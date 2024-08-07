// #define DOCTEST_CONFIG_IMPLEMENT
// #include <doctest/doctest.h>
#define BOOST_TEST_MODULE MyTest
#include "input-system/keys.h"
#include "utils/includes.h"
#include <GLFW/glfw3.h>
#include <boost/test/included/unit_test.hpp>

// int main(int argc, char** argv) {
//   doctest::Context context;
//   context.applyCommandLine(argc, argv);

//   int res = context.run(); // run doctest

//   // important - query flags (and --exit) rely on the user doing this
//   if (context.shouldExit()) {
//     // propagate the result of the tests
//     return res;
//   }
// }

// TEST_CASE("Testing wind::mapGlfwActionToKeyAction function") {
//   SUBCASE("Valid action codes") {
//     CHECK(wind::mapGlfwActionToKeyAction(GLFW_RELEASE) == wind::KEY_ACTIONS::RELEASED);
//     CHECK(wind::mapGlfwActionToKeyAction(GLFW_PRESS) == wind::KEY_ACTIONS::PRESSED);
//     CHECK(wind::mapGlfwActionToKeyAction(GLFW_REPEAT) == wind::KEY_ACTIONS::HELD);
//     CHECK(wind::mapGlfwActionToKeyAction(GLFW_KEY_UNKNOWN) == wind::KEY_ACTIONS::RELEASED);
//   }

//   SUBCASE("Invalid action codes") {
//     CHECK(wind::mapGlfwActionToKeyAction(-1) == wind::KEY_ACTIONS::RELEASED);
//     CHECK(wind::mapGlfwActionToKeyAction(100) == wind::KEY_ACTIONS::RELEASED);
//   }
// }

BOOST_AUTO_TEST_CASE(test_mapGlfwActionToKeyAction_valid) {
  using namespace wind;
  BOOST_CHECK(mapGlfwActionToKeyAction(GLFW_RELEASE) == KEY_ACTIONS::RELEASED);
  BOOST_CHECK(mapGlfwActionToKeyAction(GLFW_PRESS) == KEY_ACTIONS::PRESSED);
  BOOST_CHECK(mapGlfwActionToKeyAction(GLFW_REPEAT) == KEY_ACTIONS::HELD);
  BOOST_CHECK(mapGlfwActionToKeyAction(GLFW_KEY_UNKNOWN) == KEY_ACTIONS::RELEASED);
}

BOOST_AUTO_TEST_CASE(test_mapGlfwActionToKeyAction_invalid) {
  using namespace wind;
  BOOST_CHECK(mapGlfwActionToKeyAction(-1) == KEY_ACTIONS::RELEASED);
  BOOST_CHECK(mapGlfwActionToKeyAction(100) == KEY_ACTIONS::RELEASED);
}

// TEST_CASE("Testing mapGlfwMouseCodeToKey function") {
//   SUBCASE("Valid mouse button codes with actions") {
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1, GLFW_PRESS) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_1, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1, GLFW_RELEASE) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_1, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_2, GLFW_PRESS) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_2, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_3, GLFW_REPEAT) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_3, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_4, GLFW_PRESS) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_4, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_5, GLFW_RELEASE) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_5, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_6, GLFW_PRESS) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_6, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_7, GLFW_RELEASE) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_7, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_8, GLFW_REPEAT) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_8, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//   }

//   SUBCASE("Invalid mouse button codes with actions") {
//     CHECK(wind::mapGlfwMouseCodeToKey(-1, GLFW_PRESS) == wind::Key{wind::KEYCODES::KEY_UNKNOWN, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwMouseCodeToKey(100, GLFW_RELEASE) == wind::Key{wind::KEYCODES::KEY_UNKNOWN, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1 + 1000, GLFW_REPEAT) == wind::Key{wind::KEYCODES::KEY_UNKNOWN, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//   }

//   SUBCASE("Valid mouse button codes with invalid actions") {
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1, -1) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_1, wind::mapGlfwActionToKeyAction(-1)});
//     CHECK(wind::mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_2, 100) == wind::Key{wind::KEYCODES::MOUSE_BUTTON_2, wind::mapGlfwActionToKeyAction(100)});
//   }
// }

BOOST_AUTO_TEST_CASE(test_mapGlfwMouseCodeToKey_valid) {
  using namespace wind;
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1, GLFW_PRESS) == (Key{KEYCODES::MOUSE_BUTTON_1, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1, GLFW_RELEASE) == (Key{KEYCODES::MOUSE_BUTTON_1, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_2, GLFW_PRESS) == (Key{KEYCODES::MOUSE_BUTTON_2, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_3, GLFW_REPEAT) == (Key{KEYCODES::MOUSE_BUTTON_3, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_4, GLFW_PRESS) == (Key{KEYCODES::MOUSE_BUTTON_4, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_5, GLFW_RELEASE) == (Key{KEYCODES::MOUSE_BUTTON_5, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_6, GLFW_PRESS) == (Key{KEYCODES::MOUSE_BUTTON_6, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_7, GLFW_RELEASE) == (Key{KEYCODES::MOUSE_BUTTON_7, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_8, GLFW_REPEAT) == (Key{KEYCODES::MOUSE_BUTTON_8, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
}

BOOST_AUTO_TEST_CASE(test_mapGlfwMouseCodeToKey_invalid) {
  using namespace wind;
  BOOST_CHECK(mapGlfwMouseCodeToKey(-1, GLFW_PRESS) == (Key{KEYCODES::KEY_UNKNOWN, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(100, GLFW_RELEASE) == (Key{KEYCODES::KEY_UNKNOWN, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1 + 1000, GLFW_REPEAT) == (Key{KEYCODES::KEY_UNKNOWN, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
}

BOOST_AUTO_TEST_CASE(test_mapGlfwMouseCodeToKey_valid_invalid_actions) {
  using namespace wind;
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_1, -1) == (Key{KEYCODES::MOUSE_BUTTON_1, mapGlfwActionToKeyAction(-1)}));
  BOOST_CHECK(mapGlfwMouseCodeToKey(GLFW_MOUSE_BUTTON_2, 100) == (Key{KEYCODES::MOUSE_BUTTON_2, mapGlfwActionToKeyAction(100)}));
}

// TEST_CASE("Testing mapGlfwJoystickCodeToKey function") {
//   SUBCASE("Valid joystick codes with actions") {
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_1, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1, GLFW_RELEASE) == wind::Key{wind::KEYCODES::JOYSTICK_1, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_2, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_2, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_3, GLFW_REPEAT) == wind::Key{wind::KEYCODES::JOYSTICK_3, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_4, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_4, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_5, GLFW_RELEASE) == wind::Key{wind::KEYCODES::JOYSTICK_5, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_6, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_6, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_7, GLFW_RELEASE) == wind::Key{wind::KEYCODES::JOYSTICK_7, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_8, GLFW_REPEAT) == wind::Key{wind::KEYCODES::JOYSTICK_8, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_9, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_9, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_10, GLFW_RELEASE) == wind::Key{wind::KEYCODES::JOYSTICK_10, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_11, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_11, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_12, GLFW_RELEASE) == wind::Key{wind::KEYCODES::JOYSTICK_12, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_13, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_13, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_14, GLFW_REPEAT) == wind::Key{wind::KEYCODES::JOYSTICK_14, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_15, GLFW_PRESS) == wind::Key{wind::KEYCODES::JOYSTICK_15, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_16, GLFW_RELEASE) == wind::Key{wind::KEYCODES::JOYSTICK_16, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//   }

//   SUBCASE("Invalid joystick codes with actions") {
//     CHECK(wind::mapGlfwJoystickCodeToKey(-1, GLFW_PRESS) == wind::Key{wind::KEYCODES::KEY_UNKNOWN, wind::mapGlfwActionToKeyAction(GLFW_PRESS)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(100, GLFW_RELEASE) == wind::Key{wind::KEYCODES::KEY_UNKNOWN, wind::mapGlfwActionToKeyAction(GLFW_RELEASE)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1 + 1000, GLFW_REPEAT) == wind::Key{wind::KEYCODES::KEY_UNKNOWN, wind::mapGlfwActionToKeyAction(GLFW_REPEAT)});
//   }

//   SUBCASE("Valid joystick codes with invalid actions") {
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1, -1) == wind::Key{wind::KEYCODES::JOYSTICK_1, wind::mapGlfwActionToKeyAction(-1)});
//     CHECK(wind::mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_2, 100) == wind::Key{wind::KEYCODES::JOYSTICK_2, wind::mapGlfwActionToKeyAction(100)});
//   }
// }

BOOST_AUTO_TEST_CASE(test_mapGlfwJoystickCodeToKey_valid) {
  using namespace wind;
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_1, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1, GLFW_RELEASE) == (Key{KEYCODES::JOYSTICK_1, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_2, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_2, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_3, GLFW_REPEAT) == (Key{KEYCODES::JOYSTICK_3, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_4, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_4, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_5, GLFW_RELEASE) == (Key{KEYCODES::JOYSTICK_5, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_6, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_6, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_7, GLFW_RELEASE) == (Key{KEYCODES::JOYSTICK_7, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_8, GLFW_REPEAT) == (Key{KEYCODES::JOYSTICK_8, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_9, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_9, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_10, GLFW_RELEASE) == (Key{KEYCODES::JOYSTICK_10, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_11, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_11, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_12, GLFW_RELEASE) == (Key{KEYCODES::JOYSTICK_12, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_13, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_13, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_14, GLFW_REPEAT) == (Key{KEYCODES::JOYSTICK_14, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_15, GLFW_PRESS) == (Key{KEYCODES::JOYSTICK_15, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_16, GLFW_RELEASE) == (Key{KEYCODES::JOYSTICK_16, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
}

BOOST_AUTO_TEST_CASE(test_mapGlfwJoystickCodeToKey_invalid) {
  using namespace wind;
  BOOST_CHECK(mapGlfwJoystickCodeToKey(-1, GLFW_PRESS) == (Key{KEYCODES::KEY_UNKNOWN, mapGlfwActionToKeyAction(GLFW_PRESS)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(100, GLFW_RELEASE) == (Key{KEYCODES::KEY_UNKNOWN, mapGlfwActionToKeyAction(GLFW_RELEASE)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1 + 1000, GLFW_REPEAT) == (Key{KEYCODES::KEY_UNKNOWN, mapGlfwActionToKeyAction(GLFW_REPEAT)}));
}

BOOST_AUTO_TEST_CASE(test_mapGlfwJoystickCodeToKey_valid_invalid_actions) {
  using namespace wind;
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_1, -1) == (Key{KEYCODES::JOYSTICK_1, mapGlfwActionToKeyAction(-1)}));
  BOOST_CHECK(mapGlfwJoystickCodeToKey(GLFW_JOYSTICK_2, 100) == (Key{KEYCODES::JOYSTICK_2, mapGlfwActionToKeyAction(100)}));
}
