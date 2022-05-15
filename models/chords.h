#ifndef CHORDCHART_CHORDS_H
#define CHORDCHART_CHORDS_H

#include "scales.h"
#include <vector>
#include <string>

class Chords {

private:

    std::vector<std::string> chords;

public:

    Chords();

    void thirteenthChords(std::vector<std::string> scale);
    std::vector<std::string> seventhChords(std::vector<std::string> scales);


};
#endif //CHORDCHART_CHORDS_H
