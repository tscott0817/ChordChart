#ifndef CHORDCHART_CHORDS_H
#define CHORDCHART_CHORDS_H

#include "scales.h"
#include <vector>
#include <string>

class Chords {

private:

    std::vector<std::string> scale = {"C", "D", "E", "F", "G", "A", "B"};

public:

    Chords();

    void thirteenthChords(std::vector<std::string> scale);
    void seventhChords(std::vector<std::string> scales);


};
#endif //CHORDCHART_CHORDS_H
