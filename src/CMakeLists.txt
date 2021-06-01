add_executable(AutoNightFunkin main.cpp)
add_library(HotkeyManager hotkeymanager.cpp lib/hotkeymanager.hpp)
include_directories(lib)
target_link_libraries(AutoNightFunkin HotkeyManager)
set_property(TARGET AutoNightFunkin PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")