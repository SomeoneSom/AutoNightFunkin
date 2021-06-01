/* songstuff:
deals with decoding fnf charts (json files) into a vector of Notes (struct)
members ending in '__' should be seen as "private"*/
#include <vector>
#include <iostream>
#include <string>
#include "json.hpp"
#ifndef SONGSTUFF_HPP
#define SONGSTUFF_HPP
namespace SongStuff {
    typedef struct Note {
        int key;
        int time;
        int holdTime;
    } Note;
    std::vector<Note> loadSongFromJSON(std::string filename);
}
#endif