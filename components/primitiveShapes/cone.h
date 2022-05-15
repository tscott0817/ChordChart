#ifndef CHORDCHART_CONE_H
#define CHORDCHART_CONE_H
#include "shape.h"

class Cone : public Shape {
private:
    double radius;
public:
    /* Constructors */
    Cone();
    explicit Cone(double radius);
    explicit Cone(color fill);
    explicit Cone(point2D center);
    Cone(color fill, point2D center);
    Cone(double red, double green, double blue, double alpha);
    Cone(double x, double y);
    Cone(double red, double green, double blue, double alpha, double x, double y);
    Cone(color fill, double x, double y);
    Cone(double red, double green, double blue, double alpha, point2D center);
    Cone(color fill, double radius);
    Cone(point2D center, double radius);
    Cone(color fill, point2D center, double radius);
    Cone(double red, double green, double blue, double alpha, double radius);
    Cone(double x, double y, double radius);
    Cone(double red, double green, double blue, double alpha, double x, double y, double radius);
    Cone(color fill, double x, double y, double radius);
    Cone(double red, double green, double blue, double alpha, point2D center, double radius);

    /* Destructor */
    virtual ~Cone() = default;

    /* Getters */
    double getRadius() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setter */
    void setRadius(double r);
    void changeRadius(double delta);

    void rotate(double angle);

    /* Draw */
    void draw() const override;
    void drawAngled(double startAngle, double endAngle);

};
#endif //CHORDCHART_CONE_H
