#include "main.h"
#include "primitiveShapes/circle.h"
#include "primitiveShapes/cone.h"
#include "components/chord-chart/chordChart.h"
#include "components/cof/cof.h"
#include <ctime>
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

// Window settings
void init() {
    width = 1920;
    height = 1080;
    srand(time(0));
}

void initGL() {
    //glClearColor(0, 90/255.0, 130/255.0, 1);
}

void display() {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    ChordChart chordChart;
    chordChart.chart(960, 540, 960, 540, brickRed);

//    CoF cof;
//    cof.cof();

    glFlush();
}

void kbd(unsigned char key, int x, int y) {

    switch(key) {
        // When space key is pressed, activate lights
        case 32: {

        }
    }
    glutPostRedisplay();
}


/**
 *  Timer Function
 */
void mainLoop(int currentTime) {

    glutPostRedisplay();
}

int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(300, 150);
    wd = glutCreateWindow("Chord Chart");

    glutDisplayFunc(display);

    initGL();

    glutKeyboardFunc(kbd);

    glutSetCursor(GLUT_CURSOR_DESTROY);

    //glutTimerFunc(0, mainLoop, 0);

    glutMainLoop();
    return 0;
}