#include "asset_bundler.h"
#include <openssl/md5.h>
#include <openssl/evp.h>

namespace wind {
    namespace {
        std::string md5(const std::string &str){
            EVP_MD_CTX* mdctx;           
            unsigned char* md5_digest;
            unsigned int   md5_digest_len = EVP_MD_size(EVP_md5());
           
            mdctx = EVP_MD_CTX_new();
            EVP_DigestInit_ex(mdctx, EVP_md5(), NULL);

            EVP_DigestUpdate(mdctx, str.c_str(), str.size());

            md5_digest = (unsigned char *)OPENSSL_malloc(md5_digest_len);
            EVP_DigestFinal_ex(mdctx, md5_digest, &md5_digest_len);
            EVP_MD_CTX_free(mdctx);

            std::stringstream ss;

            for(int i = 0; i < md5_digest_len; i++){
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( md5_digest[i] );
            }

            return ss.str();
        }
    }

    namespace assets {
        void Bundler::regLoader(string reg_exp, ILoader* loader) {
            try {
                m_loaders.push_back(std::make_pair(
                    std::regex(reg_exp), loader
                ));
            } catch (std::regex_error& ex) {
                log().error() << "can't create regex from '" << reg_exp << "': " << ex.what();
            }
        }

        void Bundler::assembly(
            const string&& _src, 
            const string&& _dst
        ) {
            log().info() << "Asset Bundler: assembly " << _src;

            std::ofstream output(_dst, std::ofstream::binary);
            if (!output.is_open()) {
                log().error() << "Asset Bundler: can't create destination file: " << _dst;
                return;
            }

            fs::directory_iterator it;
            try {
                it = fs::directory_iterator(_src);
            } catch (fs::filesystem_error& ex) {
                log().error() << "Asset Bundler: can't open source directory: " << ex.what();
                return;
            }

            for (const auto& entry : it) {
                ISerializable* obj = nullptr;
                auto filename = entry.path().relative_path().string();

                for (const auto& pair : m_loaders) {
                    if (!std::regex_match(filename, pair.first))
                        continue;

                    obj = pair.second->load(entry.path().c_str());
                    if (!obj) {
                        log().error() << "Asset Bundler: can't load resource: " << filename;
                        break;
                    }

                    try {
                        obj->id = filename;
                        obj->serialize(output);
                    } catch (std::exception& ex) {
                        log().error() << "Asset Bundler: can't serialize resource: " << filename << " what(): " << ex.what();
                    }

                    break;
                }

                if (!obj) {
                    log().warning() << "Asset Bundler: ignore resource: " << filename; 
                    continue;
                }

                delete obj;
            }

            output.close();
            log().info() << "Asset Bundler: assembly success";
        }

        Bundler::~Bundler() {
            for (auto pair : m_loaders)
                delete pair.second;
            m_loaders.clear();
        }
    }
}