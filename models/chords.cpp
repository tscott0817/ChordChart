#include "chords.h"
#include <iostream>

Chords::Chords() {

}

void Chords::thirteenthChords(std::vector<std::string> scale) {

    // i = note index position
    for (int i = 0; i < scale.size(); i++) {

        // At current note index, iterate by 2, double scale size and add i until i = scale.size()
        for (int j = i; j < (scale.size() * 2) + i; j+=2) {
            std::cout << scale[j % scale.size()];
        }
        std::cout << "\n";
    }
}

std::vector<std::string> Chords::seventhChords(std::vector<std::string> scale) {

    // i = note index position
    for (int i = 0; i < scale.size(); i++) { // Need the outer loop to keep the inner one from looping forever

        std::string tempString;
        for (int j = i; j < scale.size() + i; j+=2) { // TODO: Implement flat keys, this only returns natural and sharp

            if (scale[j % scale.size()].size() == 1) { // Checks size of string at specific scale index for '#' symbol
                tempString.push_back(scale[j % scale.size()][0]);
            }

            else {
                tempString.push_back(scale[j % scale.size()][0]);
                tempString.push_back(scale[j % scale.size()][1]);
            }
        }

        chords.push_back(tempString);
    }

    return chords;
}

void Chords::printChords() {
}