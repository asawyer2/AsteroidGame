#include <ctime>

#include "SpaceShipEarth.h"
#include "ConcreteAsteroid1.h"
#include "ConcreteAsteroid2.h"
#include "ConcreteAsteroid3.h"
#include "ConcreteAsteroid4.h"

bool overlap(ScreenObject&, ScreenObject&);

uLCD_4DGL uLCD(p9, p10, p11); //serial tx, serial rx, reset pin;
Serial pc(USBTX,USBRX);
Speaker gameSpeaker(p25); //speaker
MMA8452 acc(p28, p27, 40000); //accelerometer
Timer t;

int main()
{
    int numAsteroids = 4;  
    bool endGame = false; 

    //LCD display setup
    uLCD.baudrate(6000);
    wait(0.2);
    srand(time(0));


    acc.setBitDepth(MMA8452::BIT_DEPTH_12);
    acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
    acc.setDataRate(MMA8452::RATE_100);

    //create game objs 
    ScreenObject* ActiveAsteroids[numAsteroids];
    ActiveAsteroids[0] = new ConcreteAsteroid1(&uLCD);
    ActiveAsteroids[1] = new ConcreteAsteroid2(&uLCD);
    ActiveAsteroids[2] = new ConcreteAsteroid3(&uLCD);
    ActiveAsteroids[3] = new ConcreteAsteroid4(&uLCD);
    SpaceShipEarth ship(&gameSpeaker, &acc, &uLCD);

    
    while(1) {
        if(acc.isXYZReady()) {
            break;
        }
    }
    
    //draw asteroids & ship 
    for(int i = 0; i < numAsteroids; i++) {
        ActiveAsteroids[i]->draw();
    }
    ship.draw();

    //timer
    uLCD.filled_rectangle(SCREEN_MAX + 1, 1, 128, SCREEN_MAX, I);
    //start timer
    t.start();
    
    //game begins here!!
    while(t.read() < 30 && !endGame)
    {
        //updates timer
        uLCD.filled_rectangle(SCREEN_MAX + 1, 1, 128, SCREEN_MAX / 30.0 * t.read(), _);

        //updates location of objs      
        ship.update();
        for(int i = 0; i < numAsteroids; i++)
            ActiveAsteroids[i]->update();
            
        //redraw objs as they're updated
        ship.draw();
        for(int i = 0; i < numAsteroids; i++)
            ActiveAsteroids[i]->draw();

        //check overlap
        for(int i = 0; i < numAsteroids; i++) {
            //if overlap -> GAME OVER
            if(overlap(ship,*(ActiveAsteroids[i]))) {
                ship.explode();
                endGame = true;
                break;
            }
        }
    }
    
    //clear screem
    uLCD.filled_rectangle(1,1,128,128,_);
    t.stop();
    
    if(endGame) {
        //lost
        uLCD.printf("GAME OVER");
    } else {
        //complete at end of 30 sec 
        uLCD.printf("Mission Complete!");
    }
}

//checks for overlap 
bool overlap(ScreenObject& a, ScreenObject& b)
{
    if(abs(b.getX_pos() - a.getX_pos()) < a.getWidth() && abs(b.getY_pos() - a.getY_pos()) < a.getHeight()) {
        return true;
    }
    return false;
}
