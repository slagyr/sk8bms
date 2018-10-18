#ifndef SK8BMS_SPLASHSCREEN_H
#define SK8BMS_SPLASHSCREEN_H


#include <Screen.h>

class SplashScreen : public Screen {

public:
    explicit SplashScreen(Controller *controller);

    const char *getName() override;

    void enter() override;

    void update() override;

    unsigned long getIdleTimeout() override;
};


#endif //SK8BMS_SPLASHSCREEN_H
