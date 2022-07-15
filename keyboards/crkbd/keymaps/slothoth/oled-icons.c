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

static void render_layer_state(uint8_t const state) {
	static char const base_layer[] PROGMEM = {
		0x20, 0x9a, 0x9b, 0x9c, 0x20,
		0x20, 0xba, 0xbb, 0xbc, 0x20,
		0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
	static char const numb_layer[] PROGMEM = {
		0x20, 0x94, 0x95, 0x96, 0x20,
		0x20, 0xb4, 0xb5, 0xb6, 0x20,
		0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
	static char const symb_layer[] PROGMEM = {
		0x20, 0x97, 0x98, 0x99, 0x20,
		0x20, 0xb7, 0xb8, 0xb9, 0x20,
		0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
	static char const func_layer[] PROGMEM = {
		0x20, 0x9d, 0x9e, 0x9f, 0x20,
		0x20, 0xbd, 0xbe, 0xbf, 0x20,
		0x20, 0xdd, 0xde, 0xdf, 0x20, 0};

	switch(state) {
	case FNC: oled_write_P(func_layer, false); break;
	case SYM: oled_write_P(symb_layer, false); break;
	case NUM: oled_write_P(numb_layer, false); break;
	default:  oled_write_P(base_layer, false);
	}
}

// Primary modifier status display function
void render_mod_status(void) {
	uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
	mods |= get_oneshot_mods();
#endif
	oled_set_cursor(0,6);
	render_layer_state(get_highest_layer(layer_state|default_layer_state));
	oled_set_cursor(0,11);
}