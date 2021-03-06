#ifndef CHORDCHART_CHORDCHART_H
#define CHORDCHART_CHORDCHART_H

#include "../primitiveShapes/shape.h"
#include "../primitiveShapes/rect.h"
#include "../primitiveShapes/circle.h"
#include <vector>

const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 80/255.0, 185/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0, .25);
const color grey(.6,.6,.6);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);
const color lightWood (171/255.0, 117/255.0, 57/255.0);
const color darkYellow(90/255.0, 100/255.0, 110/255.0);


// TODO: Want this class to inherit from base grid system rather than implement it in .cpp
class ChordChart {

private:

    int gridWidth;
    int gridHeight;

    // 2D vector test
    std::vector<std::vector<Rect>> cells;
    std::vector<std::vector<Rect>> curCell;

    Rect container;

    // Offset for cells
    double cellWidthPos;
    double cellHeightPos;
    double translateX;
    double translateY;
    double scalarW;
    double scalarH;
    double scalarWS; // Width spacing between each cell
    double scalarHS; // Height spacing between each cell

    double column;
    double row;

    // Text for cells
    std::string label;

public:

    ChordChart();

    void chart(double x, double y, double width, double height);
    bool checkOverlap(int x, int y);
    void hoverColor();
    void hoverCompress();
    void releaseAll();
    void releaseColor();
    void releaseCompress();
    void draw();

};
#endif //CHORDCHART_CHORDCHART_H
