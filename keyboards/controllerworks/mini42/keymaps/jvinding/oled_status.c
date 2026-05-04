#include QMK_KEYBOARD_H
#include "jvinding.h"

#ifdef OLED_ENABLE

// mini42.c::oled_init_kb handles rotation (both halves at 90°) and does
// not chain into oled_init_user, so this is intentionally a pass-through.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

// ---------------------------------------------------------------------------
// WPM-reactive cat animation — rendered on the master (right) half.
//
// The right OLED is a 128x32 SSD1306 rotated 90°, giving a portrait layout
// of 5 chars wide × 16 rows tall. The animation occupies rows 5-9 (centred).
//
// States:       idle  (WPM <  10) — cat sits, eyes blink
//               walk  (WPM < 40)  — cat trots, legs alternate
//               run   (WPM ≥ 40)  — cat sprints, legs spread wide
// ---------------------------------------------------------------------------

static void render_wpm_anim(void) {
    static uint8_t  frame      = 0;
    static uint32_t last_frame = 0;

    if (timer_elapsed32(last_frame) > 200) {
        last_frame = timer_read32();
        frame ^= 1;
    }

    uint8_t wpm = get_current_wpm();
    oled_set_cursor(0, 5);

    if (wpm < 10) {
        // Idle: sitting cat, eyes blink every other frame
        oled_write_ln_P(PSTR("/\\_/\\"), false);
        oled_write_ln_P(frame ? PSTR("(-,-)") : PSTR("(o.o)"), false);
        oled_write_ln_P(PSTR("(_|_)"), false);
        oled_write_ln_P(PSTR(" | | "), false);
        oled_write_ln_P(PSTR(" m m "), false);
    } else if (wpm < 40) {
        // Walk: legs alternate between forward/back positions
        oled_write_ln_P(PSTR("/\\_/\\"), false);
        oled_write_ln_P(PSTR("(o.o)"), false);
        oled_write_ln_P(PSTR("(_|_)"), false);
        if (frame) {
            oled_write_ln_P(PSTR("  |/ "), false);
            oled_write_ln_P(PSTR("\\ |  "), false);
        } else {
            oled_write_ln_P(PSTR("/ |  "), false);
            oled_write_ln_P(PSTR("  |\\ "), false);
        }
    } else {
        // Run: legs fully spread, face alternates direction
        oled_write_ln_P(PSTR("/\\_/\\"), false);
        oled_write_ln_P(frame ? PSTR("(o.<)") : PSTR("(>.o)"), false);
        oled_write_ln_P(PSTR(" =|= "), false);
        if (frame) {
            oled_write_ln_P(PSTR("\\ \\ \\"), false);
        } else {
            oled_write_ln_P(PSTR("/ / /"), false);
        }
        oled_write_ln_P(PSTR("     "), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_wpm_anim();
    } else {
        jv_oled_render_status();
    }
    return false;
}

#endif
