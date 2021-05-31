add_executable(AutoNightFunkin Main.cpp)
set_property(TARGET AutoNightFunkin PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")