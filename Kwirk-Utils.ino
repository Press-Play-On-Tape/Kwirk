#include <ArduboyFX.h>  
#include "src/utils/ArduboyG.h"
#include "src/utils/Constants.h"
#include "src/utils/Enums.h"
#include "fxdata/fxdata.h"
#include "src/entities/Entities.h"
#include "src/utils/SpritesU.hpp"

uint8_t getJustPressedButtons() {

    a.pollButtons();

    return a.justPressedButtons();

}

uint8_t getPressedButtons() {

    return a.pressedButtons();

}

void saveCookie(bool enableLEDs) {

    #ifdef USE_LED
    if (enableLEDs) {
        #ifndef MICROCADE
            a.setRGBled(RED_LED, 32);
        #else
            a.setRGBledGreenOff();
            a.setRGBledBlueOff();
        #endif
    }
    #endif

    FX::saveGameState(cookie);

    #ifdef USE_LED
    if (enableLEDs) {
        #ifndef MICROCADE
            a.setRGBled(RED_LED, 0);
            a.setRGBled(GREEN_LED, 32);
        #else
            a.setRGBledRedOff();
            a.setRGBledGreenOn();
        #endif
    }
    #endif

}

void deactivateLEDs() {

    #ifdef USE_LED
        #ifndef MICROCADE
            a.setRGBled(0, 0, 0);
        #else
            a.setRGBledRedOff();
            a.setRGBledGreenOff();
            a.setRGBledBlueOff();
        #endif
    #endif

}

void handleNorthScroll(PlayerCanMove playerCanMove) {

    level.getPlayer().setDirection(Direction::North);

    if (level.getMapY() != level.loadMap_MapY(level.getPlayer().getY_WorldCoords() - 1)) {

        level.setMoving_Y(8);

    }
    else {

        level.getPlayer().setMoving_Y(-8);
        level.getPlayer().setSpeed(static_cast<uint8_t>(playerCanMove) * 2);

    }

}

void handleEastScroll(PlayerCanMove playerCanMove) {

    level.getPlayer().setDirection(Direction::East);

    if (level.getMapX() != level.loadMap_MapX(level.getPlayer().getX_WorldCoords() + 1)) {

        level.setMoving_X(-8);

    }
    else {

        level.getPlayer().setMoving_X(8);
        level.getPlayer().setSpeed(static_cast<uint8_t>(playerCanMove) * 2);

    }

}

void handleSouthScroll(PlayerCanMove playerCanMove) {

    level.getPlayer().setDirection(Direction::South);

    if (level.getMapY() != level.loadMap_MapY(level.getPlayer().getY_WorldCoords() + 1)) {

        level.setMoving_Y(-8);

    }
    else {

        level.getPlayer().setMoving_Y(8);
        level.getPlayer().setSpeed(static_cast<uint8_t>(playerCanMove) * 2);

    }

}

void handleWestScroll(PlayerCanMove playerCanMove) {

    level.getPlayer().setDirection(Direction::West);

    if (level.getMapX() != level.loadMap_MapX(level.getPlayer().getX_WorldCoords() - 1)) {

        level.setMoving_X(8);

    }
    else {

        level.getPlayer().setMoving_X(-8);
        level.getPlayer().setSpeed(static_cast<uint8_t>(playerCanMove) * 2);

    }

}

