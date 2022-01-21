#include "ConcreteAsteroid4.h"

int asteroid_sprite_4[ASTEROID_HEIGHT * ASTEROID_WIDTH] = {
    _,_,_,X,X,X,X,X,X,X,_,_,_,_,_,
    _,_,_,_,X,_,_,_,_,_,X,_,_,_,_,
    _,_,_,_,_,X,_,_,_,_,_,X,_,_,_,
    _,X,X,X,X,X,_,_,_,_,_,_,X,_,_,
    X,_,_,_,_,_,_,_,_,_,_,_,_,X,_,
    X,_,_,_,_,_,_,_,_,_,X,X,X,_,_,
    X,_,_,_,_,_,_,_,_,_,X,_,_,_,_,
    _,X,_,_,_,_,_,_,_,_,_,X,_,_,_,
    _,X,_,_,_,_,_,X,X,_,_,_,X,X,_,
    _,_,X,_,_,X,X,_,_,X,_,_,_,X,_,
    _,_,_,X,X,_,_,_,_,_,X,X,X,_,_
};

ConcreteAsteroid4::ConcreteAsteroid4(uLCD_4DGL* inScreen): AbstractAsteroid(NULL, inScreen)
{

    setSprite(asteroid_sprite_4);
}

void ConcreteAsteroid4::draw()
{
    getScreen()->BLIT(getX_pos(), getY_pos(), ASTEROID_WIDTH, ASTEROID_HEIGHT, getSprite());
}

void ConcreteAsteroid4::update()
{
    updatePosition();
    getScreen()->filled_rectangle(getPrev_x(), getPrev_y(), getPrev_x() + getWidth() - 1, getPrev_y() + getHeight() - 1, _);
}
