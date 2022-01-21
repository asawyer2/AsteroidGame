#ifndef ScreenObject_h
#define ScreenObject_h

#include "mbed.h"
#include "uLCD_4DGL.h"
#include "Speaker.h"
#include "math.h"

#define ASTEROID_HEIGHT 12
#define ASTEROID_WIDTH 15
#define SPRITE_MAX 15
#define EARTH_WIDTH 10
#define EARTH_HEIGHT 10
#define EXPLOSION1_WIDTH 20
#define EXPLOSION1_HEIGHT 20

#define SCREEN_MAX 125
#define SCREEN_MIN 1
#define NUM_ASTEROIDS 4

#define Q 0x808000 //OLIVE
#define I 0x008000 //GREEN
#define S 0xC0C0C0 //SILVER
#define C 0x17202A //UFO GLASS 
#define D 0x797D7F //DARK GREY
#define L 0x00FF00 //LIME
#define P 0xFF00FF //PINK
#define R 0xF1C40F //YELLOW
#define O 0xF39C12 //ORANGE 
#define G 0xAAB7B8 //GREY 
#define _ 0x000000 //BLACK 
#define X 0xFFFFFF //WHITE 
#define B 0x0000FF //BLUE
#define r 0xFF0000 //RED

class ScreenObject
{
public:
    ScreenObject();
    ScreenObject(int, int, int, int, int*, uLCD_4DGL*);

    virtual void draw() = 0;
    virtual void update() = 0;
    
    int getX_pos();
    int getY_pos();
    int getPrev_x();
    int getPrev_y();
    int getWidth();
    int getHeight();
    int* getSprite();
    uLCD_4DGL* getScreen();
    void setX_pos(int);
    void setY_pos(int);
    void setWidth(int);
    void setHeight(int);
    void setSprite(int*);
    void setScreen(uLCD_4DGL*);

private:
    int x_pos;
    int y_pos;
    int prev_x;
    int prev_y;
    int width;
    int height;
    int* sprite;
    uLCD_4DGL* screen;
};

#endif
