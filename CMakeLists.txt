cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(AutoNightFunkin 
    LANGUAGES C CXX 
    VERSION 0.0.1)
add_subdirectory(src)
install(TARGETS AutoNightFunkin RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/export)
# testing
enable_testing()
add_subdirectory(tests)
add_test(NAME HotkeyManagerTest COMMAND  $<TARGET_FILE:HotkeyManagerTest>)
add_test(NAME KeyPresserPressTest COMMAND  $<TARGET_FILE:KeyPresserPressTest>)
add_test(NAME KeyPresserHoldTest COMMAND  $<TARGET_FILE:KeyPresserHoldTest>)