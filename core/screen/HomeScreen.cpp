#include "HomeScreen.h"
#include "Controller.h"

HomeScreen::HomeScreen(Controller *controller) : Screen(controller) {}

const char *HomeScreen::getName() {
    return "Home";
}

void HomeScreen::enter() {
    Display *display = controller->getDisplay();
    display->showHome();
    for (int i = 0; i < controller->getCellCount(); i++) {
        display->showCellVoltage(i, controller->getCellVoltage(i));
    }
}

void HomeScreen::update() {
    if (controller->didCurrentCellVoltageChanged()) {
        Display *display = controller->getDisplay();
        uint8_t currentCell = controller->getCurrentCell();
        float voltage = controller->getCellVoltage(currentCell);
        display->showCellVoltage(currentCell, voltage);
    }
}

unsigned long HomeScreen::getIdleTimeout() {
    return 3600000;
}
