set(CPACK_BUNDLE_NAME "Dreich")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Dreich Inc")
set(CPACK_PACKAGE_FILE_NAME "dreich")

set_target_properties(game PROPERTIES INSTALL_RPATH "@executable_path")

install (TARGETS game DESTINATION .)

install (DIRECTORY $ENV{ULTRALIGHT_PATH}/bin/ DESTINATION .)

install (DIRECTORY game/res DESTINATION .)

set(CPACK_GENERATOR "ZIP")
set(CPACK_BUNDLE_STARTUP_COMMAND ${CMAKE_BINARY_DIR}/game/game)

include(CPack)
