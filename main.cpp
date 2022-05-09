#include "main.h"
#include "primitiveShapes/circle.h"
#include "primitiveShapes/cone.h"
#include "components/chord-chart/chordChart.h"
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

void init() {
    width = 1280;
    height = 720;
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
    chordChart.chart(320, 50, 640, 360, darkBlue);

//    Circle circle;
//    circle.setCenter(640, 360);
//    circle.setRadius(300);
//    circle.setColor(1,0,0,1);
//    circle.draw();
//
//    // ChordChart logic basically
//
//    Cone coneTwo;
//    coneTwo.setCenter(640, 360);
//    coneTwo.setRadius(290);
//    coneTwo.setColor(0,0,1,1);
//    coneTwo.drawAngled(0, .16);
//
//    Cone coneThree;
//    coneThree.setCenter(640, 360);
//    coneThree.setRadius(290);
//    coneThree.setColor(0,1,0,1);
//    coneThree.drawAngled(0.56, .36);

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
    wd = glutCreateWindow("Finite State Machines Example: Traffic Lights");

    glutDisplayFunc(display);

    initGL();

    glutKeyboardFunc(kbd);

    glutSetCursor(GLUT_CURSOR_DESTROY);

    //glutTimerFunc(0, mainLoop, 0);

    glutMainLoop();
    return 0;
}