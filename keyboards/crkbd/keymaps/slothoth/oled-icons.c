// Copyright 2021 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

/* Graphical active layer and modifier status display.
   Modified from @soundmonster's keymap:
   (keyboards/crkbd/keymaps/soundmonster)
   Usage guide
   1 Place this file next to keymap.c or in userspace.
   2 Add the following lines into rules.mk:
        OLED_ENABLE = yes
        SRC += oled-icons.c
   3 Add the following lines into the main 'oled_task_user()'
     function to render this module:
        extern void render_mod_status(void);
        render_mod_status();
   4 Add the font file reference into `config.h`:
        #define OLED_FONT_H "oledfont.c"
   5 Add your layer numbers for NUM, SYM, and FNC. Example:
        #define NUM 1
        #define SYM 2
        #define FNC 3
*/

#include QMK_KEYBOARD_H

#define NUM 1
#define SYM 2
#define FNC 3


// Primary modifier status display function
void render_mod_status(void) {
}