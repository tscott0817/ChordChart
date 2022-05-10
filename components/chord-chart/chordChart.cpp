#include "chordChart.h"
#include <memory>
#include <vector>

ChordChart::ChordChart() {

}

void ChordChart::chart(double x, double y, double width, double height, color color) {

    gridWidth = 8; // # Columns
    gridHeight = 7; // # Rows

    // Outer container
    Rect container;
    container.setCenter(x, y);
    container.setSize(width, height);
    container.setColor(grey);
    container.draw();

    // Offset for cells
    cellWidthPos = 0;
    cellHeightPos = 0;

    // To resize
    translateX = width/2.5;
    translateY = height/2.55;
    scalarW = width/9.6;
    scalarH = height/9;
    scalarWS = width/8.7; // Width spacing between each cell
    scalarHS = height/7.7; // Height spacing between each cell

    // 8x7 grid
    // Columns
    if (cells.size() < gridHeight) { // Does weird fade to black without this check
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
                printf("Total Row Count: %d\n", j);
            }

            cells.push_back(temp);
            cellWidthPos = 0; // Reset for next row
            cellHeightPos += scalarHS;

        }

    }
}

bool ChordChart::checkOverlap(int x, int y) const {

    for (int i = 0; i < cells.size(); i++) {

        for (int j = 0; j < cells[i].size(); j++) {

            if (y > cells[i][j].getTopY() && y < cells[i][j].getBottomY() && x > cells[i][j].getLeftX() &&
                x < cells[i][j].getRightX()) {
                return true;
            }
        }
    }

    return false;

}

void ChordChart::hoverColor() {

    for (int i = 0; i < cells.size(); i++) {

        for (int j = 0; j < cells[i].size(); j++) {
            cells[i][j].setColor(purple);
        }
    }
}

void ChordChart::release() {

    for (int i = 0; i < cells.size(); i++) {

        for (int j = 0; j < cells[i].size(); j++) {
            cells[i][j].setColor(black);
        }
    }
}

void ChordChart::draw() {
    for (const std::vector<Rect> &vec : cells) {
        for (Rect rect: vec) {
            rect.draw();
        }
    }
}



