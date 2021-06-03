add_executable(TheActualBotConstructorTest constructortest.cpp)
include_directories(../../src/lib)
target_link_libraries(TheActualBotConstructorTest TheActualBot KeyPresser SongStuff)