#include "scales.h"
#include <iostream>

Scales::Scales() {

}

std::vector<std::string> Scales::buildScale(char key) {

    char keyNote = getKey(key);

    int it = 0;
    for (int j = keyNote; j < notes.size() + keyNote; j+=2) { // Whole steps

        if (it == 3) { // Half steps
            j -= 1;
        }
        it += 1;
        scale.push_back(notes[j % notes.size()]);
    }

    return scale;
}

// Prints all scales, probably won't use
void Scales::diatonic() {

    for (int i = 0; i < notes.size(); i++) {

        int it = 0;
        for (int j = i; j < notes.size() + i; j+=2) {
            if (it == 3) {
                j -= 1;
            }
            it += 1;
        }
        std::cout << "\n";
    }
}

char Scales::getKey(char key) {

    int keyNote = 0;
    switch (key) {
        case 'A':
            keyNote = 0;
            break;

        // Need to figure out #/b

        case 'B':
            keyNote = 2;
            break;
        case 'C':
            keyNote = 3;
            break;
    }
    return keyNote;
}

