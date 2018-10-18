#ifndef SK8BMS_SCREEN_H
#define SK8BMS_SCREEN_H

class Controller;

class Screen {
public:
    virtual ~Screen() = default;

    virtual unsigned long getIdleTimeout() { return 5000; };

    virtual const char *getName() = 0;

    virtual void enter() = 0;

    virtual void update() = 0;

protected:
    explicit Screen(Controller *controller) {
        this->controller = controller;
    };

    Controller *controller;
};


#endif //SK8BMS_SCREEN_H
