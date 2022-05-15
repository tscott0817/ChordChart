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

void Chords::seventhChords(std::vector<std::string> scale) {

    // i = note index position
    for (int i = 0; i < scale.size(); i++) { // Need the outer loop to keep the inner one from looping forever

        // At current note index, iterate by 2 until
        for (int j = i; j < scale.size() + i; j+=2) {
            std::cout << scale[j % scale.size()];
        }
        std::cout << "\n";
    }
}