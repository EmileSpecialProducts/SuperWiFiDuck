#include <Arduino.h>
#include <FS.h> // File
#include <LittleFS.h>

#include "config.h"
#include "debug.h"
#include "duckscript.h"
#include "duckparser.h"
#include "webserver.h"
#include "settings.h"
#include "cli.h"
#include "USB.h"
#include "led.h"

void setup() {
    debug_init();

    debug("Initializing LittleFS...");
    LittleFS.begin(true);
    settings::begin();
    led::begin();
    duckparser::beginKeyboard();
    USB.begin();
    delay(200);
    cli::begin();
    webserver::begin();
    duckscript::run(settings::getAutorun());
}

void loop() {
    webserver::update();
    debug_update();
}