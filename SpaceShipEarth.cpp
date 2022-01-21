#include "SpaceShipEarth.h"

int spaceship_earth[EARTH_WIDTH * EARTH_HEIGHT] = {
        _,_,S,S,S,S,S,S,_,_,
        _,S,I,I,I,I,I,I,S,_,
        S,I,I,I,I,I,I,I,I,S,
        S,I,I,I,I,I,I,I,I,S,
        S,I,I,I,I,I,I,I,I,S,
        S,I,I,I,I,I,I,I,I,S,
        S,I,I,I,I,I,I,I,I,S,
        S,I,I,I,I,I,I,I,I,S,
        S,I,I,I,I,I,I,I,S,_,
        _,S,S,S,S,S,S,S,_,_,
    };

SpaceShipEarth::SpaceShipEarth(Speaker* inSpeaker, MMA8452* inAcc, uLCD_4DGL* inScreen)
{
    //center
    setX_pos(58);
    setY_pos(58);
    
    setWidth(EARTH_WIDTH);
    setHeight(EARTH_HEIGHT);
    setSprite(spaceship_earth);
    setScreen(inScreen);
    speaker = inSpeaker;
    acc = inAcc;
    xAccel = 0;
    yAccel = 0;
}

void SpaceShipEarth::draw()
{
    getScreen()->BLIT(getX_pos(), getY_pos(), getWidth(), getHeight(), getSprite());
}

void SpaceShipEarth::explode()
{
    int explosion_sprite[EXPLOSION1_WIDTH * EXPLOSION1_HEIGHT] = {
        R,_,_,_,_,_,R,_,_,_,_,_,_,R,_,_,_,_,_,R,
        O,R,_,_,_,_,_,R,_,_,O,_,R,O,_,_,_,_,R,_,
        _,O,R,_,_,O,_,R,_,_,_,_,R,_,O,_,_,R,_,_,
        _,_,O,R,_,_,_,_,R,_,_,R,_,_,_,_,R,_,_,O,
        _,_,_,O,R,_,_,_,R,_,O,R,_,_,_,R,_,_,_,_,
        _,_,_,_,O,R,_,_,O,O,O,O,_,_,R,_,O,_,_,_,
        _,_,_,_,_,O,R,O,O,O,O,O,O,R,_,O,_,_,_,_,
        _,_,R,R,_,_,O,O,r,O,O,r,O,O,O,_,R,R,_,_,
        _,R,_,_,R,O,O,r,r,O,O,r,r,O,O,R,_,_,R,_,
        R,_,_,_,_,O,O,O,O,O,O,O,O,O,O,_,_,_,_,R,
        _,_,_,_,_,O,O,O,O,O,O,O,O,O,O,_,_,_,_,_,
        _,_,_,R,R,O,O,r,r,O,O,r,r,O,O,R,R,_,_,_,
        _,R,R,O,O,O,O,O,r,O,O,r,O,O,O,O,O,R,R,_,
        R,_,_,_,_,_,R,O,O,O,O,O,O,R,O,_,_,_,_,R,
        _,_,_,_,_,R,_,_,O,O,O,O,_,_,R,O,_,_,_,_,
        _,O,_,_,R,_,_,R,_,O,_,O,R,_,_,R,O,_,_,O,
        _,_,_,R,O,_,R,_,_,O,_,_,O,R,_,_,R,_,_,_,
        _,_,R,O,_,R,_,_,_,O,_,O,_,O,R,_,_,R,_,_,
        _,R,O,_,_,R,_,_,_,O,_,_,_,_,R,_,_,_,R,_,
        R,_,_,_,_,R,_,_,_,O,_,_,O,_,R,_,_,_,_,R,
    };
    setX_pos(getX_pos() - 5);
    setY_pos(getY_pos() - 5);
    getScreen()->BLIT(getX_pos(), getY_pos(), EXPLOSION1_WIDTH, EXPLOSION1_HEIGHT, explosion_sprite);
    getSpeaker()->PlayNote(380, 5.0, 1.0);
}

//update position based on accelerometer
void SpaceShipEarth::update()
{
    double z;
    double f = 15;      
    acc->readXYZGravity(&xAccel, &yAccel, &z);
    if(abs(xAccel * f) >= 1 || abs(yAccel * f) >= 1)
    {
        getScreen()->filled_rectangle(getX_pos(), getY_pos(), getX_pos() + getWidth() - 1, getY_pos() + getHeight() - 1, _);
        setPosition(getX_pos() + f * xAccel, getY_pos() + f * yAccel);
        draw();
    }
    if(getPrev_x() != getX_pos() || getPrev_y() != getY_pos())
        getScreen()->filled_rectangle(getPrev_x(), getPrev_y(), getWidth(), getHeight(), _);
}

Speaker* SpaceShipEarth::getSpeaker()
{
    return speaker;
}


MMA8452* SpaceShipEarth::getAcc()
{
    return acc;
}

void SpaceShipEarth::setSpeaker(Speaker* inSpeaker)
{
    speaker = inSpeaker;
}

void SpaceShipEarth::setPosition(int x, int y)
{
    setX_pos(max(1, min(x, SCREEN_MAX - EARTH_WIDTH + 1)));
    setY_pos(max(1, min(y, SCREEN_MAX - EARTH_HEIGHT + 1)));
}

void SpaceShipEarth::setAcc(MMA8452* inAcc)
{
    acc = inAcc;
}
