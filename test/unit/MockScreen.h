#ifndef SK8BMS_MOCKSCREEN_H
#define SK8BMS_MOCKSCREEN_H

#include <Screen.h>

class MockScreen : public Screen {
public:
    MockScreen(Controller *controller) : Screen(controller) {}

    const char *getName() override {
        return "Mock Screen";
    }

    void enter() override {
        entered = true;
    }

    void update() override {
        updated = true;
    }

    unsigned long getIdleTimeout() override {
        return timeout;
    }

    bool entered = false;
    bool updated = false;
    unsigned long timeout = 6000;
};

#endif //SK8BMS_MOCKSCREEN_H
