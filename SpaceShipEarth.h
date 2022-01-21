#ifndef SpaceShipEarth_h
#define SpaceShipEarth_h

#include "ScreenObject.h"
#include "MMA8452.h"

class SpaceShipEarth: public ScreenObject
{
public:
    SpaceShipEarth(Speaker*, MMA8452*, uLCD_4DGL*);
    
    void draw();
    void update();
    void explode();
    
    void setAcc(MMA8452*);
    void setSpeaker(Speaker*);
    void setPosition(int, int);   

    MMA8452* getAcc();
    Speaker* getSpeaker();
  

private:
    Speaker* speaker;
    MMA8452* acc;
    double xAccel, yAccel;          
};
#endif