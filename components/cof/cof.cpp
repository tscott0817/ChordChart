#include "cof.h"
#include "../chord-chart/chordChart.h"

CoF::CoF() {

}

void CoF::cof() {


    Circle circle;
    circle.setCenter(640, 360);
    circle.setRadius(300);
    circle.setColor(1,0,0,1);
    circle.draw();

    // ChordChart logic basically

    Cone coneTwo;
    coneTwo.setCenter(640, 360);
    coneTwo.setRadius(290);
    coneTwo.setColor(0,0,1,1);
    coneTwo.drawAngled(0, .16);

    Cone coneThree;
    coneThree.setCenter(640, 360);
    coneThree.setRadius(290);
    coneThree.setColor(0,1,0,1);
    coneThree.drawAngled(0.48, .32);

    Cone coneFour;
    coneFour.setCenter(640, 360);
    coneFour.setRadius(290);
    coneFour.setColor(purple);
    coneFour.drawAngled(.96, .48);

    Cone coneFive;
    coneFive.setCenter(640, 360);
    coneFive.setRadius(290);
    coneFive.setColor(lightWood);
    coneFive.drawAngled(1.44, .64);


    // Loops entire circle with cones
//    double start = 0;
//    double end = .16;
//    for (int i = 0; i < 12; i++) {
//        Cone coneFive;
//        coneFive.setCenter(640, 360);
//        coneFive.setRadius(290);
//        coneFive.setColor(lightWood);
//        coneFive.drawAngled(start, end);
//        start += .48;
//        end += .16;
//    }

}

