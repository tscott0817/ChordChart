#include "scales.h"
#include <iostream>

Scales::Scales() {

}


// W-W-H-W-W-W-H
void Scales::buildScale(char key, std::string mode) {

    for (int i = 0; i < notes.size(); i++) {


        for (int j = i; j < (notes.size() * 2) + i; j+=2) {
            std::cout << notes[j % notes.size()];
        }
        std::cout << "\n";
    }

}

