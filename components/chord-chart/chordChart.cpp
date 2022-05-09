#include "chordChart.h"
#include <memory>
#include <vector>

ChordChart::ChordChart() {

}

void ChordChart::chart(int x, int y, double width, double height, color color) {

    // Outer container
//    Rect container;
//    container.setCenter(x, y);
//    container.setSize(width, height);
//    container.setColor(color);
//    container.draw();

    // Inner cells
    //Rect cell;
    // How many columns/rows
    gridWidth = 8;
    gridHeight = 7;
    double cellWidthPos = 0;
    double cellHeightPos = 0;

    // Create new cell
    Rect newCell;
    // Fill rows
    for (int i = 0; i < 7; i++) {
        std::vector<Rect> temp;
        // Columns
        for(int j = 0; j < 8; j++) {
            newCell.setColor(darkBlue);
            newCell.setSize(90, 40);
            newCell.setCenter(x + cellWidthPos, y + cellHeightPos);
            temp.push_back(newCell);
            cellWidthPos += 100;
        }

        cells.push_back(temp);
        cellWidthPos = 0;
        cellHeightPos += 50;
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



