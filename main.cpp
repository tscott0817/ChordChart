#include "main.h"
#include "components/primitiveShapes/circle.h"
#include "components/primitiveShapes/cone.h"
#include "components/chord-chart/chordChart.h"
#include "components/cof/cof.h"
#include "models/scales.h"
#include "models/chords.h"
#include <iostream>
#include <ctime>
#include <vector>

#include "models/scales.h"
using namespace std;

GLdouble width, height;
int wd;

const color baseGrey(64/255.0,64/255.0,64/255.0);
const color lightGreen(0, .8, 0);
const color lightYellow(.85, .85, 0);
const color lightRed(1, 0, 0);
const color green(0, .5, 0);
const color yellow(.45, .45, 0);
const color red(.5, 0, 0);

ChordChart chordChart;
bool canDraw = false;

void init() {

    width = 1600;
    height = 900;
    srand(time(0));
}

void initGL() {
    glClearColor(0, 90/255.0, 130/255.0, 1);
}

void initTests() {

    Scales scales;
    std::vector<std::string> scale = scales.buildScale('C');

    std::cout << "Notes from scale: " << std::endl;
    for (int i = 0; i < scale.size(); i++) {
        std::cout << scale[i] << "-";
    }

    Chords chords;
//    chords.thirteenthChords(scale);
    std::cout << "\n";
    std::vector<std::string> chord = chords.seventhChords(scale);
    std::cout << "\n";

    std::cout << "Chords from scale: " << std::endl;
    for (int i = 0; i < chord.size(); i++) {
        std::cout << chord[i] << std::endl;
    }
}

void display() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

//    ChordChart chordChart;
        chordChart.chart(800, 450, 960, 540);
        chordChart.draw();
//    CoF cof;
//    cof.cof();

    glFlush();

}

void cursor(int x, int y) {
    if (chordChart.checkOverlap(x, y)) {
        chordChart.hoverColor();
        chordChart.hoverCompress();
    }

    else {
        chordChart.releaseAll();
        //chordChart.releaseColor();
    }

    glutPostRedisplay();
}

void kbd(unsigned char key, int x, int y) {

    switch(key) {

        case 32: {

        }
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(300, 150);
    wd = glutCreateWindow("Chord Chart");

    initGL();
    initTests();

    glutDisplayFunc(display);

    glutKeyboardFunc(kbd);
    glutPassiveMotionFunc(cursor);

    glutSetCursor(GLUT_CURSOR_DESTROY);

    glutMainLoop();
    return 0;
}