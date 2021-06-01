add_executable(AutoNightFunkin main.cpp)
add_library(HotkeyManager hotkeymanager.cpp lib/hotkeymanager.hpp)
add_library(KeyPresser keypresser.cpp lib/keypresser.hpp)
add_library(SongStuff songstuff.cpp lib/songstuff.hpp)
include_directories(lib)
target_link_libraries(AutoNightFunkin HotkeyManager KeyPresser SongStuff winmm.lib)
set_property(TARGET AutoNightFunkin PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")