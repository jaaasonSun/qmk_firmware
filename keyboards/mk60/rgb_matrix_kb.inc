RGB_MATRIX_EFFECT(dual_tone_hue_left)
RGB_MATRIX_EFFECT(dual_tone_sat_left)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    define LEFT_DIAG_1 368
#    define LEFT_DIAG_2 288

static bool dual_tone_hue_left(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
    hsv.h += rgb_matrix_config.speed;
    RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);
    
    for (uint8_t i = led_min; i < led_max; ++i) {
        point_t pos = g_led_config.point[i];
        int val = 4 * (int)pos.x + 3 * (int)pos.y;
        if (val <= LEFT_DIAG_2)
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        else rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
    }

    return led_max < DRIVER_LED_TOTAL;
}

static bool dual_tone_sat_left(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv = rgb_matrix_config.hsv;
    RGB rgb1 = rgb_matrix_hsv_to_rgb(hsv);
    hsv.s -= rgb_matrix_config.speed;
    RGB rgb2 = rgb_matrix_hsv_to_rgb(hsv);
    hsv.s -= rgb_matrix_config.speed;
    RGB rgb3 = rgb_matrix_hsv_to_rgb(hsv);
    
    for (uint8_t i = led_min; i < led_max; ++i) {
        point_t pos = g_led_config.point[i];
        int val = 4 * (int)pos.x + 3 * (int)pos.y;
        if (val <= LEFT_DIAG_2)
            rgb_matrix_set_color(i, rgb3.r, rgb3.g, rgb3.b);
        else if (val <= LEFT_DIAG_1)
            rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
        else rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
    }

    return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
