#pragma once
#include "utils/includes.h"
#include <unordered_set>

namespace wind {

enum class KEY_ACTIONS {
  UNKNOWN,
  PRESSED,
  HELD,
  RELEASED
};

enum class KEYCODES {
  KEY_UNKNOWN = 0,
  //
  KEYBOARD_START,
  //
  KEY_SPACE,
  KEY_APOSTROPHE,
  KEY_COMMA,
  KEY_MINUS,
  KEY_PERIOD,
  KEY_SLASH,
  KEY_0,
  KEY_1,
  KEY_2,
  KEY_3,
  KEY_4,
  KEY_5,
  KEY_6,
  KEY_7,
  KEY_8,
  KEY_9,
  KEY_SEMICOLON,
  KEY_EQUAL,
  KEY_A,
  KEY_B,
  KEY_C,
  KEY_D,
  KEY_E,
  KEY_F,
  KEY_G,
  KEY_H,
  KEY_I,
  KEY_J,
  KEY_K,
  KEY_L,
  KEY_M,
  KEY_N,
  KEY_O,
  KEY_P,
  KEY_Q,
  KEY_R,
  KEY_S,
  KEY_T,
  KEY_U,
  KEY_V,
  KEY_W,
  KEY_X,
  KEY_Y,
  KEY_Z,
  KEY_LEFT_BRACKET,
  KEY_BACKSLASH,
  KEY_RIGHT_BRACKET,
  KEY_GRAVE_ACCENT,
  KEY_WORLD_1,
  KEY_WORLD_2,
  KEY_ESCAPE,
  KEY_ENTER,
  KEY_TAB,
  KEY_BACKSPACE,
  KEY_INSERT,
  KEY_DELETE,
  KEY_RIGHT,
  KEY_LEFT,
  KEY_DOWN,
  KEY_UP,
  KEY_PAGE_UP,
  KEY_PAGE_DOWN,
  KEY_HOME,
  KEY_END,
  KEY_CAPS_LOCK,
  KEY_SCROLL_LOCK,
  KEY_NUM_LOCK,
  KEY_PRINT_SCREEN,
  KEY_PAUSE,
  KEY_F1,
  KEY_F2,
  KEY_F3,
  KEY_F4,
  KEY_F5,
  KEY_F6,
  KEY_F7,
  KEY_F8,
  KEY_F9,
  KEY_F10,
  KEY_F11,
  KEY_F12,
  KEY_F13,
  KEY_F14,
  KEY_F15,
  KEY_F16,
  KEY_F17,
  KEY_F18,
  KEY_F19,
  KEY_F20,
  KEY_F21,
  KEY_F22,
  KEY_F23,
  KEY_F24,
  KEY_F25,
  KEY_KP_0,
  KEY_KP_1,
  KEY_KP_2,
  KEY_KP_3,
  KEY_KP_4,
  KEY_KP_5,
  KEY_KP_6,
  KEY_KP_7,
  KEY_KP_8,
  KEY_KP_9,
  KEY_KP_DECIMAL,
  KEY_KP_DIVIDE,
  KEY_KP_MULTIPLY,
  KEY_KP_SUBTRACT,
  KEY_KP_ADD,
  KEY_KP_ENTER,
  KEY_KP_EQUAL,
  KEY_LEFT_SHIFT,
  KEY_LEFT_CONTROL,
  KEY_LEFT_ALT,
  KEY_LEFT_SUPER,
  KEY_RIGHT_SHIFT,
  KEY_RIGHT_CONTROL,
  KEY_RIGHT_ALT,
  KEY_RIGHT_SUPER,
  KEY_MENU,
  KEY_LAST = KEY_MENU,
  //
  KEYBOARD_END,
  //
  //
  MOUSE_START,
  //
  MOUSE_BUTTON_1,
  MOUSE_BUTTON_2,
  MOUSE_BUTTON_3,
  MOUSE_BUTTON_4,
  MOUSE_BUTTON_5,
  MOUSE_BUTTON_6,
  MOUSE_BUTTON_7,
  MOUSE_BUTTON_8,
  MOUSE_BUTTON_LAST = MOUSE_BUTTON_8,
  MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1,
  MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2,
  MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3,
  //
  MOUSE_END = MOUSE_BUTTON_8 + 1,
  //
  //
  JOYSTICK_START,
  //
  JOYSTICK_1,
  JOYSTICK_2,
  JOYSTICK_3,
  JOYSTICK_4,
  JOYSTICK_5,
  JOYSTICK_6,
  JOYSTICK_7,
  JOYSTICK_8,
  JOYSTICK_9,
  JOYSTICK_10,
  JOYSTICK_11,
  JOYSTICK_12,
  JOYSTICK_13,
  JOYSTICK_14,
  JOYSTICK_15,
  JOYSTICK_16,
  JOYSTICK_LAST = JOYSTICK_16,
  //
  JOYSTICK_END,
  //
  //
  GAMEPAD_START,
  //
  GAMEPAD_BUTTON_A,
  GAMEPAD_BUTTON_B,
  GAMEPAD_BUTTON_X,
  GAMEPAD_BUTTON_Y,
  GAMEPAD_BUTTON_LEFT_BUMPER,
  GAMEPAD_BUTTON_RIGHT_BUMPER,
  GAMEPAD_BUTTON_BACK,
  GAMEPAD_BUTTON_START,
  GAMEPAD_BUTTON_GUIDE,
  GAMEPAD_BUTTON_LEFT_THUMB,
  GAMEPAD_BUTTON_RIGHT_THUMB,
  GAMEPAD_BUTTON_DPAD_UP,
  GAMEPAD_BUTTON_DPAD_RIGHT,
  GAMEPAD_BUTTON_DPAD_DOWN,
  GAMEPAD_BUTTON_DPAD_LEFT,
  GAMEPAD_BUTTON_LAST = GAMEPAD_BUTTON_DPAD_LEFT,
  GAMEPAD_BUTTON_CROSS = GAMEPAD_BUTTON_A,
  GAMEPAD_BUTTON_CIRCLE = GAMEPAD_BUTTON_B,
  GAMEPAD_BUTTON_SQUARE = GAMEPAD_BUTTON_X,
  GAMEPAD_BUTTON_TRIANGLE = GAMEPAD_BUTTON_Y,
  //
  GAMEPAD_END = GAMEPAD_BUTTON_DPAD_LEFT + 1,
  //
  //
  GAMEPAD_AXIS_START,
  //
  GAMEPAD_AXIS_LEFT_X,
  GAMEPAD_AXIS_LEFT_Y,
  GAMEPAD_AXIS_RIGHT_X,
  GAMEPAD_AXIS_RIGHT_Y,
  GAMEPAD_AXIS_LEFT_TRIGGER,
  GAMEPAD_AXIS_RIGHT_TRIGGER,
  GAMEPAD_AXIS_LAST = GAMEPAD_AXIS_RIGHT_TRIGGER,
  //
  GAMEPAD_AXIS_END,
  //
  MOUSE_MOVE = 996,
  MOUSE_SCROLL_DOWN = 997,
  MOUSE_SCROLL_UP = 998,
  MOUSE_SCROLL = 999,
  //
  ALL_KEYBOARD_KEYS = 1000,
  ALL_MOUSE_KEYS = 1001,
  ALL_MOUSE_EVENTS = 1002,
  ALL_EVENTS = 1003,
  ALL_KEYBOARD_CHARS = 1004,
};

struct Key {
  KEYCODES keycode;
  KEY_ACTIONS action;

  bool operator==(const Key& key) const {
    return key.keycode == keycode && action == key.action;
  }
};

struct KeyHash {
  std::size_t operator()(const Key& key) const {
    return std::hash<KEYCODES>()(key.keycode) ^ (std::hash<KEY_ACTIONS>()(key.action) << 1);
  }
};

using Keys = std::unordered_set<Key, KeyHash>;

KEY_ACTIONS mapStringToKeyAction(std::string action);
KEYCODES mapStringToKeycode(std::string action);

Key mapGlfwMouseCodeToKey(int glfwKey, int action);
Key mapGlfwJoystickCodeToKey(int glfwKey, int action);
Key mapGlfwGamepadButtonCodeToKey(int glfwKey);
Key mapGlfwGamepadAxisCodeToKey(int glfwKey);
Key mapGlfwKeyboardCodeToKey(int glfwKey, int action);

} // namespace wind