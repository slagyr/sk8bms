
#ifndef ROTARY_H
#define ROTARY_H

#include "Hardware.h"

class Rotary {

public:

    Rotary(Hardware *hardware, byte sw, byte dt, byte clk);
    Hardware* getHardware();
    int getPosition();
    int getSW();
    int getDT();
    int getCLK();
    void setup() const;
    bool hasUpdate();
    void rest();
    void handleRotation();
    int getDebounceDelay();
    void setDebouceDelay(int delay);
    void handleClick();
    bool wasClicked();
    void setPosition(int position);
    void setClicked(bool b);

    void setMinClickSeparation(unsigned int minClickSeparation);

    unsigned int getMinClickSeparation() const;

private:

    Hardware *hardware;
    byte sw;
    byte dt;
    byte clk;
    volatile int position;
    volatile bool updated;
    volatile bool clicked;
    int debounceDelay;
    unsigned long lastEventTime;
    unsigned int minClickSeparation;
    unsigned long lastClickTime;

    bool notBounced(unsigned long now);

};


#endif
