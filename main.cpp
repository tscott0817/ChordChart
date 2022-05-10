#include "main.h"
#include "primitiveShapes/circle.h"
#include "primitiveShapes/cone.h"
#include "components/chord-chart/chordChart.h"
#include "components/cof/cof.h"
#include <ctime>
#include <vector>
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

// Window settings
void init() {
    width = 1600;
    height = 900;
    srand(time(0));
}

void initGL() {
    glClearColor(0, 90/255.0, 130/255.0, 1);
}

void display() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

//    ChordChart chordChart;
    chordChart.chart(800, 450, 960, 540, brickRed);
    chordChart.draw();
//    CoF cof;
//    cof.cof();

    glFlush();
}

void cursor(int x, int y) {
    if (chordChart.isOverlappingOne(x, y)) {
        chordChart.hover();
    }

    else {
        chordChart.release();
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

    glutDisplayFunc(display);

    glutKeyboardFunc(kbd);
    glutPassiveMotionFunc(cursor);

    glutSetCursor(GLUT_CURSOR_DESTROY);

    glutMainLoop();
    return 0;
}