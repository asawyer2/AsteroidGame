#include "ScreenObject.h"

#ifndef AbstractAsteroid_h
#define AbstractAsteroid_h


class AbstractAsteroid : public ScreenObject {
public:
    AbstractAsteroid();
    AbstractAsteroid(int, int, int, int*, uLCD_4DGL*);
    AbstractAsteroid(int, int, int, int, int, int*, uLCD_4DGL*);
    AbstractAsteroid(int*, uLCD_4DGL*);

    //random due to the nature of the assignment 
    void randStart();
    void randAssignDelta();
    void updatePosition();

    int getDeltaX();
    int getDeltaY();
    void setDeltaX(int);
    void setDeltaY(int);

    double getSpeed();
    void setSpeed(double);

private:
    int deltaX;
    int deltaY;
    double speed;
};



#endif
