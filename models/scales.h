#ifndef CHORDCHART_SCALES_H
#define CHORDCHART_SCALES_H

#include "vector"
#include "string"

class Scales {

private:


    std::vector<std::string> notes = {"A", "A#/Bb", "B", "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab"};
    std::vector<std::string> scale;

public:

    Scales();

    std::vector<std::string> buildScale(char key);
    void diatonic();
    char getKey(char key); // Helper function for buildScale()




};
#endif //CHORDCHART_SCALES_H
