add_executable(HotkeyManagerTest test.cpp)
include_directories(../../src/lib)
target_link_libraries(HotkeyManagerTest HotkeyManager KeyPresser)