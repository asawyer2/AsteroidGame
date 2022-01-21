#include "AbstractAsteroid.h"

#ifndef ConcreteAsteroid3_h
#define ConcreteAsteroid3_h

class ConcreteAsteroid3: virtual public AbstractAsteroid
{
public:
    // constructor
    ConcreteAsteroid3(uLCD_4DGL*);
    
    // overriden methods from ScreenObject
    void draw();
    void update();
};

#endif
