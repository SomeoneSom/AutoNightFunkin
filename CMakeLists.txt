cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
project(AutoNightFunkin 
    LANGUAGES C CXX 
    VERSION 1.0.0)
add_subdirectory(src)
install(TARGETS AutoNightFunkin RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/export)
install(TARGETS Calibrator RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/export)
# testing
enable_testing()
add_subdirectory(tests)
add_test(NAME KeyPresserPressTest COMMAND  $<TARGET_FILE:KeyPresserPressTest>)
add_test(NAME KeyPresserHoldTest COMMAND  $<TARGET_FILE:KeyPresserHoldTest>)
add_test(NAME HotkeyManagerTest COMMAND  $<TARGET_FILE:HotkeyManagerTest>)
add_test(NAME SongStuffTest COMMAND  $<TARGET_FILE:SongStuffTest>)
add_test(NAME TheActualBotConstructorTest COMMAND $<TARGET_FILE:TheActualBotConstructorTest>)