#include "ConcreteAsteroid1.h"

int asteroid_sprite_1[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
     _,_,_,_,X,X,X,X,X,X,X,X,_,_,_,
    _,_,_,X,_,_,_,_,_,_,_,_,X,_,_,
    _,_,X,_,_,_,_,_,_,_,_,_,X,_,_,
    _,X,_,_,_,_,_,_,_,_,_,_,X,_,_,
    X,X,X,X,_,_,_,_,_,_,_,_,_,X,_,
    _,_,_,X,_,_,_,_,_,_,_,_,_,X,_,
    _,_,X,_,_,_,_,_,_,_,_,_,_,X,_,
    _,X,_,_,_,_,_,X,_,_,_,_,_,X,_,
    X,_,_,_,_,_,X,X,_,_,_,_,X,_,_,
    _,X,_,_,_,X,_,X,_,_,_,_,X,_,_,
    _,_,X,_,X,_,_,X,_,_,_,X,_,_,_,
    _,_,_,X,_,_,_,X,X,X,X,_,_,_,_
};
    
ConcreteAsteroid1::ConcreteAsteroid1(uLCD_4DGL* inScreen): AbstractAsteroid(NULL, inScreen)
{
    setSprite(asteroid_sprite_1);
}

void ConcreteAsteroid1::draw()
{
    getScreen()->BLIT(getX_pos(), getY_pos(), getWidth(), getHeight(), getSprite());
}

void ConcreteAsteroid1::update()
{
    updatePosition();
    getScreen()->filled_rectangle(getPrev_x(), getPrev_y(), getPrev_x() + getWidth() - 1, getPrev_y() + getHeight() - 1, _);
}
