#ifndef SK8BMS_HOMESCREEN_H
#define SK8BMS_HOMESCREEN_H


#include <Screen.h>

class HomeScreen : public Screen {

public:
    HomeScreen(Controller *controller);

    const char *getName() override;

    void enter() override;

    void update() override;

    unsigned long getIdleTimeout() override;

};


#endif //SK8BMS_HOMESCREEN_H
