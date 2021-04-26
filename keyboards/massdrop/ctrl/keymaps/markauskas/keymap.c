#include QMK_KEYBOARD_H

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout

    MY_RGB,                // MY CUSTOM RGB mode
    TMX_1,
    TMX_2,
    TMX_3,
    TMX_4,
    TMX_5,
    TMX_6,
    TMX_7,
    TMX_8,
    TMX_9,
    TMX_10,
    TMX_11,
    TMX_12,
};

enum layout_names {
    _DEFAULT = 0,
    _RGB,
    _NAV,
};

#define MY_ESCTL LCTL_T(KC_ESC)
#define MO_RGB   MO(_RGB)
#define MO_NAV   MO(_NAV)
#define MY_TAB   LT(_NAV, KC_TAB)
#define MY_SPC   LT(_NAV, KC_SPC)

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEFAULT] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
    MY_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
    MY_ESCTL,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
    KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC,                             KC_LCMD, KC_ROPT, MO_RGB,  MO_NAV,             KC_LEFT, KC_DOWN, KC_RGHT \
),

[_RGB] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,            _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
    _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
    _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, \
    _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
    _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
),

[_NAV] = LAYOUT(
    _______, DBG_TOG, DBG_MTRX,DBG_KBD, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,            _______, _______, _______, \
    _______, TMX_1,   TMX_2,   TMX_3,   TMX_4,   TMX_5,   TMX_6,   TMX_7,   TMX_8,   TMX_9,   TMX_10,  _______, _______, _______,   _______, _______, _______, \
    _______, TMX_11,  TMX_12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
    _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
),

/*
[EMPTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                              _______, \
    _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
),
*/
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

/* const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6 */
/*     {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12 */
/* ); */

/* // Light LEDs 9-16 in cyan when keyboard layer 1 is active */
/* const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {9, 8, HSV_CYAN} */
/* ); */
/* // Light LEDs 11-18 in purple when keyboard layer 2 is active */
/* const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {11, 8, HSV_PURPLE} */
/* ); */

/* const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( */
/* 		my_capslock_layer, */
/*     my_layer1_layer,    // Overrides caps lock layer */
/*     my_layer2_layer     // Overrides other layers */
/* ); */

/* void keyboard_post_init_user(void) { */
/*     // Enable the LED layers */
/*     rgblight_layers = my_rgb_layers; */
/* } */

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     // Both layers will light up if both kb layers are active */
/*     rgblight_set_layer_state(1, layer_state_cmp(state, 1)); */
/*     rgblight_set_layer_state(2, layer_state_cmp(state, 2)); */
/*     return state; */
/* } */

/* bool led_update_user(led_t led_state) { */
/*     rgblight_set_layer_state(0, led_state.caps_lock); */
/*     return true; */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

#ifdef CONSOLE_ENABLE
    // uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

    switch (keycode) {
	case TMX_1:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"1");
	    }
	    return false;
	case TMX_2:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"2");
	    }
	    return false;
	case TMX_3:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"3");
	    }
	    return false;
	case TMX_4:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"4");
	    }
	    return false;
	case TMX_5:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"5");
	    }
	    return false;
	case TMX_6:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"6");
	    }
	    return false;
	case TMX_7:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"7");
	    }
	    return false;
	case TMX_8:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"8");
	    }
	    return false;
	case TMX_9:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"9");
	    }
	    return false;
	case TMX_10:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"'10"SS_TAP(X_ENTER));
	    }
	    return false;
	case TMX_11:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"'11"SS_TAP(X_ENTER));
	    }
	    return false;
	case TMX_12:
	    if (record->event.pressed) {
		    SEND_STRING(SS_LCTL("a")"'12"SS_TAP(X_ENTER));
	    }
	    return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
	case MY_RGB:
	    if (record->event.pressed) {
		    rgb_matrix_mode(RGB_MATRIX_CUSTOM_lol);
	    }
	    return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
