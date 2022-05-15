#ifndef CHORDCHART_SCALES_H
#define CHORDCHART_SCALES_H

#include "vector"
#include "string"

class Scales {

private:


    std::vector<std::string> notes = {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};

public:

    Scales();

    void diatonic();
    void buildScale(char key, std::string mode);




};
#endif //CHORDCHART_SCALES_H
