#include "../../src/lib/keypresser.hpp"
#include "../../src/lib/songstuff.hpp"
#include "../../src/lib/theactualbot.hpp"
#include <vector>
#include <filesystem>
std::vector<std::vector<SongStuff::Note>> expected = {
    {
        {0, 0, 0}
    },
    {
        {1, 1000, 1000}
    },
    {
        {2, 2000, 0}
    },
    {
        {3, 3000, 1000}
    }
};
int main() {
    TheActualBot::MiniBotsManager manager({0x44, 0x46, 0x4a, 0x4b}, SongStuff::loadSongFromJSON(std::filesystem::current_path().string() + "\\tests\\theactualbot\\test.json"));
    for (int i = 0; i < manager.miniBots.size(); i++) {
        if (manager.miniBots.at(i)->notesVector.at(0).key != expected.at(i).at(0).key || manager.miniBots.at(i)->notesVector.at(0).time != expected.at(i).at(0).time || manager.miniBots.at(i)->notesVector.at(0).holdTime != expected.at(i).at(0).holdTime) {
            return 1;
        }
    }
    return 0;
}