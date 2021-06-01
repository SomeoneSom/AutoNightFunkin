add_executable(AutoNightFunkin main.cpp)
add_library(HotkeyManager hotkeymanager.cpp lib/hotkeymanager.hpp)
add_library(KeyPresser keypresser.cpp lib/keypresser.hpp)
include_directories(lib)
target_link_libraries(AutoNightFunkin HotkeyManager KeyPresser winmm.lib)
set_property(TARGET AutoNightFunkin PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")