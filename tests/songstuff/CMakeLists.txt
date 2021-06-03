add_executable(SongStuffTest test.cpp)
include_directories(../../src/lib)
target_link_libraries(SongStuffTest SongStuff)