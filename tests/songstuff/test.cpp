#include "../../src/lib/songstuff.hpp"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <algorithm>
int main() {
    std::vector<SongStuff::Note> target = {
        {0, 0, 0},
        {1, 1000, 1000},
        {2, 2000, 0},
        {3, 3000, 1000}
    };
    std::vector<SongStuff::Note> testNotes = SongStuff::loadSongFromJSON(std::filesystem::current_path().string() + "\\tests\\songstuff\\test.json");
    for (int i = 0; i < std::min(target.size(), testNotes.size()); i++) {
        if (target.at(i).key != testNotes.at(i).key || target.at(i).time != testNotes.at(i).time || target.at(i).holdTime != testNotes.at(i).holdTime) {
            return 1;
        }
    }
    return 0;
}