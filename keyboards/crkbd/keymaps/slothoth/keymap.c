/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

#define _COLEMAKDHM 0 
#define _NUMPAD 1
#define _SYM 2
#define _NAV 3

// Layer toggle and switch
#define T_NAV TT(_NAV)
#define S_NAV MO(_NAV)
#define T_SYM TT(_SYM)
#define S_SYM MO(_SYM)

// Tap/mod keys
#define RCTL_BR RCTL_T(KC_RBRACKET)
#define LCTL_BR LCTL_T(KC_LBRACKET)
#define SFT_SPC LSFT_T(KC_SPACE)
#define SFT_ENT RSFT_T(KC_ENTER)
// my mod taps
#define CTL_TAB LCTL_T(KC_TAB)
#define SFT_ESC LSFT_T(KC_ESC)

// Global tab forward and backward
#define TAB_FWD LCTL(KC_TAB)
#define TAB_BCK LCTL(LSFT(KC_TAB))
#define TAB_CLS LCTL(KC_W)
#define WIN_CLS LALT(KC_F4)

// CTRL become parens keys on NAV and NUM layers
#define LCT_PRN KC_LCPO
#define RCT_PRN KC_RCPC

// €
#define KC_EUR ALGR(KC_5)

// Tap Dance declarations
enum {
    Q_,
    V_HASH,
    U_QTE,
    Y_AST,
    I_EQ,
    CMA_SCLN,
    M_CLN,
    H_DOL,
    PLS_MNS,
    LPAR_LBR,
    RPAR_RBR
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [Q_] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LSFT(KC_MINUS)),
    [V_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_NONUS_HASH),
    [U_QTE] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_QUOT),
    [Y_AST] = ACTION_TAP_DANCE_DOUBLE(KC_Y, LSFT(KC_8)),
    [I_EQ] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_EQL),
    [H_DOL] = ACTION_TAP_DANCE_DOUBLE(KC_H, LSFT(KC_4)),
    [M_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_M, LSFT(KC_SCLN)),
    [CMA_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
    [PLS_MNS] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_EQL), KC_MINUS),
    [LPAR_LBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_9)),
    [RPAR_RBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_0))
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDHM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                     ,-----------------------------------------------------------.
      KC_ESC,    TD(Q_),   KC_W,      KC_F,    KC_P,     KC_B,                            KC_J,    KC_L, TD(U_QTE), TD(Y_AST), TD(PLS_MNS), KC_BSPC,
  //|---------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+---------+---------|
      CTL_TAB,    KC_A,    KC_R,      KC_S,    KC_T,     KC_G,                         TD(M_CLN),   KC_N,   KC_E,    TD(I_EQ),   KC_O,  TD(LPAR_LBR),
  //|---------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+---------+---------|
      SFT_ESC,    KC_Z,    KC_X,      KC_C,    KC_D,   TD(V_HASH),                       KC_K,   TD(H_DOL), TD(CMA_SCLN), KC_DOT, KC_SLSH, TD(RPAR_RBR),
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                          KC_LALT,  T_SYM, SFT_SPC,     SFT_ENT,   T_NAV, KC_RGUI
                                      //`---------------------------------'  `-----------------------------'

  ),

  [_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_EUR,  KC_P7,   KC_P8,    KC_P9,  XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_P4,   KC_P5,    KC_P6, KC_PMNS, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK,                      KC_EQL,  KC_P1,   KC_P2,   KC_P3,  KC_PSLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______,   KC_P0, KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_1,   KC_2,     KC_3,     KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,   KC_9,     KC_0,   _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM, KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC,  KC_AMPR, KC_ASTR, KC_UNDS, KC_MINS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCT_PRN, XXXXXXX, XXXXXXX, XXXXXXX, KC_EUR, XXXXXXX,                      KC_EQL, KC_PIPE,    KC_LT, KC_GT,   KC_BSLS,  RCT_PRN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, S_SYM,  _______,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_PGUP,  KC_HOME, KC_UP,   KC_END, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCT_PRN, KC_F11, KC_F12,   KC_INS, KC_PSCR, KC_CAPS,                      WIN_CLS, TAB_BCK, TAB_CLS, TAB_FWD,  XXXXXXX, RCT_PRN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,     KC_ENT, S_NAV, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )

};
