#include "AbstractAsteroid.h"

#ifndef ConcreteAsteroid2_h
#define ConcreteAsteroid2_h

class ConcreteAsteroid2: virtual public AbstractAsteroid
{
public:
    // consttructor
    ConcreteAsteroid2(uLCD_4DGL*);
    
    // overriden methods from ScreenObject
    void draw();
    void update();
};

#endif
