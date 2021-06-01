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
add_test(NAME HotkeyTest COMMAND  $<TARGET_FILE:HotkeyTester>)