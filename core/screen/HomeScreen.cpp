#include "HomeScreen.h"
#include "Controller.h"

HomeScreen::HomeScreen(Controller *controller) : Screen(controller) {}

const char *HomeScreen::getName() {
    return "Home";
}

void HomeScreen::enter() {
    Display *display = controller->display;
    display->showHome();
    for (int i = 0; i < controller->getCellCount(); i++) {
        display->showCellVoltage(i, controller->getCellVoltage(i));
    }
}

void HomeScreen::update() {
    Display *display = controller->display;
    if (controller->didCurrentCellVoltageChanged()) {
        uint8_t currentCell = controller->getCurrentCell();
        float voltage = controller->getCellVoltage(currentCell);
        display->showCellVoltage(currentCell, voltage);
    }
    if(controller->didBalancingChanged()) {
        display->showBalancing(controller->isBalancing(), controller->getLowestVoltageCell(), controller->getHighestVoltageCell());
    }
}

unsigned long HomeScreen::getIdleTimeout() {
    return 3600000;
}
