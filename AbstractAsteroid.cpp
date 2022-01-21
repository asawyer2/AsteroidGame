#include "AbstractAsteroid.h"

//base: no data given
AbstractAsteroid::AbstractAsteroid(): ScreenObject(0, 0, 0, 0, NULL, NULL), deltaX(0), deltaY(0), speed(0)
{ }

//dX and dY not given
AbstractAsteroid::AbstractAsteroid(int iX, int iY, int inSpeed, int* inSprite, uLCD_4DGL* inScreen):
    ScreenObject(iX, iY, ASTEROID_WIDTH, ASTEROID_HEIGHT, inSprite, inScreen), deltaX(0), deltaY(0), speed(inSpeed)
{ } 

//all inputs are specified 
AbstractAsteroid::AbstractAsteroid(int dX, int dY, int inSpeed, int iX, int iY, int* inSprite, uLCD_4DGL* inScreen):
    ScreenObject(iX, iY, ASTEROID_WIDTH, ASTEROID_HEIGHT, inSprite, inScreen), deltaX(dX), deltaY(dY), speed(inSpeed)
{ } 

//randomly assigned
AbstractAsteroid::AbstractAsteroid(int* inSprite, uLCD_4DGL* inScreen)
{ 
	setX_pos(1);
    setY_pos(1);
    setSpeed(rand() * 12 + 3);      
    setSprite(inSprite);
    setScreen(inScreen);
    setWidth(ASTEROID_WIDTH);
    setHeight(ASTEROID_HEIGHT);
    randStart();
    randAssignDelta();
}

//assign random location for start, move clockwise around the screen: 0 = top, 1 = right, 2 = bottom, 3 = left
void AbstractAsteroid::randStart()
{
    int side = rand() % 4;      
    if (side == 3) {
        setX_pos(1);
        setY_pos(rand() % (SCREEN_MAX - getHeight() + 1) + 1);
    } else if (side == 2) {
        setX_pos(rand() % (SCREEN_MAX - getWidth() + 1) + 1);
        setY_pos(SCREEN_MAX - getHeight() + 1);
    } else if (side == 1) {
        setX_pos(SCREEN_MAX - getWidth() + 1);
        setY_pos(rand() % (SCREEN_MAX - getHeight() + 1) + 1);
    } else {
        setX_pos(rand() % (SCREEN_MAX - getWidth() + 1) + 1);
        setY_pos(1);
    }
}

void AbstractAsteroid::randAssignDelta()
{
    int x_final = rand() * SCREEN_MAX + 1;
    int y_final = rand() * SCREEN_MAX + 1;
    setDeltaX((x_final - getX_pos())/getSpeed());
    setDeltaY((y_final - getY_pos())/getSpeed());
}

void AbstractAsteroid::updatePosition()
{
    int newX = getX_pos() + getDeltaX();
    int newY = getY_pos() + getDeltaY();
    
    if(newX <= 1 || newX >= SCREEN_MAX - getWidth() + 1)
        setDeltaX(deltaX * -1.0);       
    if(newY <= 1 || newY >= SCREEN_MAX - getHeight() + 1)
        setDeltaY(deltaY * -1.0);       
    setX_pos(max(1, min(newX, SCREEN_MAX - getWidth() + 1)));
    setY_pos(max(1, min(newY, SCREEN_MAX - getHeight() + 1)));
}

int AbstractAsteroid::getDeltaX()
{
    return deltaX;
}

int AbstractAsteroid::getDeltaY()
{
    return deltaY;
}

double AbstractAsteroid::getSpeed()
{
    return speed;
} 

void AbstractAsteroid::setDeltaX(int inDeltaX)
{
    deltaX = inDeltaX;
}

void AbstractAsteroid::setDeltaY(int inDeltaY)
{
    deltaY = inDeltaY;
}

void AbstractAsteroid::setSpeed(double inSpeed)
{
    speed = inSpeed;
}
