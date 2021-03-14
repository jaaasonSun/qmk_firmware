#include "mk60.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    

    led_set_user(usb_led);
}

led_config_t g_led_config = {
    {
        { 63, NO_LED, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50 },
        { 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, NO_LED, 36 },
        { NO_LED, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, NO_LED, 23 },
        { 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, NO_LED, 9 },
        { 8, 7, 6, NO_LED, NO_LED, NO_LED, 5, NO_LED, NO_LED, 4, 3, 2, NO_LED, 1, 0 },
    }, {
        { 224, 64 }, { 208, 64 }, { 192, 64 }, { 176, 64 }, { 160, 64 }, { 102, 64 }, { 42, 64 }, { 22, 64 }, { 2, 64 }, 
        { 224, 48 }, { 208, 48 }, { 192, 48 }, { 176, 48 }, { 160, 48 }, { 144, 48 }, { 128, 48 }, { 112, 48 }, { 96, 48 }, { 80, 48 }, { 64, 48 }, { 48, 48 }, { 32, 48 }, { 8, 48 },
        { 214, 32 }, { 188, 32 }, { 172, 32 }, { 156, 32 }, { 140, 32 }, { 124, 32 }, { 108, 32 }, { 92, 32 }, { 76, 32 }, { 60, 32 }, { 44, 32 }, { 28, 32 }, { 6, 32 },
        { 220, 16 }, { 200, 16 }, { 184, 16 }, { 168, 16 }, { 152, 16 }, { 136, 16 }, { 120, 16 }, { 104, 16 }, { 88, 16 }, { 72, 16 }, { 56, 16 }, { 40, 16 }, { 24, 16 }, { 4, 16 },
        { 216, 0 }, { 192, 0 }, { 176, 0 }, { 160, 0 }, { 144, 0 }, { 128, 0 }, { 112, 0 }, { 96, 0 }, { 80, 0 }, { 64, 0 }, { 48, 0 }, { 32, 0 }, { 16, 0 }, { 0, 0 }, 
    }, {
        1, 1, 1, 1, 1, 4, 1, 1, 1,
        1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    }};
