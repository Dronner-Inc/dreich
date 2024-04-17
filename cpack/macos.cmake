install (TARGETS game DESTINATION bin)

install (DIRECTORY $ENV{DOTNET_INCLUDES}/ DESTINATION lib)
install (DIRECTORY $ENV{ULTRALIGHT_PATH}/bin/ DESTINATION lib)
set_target_properties(game PROPERTIES INSTALL_RPATH "@executable_path/../lib")

install (DIRECTORY game/res DESTINATION bin)

set(CPACK_GENERATOR "Bundle")
set(CPACK_BUNDLE_PLIST ${CMAKE_SOURCE_DIR}/Info.plist)
set(CPACK_BUNDLE_ICON ${CMAKE_CURRENT_SOURCE_DIR}/icon.icns)
set(CPACK_BUNDLE_STARTUP_COMMAND ${CMAKE_BINARY_DIR}/game/game)

set(CPACK_PACKAGE_VERSION ${deb_example_VERSION})
