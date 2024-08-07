#include "editor/event-manager.hpp"

namespace editor {

namespace pt = boost::property_tree;
namespace hana = boost::hana;

// template <typename Struct>
// Struct jsonToStruct(std::string& json) {
//   pt::ptree tree;
//   std::istringstream ss(json);
//   pt::read_json(ss, tree);

//   Struct result;
//   hana::for_each(hana::keys(result), [&](auto key) {
//     auto value = tree.get<decltype(hana::at_key(result, key))>(key);
//     hana::at_key(result, key) = value;
//   });

//   return result;
// }

// OR

// template <typename Struct>
// Struct jsonToStruct(const std::string& json) {
// pt::ptree tree;
// std::istringstream ss(json);
// pt::read_json(ss, tree);

// Struct result;
// hana::for_each(hana::keys(result), [&](auto key) {
//   using Key = decltype(key);
//   auto keyStr = hana::to<const char*>(key);
//   using ValueType = typename std::decay<decltype(hana::at_key(result, key))>::type;

//   if (tree.find(keyStr) != tree.not_found()) {
//     hana::at_key(result, key) = tree.get<ValueType>(keyStr);
//   } else {
//     hana::at_key(result, key) = ValueType{}; // Default value if key is not found
//   }
// });

//   return result;
// }

struct MyStruct {
  BOOST_HANA_DEFINE_STRUCT(MyStruct,
    (int, id),
    (std::string, name));
};

JSValueRef handleCppEvent(JSContextRef ctx, JSObjectRef function,
  JSObjectRef thisObject, size_t argumentCount,
  const JSValueRef arguments[], JSValueRef* exception) {

  std::string eventJson = wind::JSValueToStdString(ctx, arguments[0]);

  pt::ptree tree;
  std::istringstream ss(eventJson);
  pt::read_json(ss, tree);

  std::string name = tree.get<std::string>("name");
  std::string data = tree.get<std::string>("data");

  auto temp = new CppEvents::Methods();

  std::unordered_map<std::string, std::function<void()>> handlers = {
    {"saveProject", [&]() {
       pt::ptree tree;
       std::istringstream ss(data);
       pt::read_json(ss, tree);

       MyStruct result;
       hana::for_each(hana::keys(result), [&](auto key) {
         using Key = decltype(key);
         auto keyStr = hana::to<const char*>(key);
         using ValueType = typename std::decay<decltype(hana::at_key(result, key))>::type;

         if (tree.find(keyStr) != tree.not_found()) {
           hana::at_key(result, key) = tree.get<ValueType>(keyStr);
         } else {
           hana::at_key(result, key) = ValueType{}; // Default value if key is not found
         }
       });
       //  wind::jsonToStruct<MyStruct>(data);
       //  temp->saveProject(wind::jsonToStruct<CppEvents::SaveProject::Input>(data), ctx);
     }}};

  auto it = handlers.find(name);

  if (it != handlers.end()) {
    it->second();
  }

  // const char* str =
  //   "console.log('BIMBO')";

  // JSStringRef script = JSStringCreateWithUTF8CString(str);

  // JSEvaluateScript(ctx, script, 0, 0, 0, 0);

  // JSStringRelease(script);

  return JSValueMakeNull(ctx);
}

} // namespace editor
