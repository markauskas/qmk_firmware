RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool_effect2)
RGB_MATRIX_EFFECT(lol)
RGB_MATRIX_EFFECT(some_color)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  return led_max < DRIVER_LED_TOTAL;
}

static uint8_t r_state;
static uint8_t g_state;
static uint8_t b_state;
static void my_cool_effect2_complex_init(effect_params_t* params) {
  r_state = 0;
  g_state = 0;
  b_state = 0;
}
static bool my_cool_effect2_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  g_state = led_min;
  b_state = led_max;
  for (uint8_t i = led_min; i < led_max; i++) {
    if (i < 60) {
      r_state = 255;
    }
    /* if (i < 50) { */
    /*   g_state = 200; */
    /* } */
    /* if (i > 30) { */
    /*   b_state = 200; */
    /* } */
    g_state = led_max - led_min;
    b_state = 0;
    rgb_matrix_set_color(i, r_state, g_state, b_state);
  }

  return led_max < DRIVER_LED_TOTAL;
}
static bool my_cool_effect2(effect_params_t* params) {
  if (params->init) my_cool_effect2_complex_init(params);
  return my_cool_effect2_complex_run(params);
}

static void lol_set_color(int i, effect_params_t* params) {
    if (!HAS_ANY_FLAGS(g_led_config.flags[i], params->flags)) return;
    HSV hsv = {0, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v};

    // Take the shortest path between hues
    int16_t deltaH = ((rgb_matrix_config.hsv.h + 180) % 360 - rgb_matrix_config.hsv.h) / 4;
    if (deltaH > 127) {
        deltaH -= 256;
    } else if (deltaH < -127) {
        deltaH += 256;
    }

    hsv.h   = rgb_matrix_config.hsv.h + (deltaH * (rand() & 0x03));
    RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

static uint16_t some_counter;

static bool lol(effect_params_t* params) {
    if (params->init) {
	    some_counter = 0;
    }
    if (!params->init) {
        if (scale16by8(g_rgb_timer % 512, qadd8(rgb_matrix_config.speed, 16)) % 10 == 0) {
            some_counter = g_rgb_timer % 20000;
	    // dprintf("some_counter: %d\n", some_counter);
	    //dprintf("g_rgb_timer: %d speed: %d qadd8(rgb_matrix_config.speed, 16): %d ifff: %d\n", g_rgb_timer, rgb_matrix_config.speed, qadd8(rgb_matrix_config.speed, 16), scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 16)));
            lol_set_color(rand() % DRIVER_LED_TOTAL, params);
        }
        return false;
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (int i = led_min; i < led_max; i++) {
        lol_set_color(i, params);
    }
    // dprintf("leds: %d-%d\n", led_min, led_max);
    return led_max < DRIVER_LED_TOTAL;
}

static bool some_color(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
