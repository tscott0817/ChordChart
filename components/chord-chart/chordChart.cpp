#include "chordChart.h"
#include <memory>
#include <vector>

ChordChart::ChordChart() {

}

void ChordChart::chart(double x, double y, double width, double height, color color) {

    // Outer container
    Rect container;
    container.setCenter(x, y);
    container.setSize(width, height);
    container.setColor(brickRed);
    container.draw();

    // How many columns/rows
    gridWidth = 8;
    gridHeight = 7;

    // Offset for cells
    double cellWidthPos = 0;
    double cellHeightPos = 0;

    // To resize
    double translateX = x/2.5;
    double translateY = y/2.55;
    double scalarW = width/9.6;
    double scalarH = height/9;
    double scalarWS = width/8.7; // Width spacing between each cell
    double scalarHS = height/7.7; // Height spacing between each cell

    // Rows
    for (int i = 0; i < 7; i++) {

        Rect newCell;
        std::vector<Rect> temp;

        // Columns
        for (int j = 0; j < 8; j++) {

            newCell.setColor(darkBlue);
            newCell.setSize(scalarW, scalarH);
            newCell.setCenter((x + cellWidthPos) - translateX, (y + cellHeightPos) - translateY);
            temp.push_back(newCell);
            cellWidthPos += scalarWS;
        }

        cells.push_back(temp);
        cellWidthPos = 0;
        cellHeightPos += scalarHS;
    }

    // Draw contents from vector
    int it = 0;
    for (const std::vector<Rect> &vec : cells) {

        for (Rect rect: vec) {
            rect.draw();
            printf("%d\n", it);
            it += 1;
        }
    }
}



