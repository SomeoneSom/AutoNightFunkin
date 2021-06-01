/* songstuff:
deals with decoding fnf charts (json files) into a vector of Notes (struct)
members ending in '__' should be seen as "private"*/
#include "lib/songstuff.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "lib/json.hpp"
std::vector<SongStuff::Note> SongStuff::loadSongFromJSON(std::string filename) {
    int rangeMin;
    int rangeMax;
    std::vector<SongStuff::Note> noteVector;
    std::ifstream f(filename);
    nlohmann::json n = nlohmann::json::parse(f);
    std::vector<nlohmann::json> jsonNotes = n["song"]["notes"];
    for (int i = 0; i < jsonNotes.size(); i++) {
        if (jsonNotes.at(i)["mustHitSection"]) {
            rangeMin = 0;
            rangeMax = 3;
        } else {
            rangeMin = 4;
            rangeMax = 7;
        }
        for (int j = 0; j < jsonNotes.at(i)["sectionNotes"].size(); j++) {
            if (jsonNotes.at(i)["sectionNotes"].at(j).at(1) >= rangeMin && jsonNotes.at(i)["sectionNotes"].at(j).at(1) <= rangeMax) {
                noteVector.push_back({(jsonNotes.at(i)["sectionNotes"].at(j).at(1) % 4),
                jsonNotes.at(i)["sectionNotes"].at(j).at(0),
                jsonNotes.at(i)["sectionNotes"].at(j).at(2)});
            }
        }
    }
    return noteVector;
}