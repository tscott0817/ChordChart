#include "chordChart.h"
#include <memory>
#include <vector>

bool canHover = true;
ChordChart::ChordChart() {

}

void ChordChart::chart(double x, double y, double width, double height, color color) {

    // How many columns/rows
    gridWidth = 8;
    gridHeight = 7;

    // Outer container
    Rect container;
    container.setCenter(x, y);
    container.setSize(width, height);
    container.setColor(grey);
    container.draw();

    // Offset for cells
    double cellWidthPos = 0;
    double cellHeightPos = 0;

    // To resize
    double translateX = width/2.5;
    double translateY = height/2.55;
    double scalarW = width/9.6;
    double scalarH = height/9;
    double scalarWS = width/8.7; // Width spacing between each cell
    double scalarHS = height/7.7; // Height spacing between each cell

    // 8x7 grid
    // Columns
    if (cells.size() < gridHeight) {
        for (int i = 0; i < gridHeight; i++) {

            Rect newCell;
            std::vector<Rect> temp;

            // Rows
            for (int j = 0; j < gridWidth; j++) {

                newCell.setColor(black);
                newCell.setSize(scalarW, scalarH);
                newCell.setCenter((x + cellWidthPos) - translateX, (y + cellHeightPos) - translateY);
                temp.push_back(newCell);
                cellWidthPos += scalarWS;
            }

            cells.push_back(temp);
            cellWidthPos = 0; // Reset for next row
            cellHeightPos += scalarHS;
        }
    }
}

bool ChordChart::isOverlappingOne(int x, int y) const {

    if (y > cells[0][0].getTopY() && y < cells[0][0].getBottomY() && x > cells[0][0].getLeftX() && x < cells[0][0].getRightX()){
        return true;
    }
    else {
        return false;
    }
}

void ChordChart::hover() {
    cells[0][0].setColor(purple);
}

void ChordChart::release() {
    cells[0][0].setColor(black);
}

void ChordChart::draw() {
    for (const std::vector<Rect> &vec : cells) {
        for (Rect rect: vec) {
            rect.draw();
        }
    }
}



