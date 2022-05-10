#include "Cone.h"
#include "../main.h"

Cone::Cone() : Shape(), radius(0) {
}

Cone::Cone(double radius) : Shape() {
    setRadius(radius);
}

Cone::Cone(color fill) : Shape(fill), radius(0) {
}

Cone::Cone(point2D center) : Shape(center), radius(0) {
}

Cone::Cone(color fill, point2D center) : Shape(fill, center), radius(0) {
}

Cone::Cone(double red, double green, double blue, double alpha) : Shape(red, green, blue, alpha), radius(0) {
}

Cone::Cone(double x, double y) : Shape(x, y), radius(0) {
}

Cone::Cone(double red, double green, double blue, double alpha, double x, double y) : Shape(red, green, blue, alpha, x, y), radius(0) {
}

Cone::Cone(color fill, double x, double y) : Shape(fill, x, y), radius(0) {
}

Cone::Cone(double red, double green, double blue, double alpha, point2D center) : Shape(red, green, blue, alpha, center), radius(0) {
}

Cone::Cone(color fill, double radius) : Shape(fill) {
    setRadius(radius);
}

Cone::Cone(point2D center, double radius) : Shape(center) {
    setRadius(radius);
}

Cone::Cone(color fill, point2D center, double radius) : Shape(fill, center) {
    setRadius(radius);
}

Cone::Cone(double red, double green, double blue, double alpha, double radius) : Shape(red, green, blue, alpha) {
    setRadius(radius);
}

Cone::Cone(double x, double y, double radius) : Shape(x, y) {
    setRadius(radius);
}

Cone::Cone(double red, double green, double blue, double alpha, double x, double y, double radius) : Shape(red, green, blue, alpha, x, y) {
    setRadius(radius);
}

Cone::Cone(color fill, double x, double y, double radius) : Shape(fill, x, y) {
    setRadius(radius);
}

Cone::Cone(double red, double green, double blue, double alpha, point2D center, double radius) : Shape(red, green, blue, alpha, center) {
    setRadius(radius);
}

double Cone::getRadius() const {
    return radius;
}

double Cone::getLeftX() const {
    return center.x - radius;
}

double Cone::getRightX() const  {
    return center.x + radius;
}

double Cone::getTopY() const {
    return center.y - radius;
}

double Cone::getBottomY() const {
    return center.y + radius;
}

void Cone::setRadius(double r) {
    if (r < 0) {
        r = 0;
    }
    radius = r;
}

void Cone::changeRadius(double delta) {
    setRadius(radius + delta);
}

void Cone::rotate(double angle) {

}

void Cone::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    for (double i = 0; i < .16*PI; i += (2.0*PI)/360.0) {
        glVertex2f(center.x + (radius * cos(i)),
                   center.y + (radius * sin(i)));
    }
    // End Triangle Fan
    glEnd();
}

void Cone::drawAngled(double startAngle, double endAngle) {
    // Enables transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(fill.red, fill.green, fill.blue, fill.alpha);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    for (double i = startAngle; i < endAngle*PI; i += (2.0*PI)/360.0) {
        glVertex2f(center.x + (radius * cos(i)),
                   center.y + (radius * sin(i)));
    }
    // End Triangle Fan
    glEnd();
}

