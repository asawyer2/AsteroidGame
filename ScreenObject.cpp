#include "ScreenObject.h"

ScreenObject::ScreenObject()
{
    x_pos = 0;
    y_pos = 0;
    prev_x = 0;
    prev_y = 0;
    width = 0;
    height = 0;
    sprite = NULL;
    screen = NULL;
}

ScreenObject::ScreenObject(int inX, int inY, int inW, int inH, int* inSprite, uLCD_4DGL* inScreen): 
    x_pos(inX), y_pos(inY), prev_x(inX), prev_y(inY), width(inW), height(inH), sprite(inSprite), screen(inScreen)
{ }

int ScreenObject::getX_pos()
{
    return x_pos;
}

int ScreenObject::getY_pos()
{
    return y_pos;
}

int ScreenObject::getPrev_x()
{
    return prev_x;
}

int ScreenObject::getPrev_y()
{
    return prev_y;
}

int ScreenObject::getWidth()
{
    return width;
}

int ScreenObject::getHeight()
{
    return height;
}

int* ScreenObject::getSprite()
{
    return sprite;
}

uLCD_4DGL* ScreenObject::getScreen()
{
    return screen;
}

void ScreenObject::setX_pos(int inX)
{
    prev_x = x_pos;
    x_pos = inX;
}

void ScreenObject::setY_pos(int inY)
{
    prev_y = y_pos;
    y_pos = inY;
}

void ScreenObject::setWidth(int inW)
{
    width = inW;
}

void ScreenObject::setHeight(int inH)
{
    height = inH;
}

void ScreenObject::setSprite(int* inSprite)
{
    sprite = inSprite;
}

void ScreenObject::setScreen(uLCD_4DGL* inScreen)
{
    screen = inScreen;
}
