#include "AbstractAsteroid.h"

#ifndef ConcreteAsteroid4_h
#define ConcreteAsteroid4_h

class ConcreteAsteroid4: virtual public AbstractAsteroid
{
public:
    // constructor
    ConcreteAsteroid4(uLCD_4DGL*);
    
    // overriden methods from ScreenObject
    void draw();
    void update();
};

#endif
