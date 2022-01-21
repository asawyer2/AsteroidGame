#include "AbstractAsteroid.h"

#ifndef ConcreteAsteroid1_h
#define ConcreteAsteroid1_h

class ConcreteAsteroid1: virtual public AbstractAsteroid
{
public:
    // constructor
    ConcreteAsteroid1(uLCD_4DGL*);
    
    // overriden methods from ScreenObject
    void draw();
    void update();
};

#endif
