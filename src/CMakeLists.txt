add_executable(AutoNightFunkin main.cpp)
set_property(TARGET AutoNightFunkin PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")