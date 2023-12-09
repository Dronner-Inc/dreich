#pragma once
#include "document.h"

namespace wind {
    namespace doom {
        class XML {
        public:
            static Document* LoadFile(const char* path);
            static Document* LoadRAW(const char* raw, size_t _nbytes);
        };
    }
}