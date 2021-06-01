add_executable(HotkeyTester Test.cpp)
include_directories(../../src/lib)
target_link_libraries(HotkeyTester HotkeyManager)