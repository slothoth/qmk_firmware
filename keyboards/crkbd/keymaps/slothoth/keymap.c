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
#define _NUM 1
#define _SYM 2
#define _GAME 3 

// Layer toggle and switch
#define T_SYM TT(_SYM)
#define T_NUM TT(_NUM)

// Tap/mod keys
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

// Copy Paste Cut Undo Redo
#define MY_CPY LCTL(KC_C)
#define MY_PST LCTL(KC_V)
#define MY_CUT LCTL(KC_X)
#define MY_UNDO LCTL(KC_Z)
#define MY_REDO LCTL(LSFT(KC_Z))

// Tap Dance declarations
enum {
    Q_,
    V_HASH,
    U_QTE,
    Y_AST,
    I_EQ,
    CMA_SCLN,
    J_CLN,
    H_DOL,
    PLS_MNS,
    LBR_RBR,
    LPAR_RPAR,
    TD_KAT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [Q_]        = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_UNDS),
    [V_HASH]    = ACTION_TAP_DANCE_DOUBLE(KC_V, LSFT(KC_TILD)),
    [U_QTE]     = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_QUOT),
    [Y_AST]     = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_ASTR),
    [I_EQ]      = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_EQL),
    [H_DOL]     = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_DLR),
    [J_CLN]     = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_COLN),
    [CMA_SCLN]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
    [PLS_MNS]   = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_MINUS),
    [LBR_RBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [LPAR_RPAR]  = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_KAT]      = ACTION_TAP_DANCE_DOUBLE(KC_K, LSFT(KC_QUOT))

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAKDHM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                     ,-----------------------------------------------------------.
      KC_ESC,    TD(Q_),   KC_W,      KC_F,    KC_P,     KC_B,                         TD(J_CLN),    KC_L, TD(U_QTE), TD(Y_AST), TD(PLS_MNS), KC_BSPC,
  //|---------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+---------+---------|
      SFT_ESC,    KC_A,    KC_R,      KC_S,    KC_T,     KC_G,                           KC_M,     KC_N,     KC_E,   TD(I_EQ),   KC_O,  TD(LPAR_RPAR),
  //|---------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+---------+---------|
      CTL_TAB,    KC_Z,    KC_X,      KC_C,    KC_D,   TD(V_HASH),                    TD(TD_KAT),   TD(H_DOL), TD(CMA_SCLN), KC_DOT, KC_SLSH, TD(LBR_RBR),
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                        OSM(MOD_LALT),   T_NUM,  KC_SPC,       KC_ENT,  T_SYM,  KC_RGUI
                                      //`---------------------------------'  `-----------------------------'

  ),
  
  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, MY_CUT,   KC_P7,   KC_P8,    KC_P9, KC_EUR,                       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, MY_CPY,  KC_P4,   KC_P5,    KC_P6, MY_UNDO,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PMNS, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, MY_PST, KC_P1,   KC_P2,    KC_P3, KC_NLCK,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      TG(_NUM), _______, _______,   _______, _______,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),
  
  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, KC_AMPR, KC_LABK,  MY_UNDO,  KC_RABK, KC_CIRC,                    KC_2,    KC_3,    KC_UP,   KC_9,     KC_0,   _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, MY_CUT, MY_PST, MY_CPY, KC_PERC,                      KC_UNDS,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PIPE, KC_LCBR, MY_REDO, KC_RCBR, KC_PSCR,                      KC_EQL, KC_PIPE,  KC_LT,    KC_GT, KC_BSLS, TG(_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     KC_ENT, _______, TG(_SYM)
                                      //`--------------------------'  `--------------------------'
  ),
    [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                     ,-----------------------------------------------------------.
      KC_ESC,    KC_Q,   KC_W,      KC_E,    KC_R,     KC_T,                              KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_BSPC,
  //|---------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+---------+---------|
      XXXXXXX,    KC_A,    KC_S,      KC_D,    KC_F,     KC_G,                           KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_ASTG,
  //|---------+---------+---------+---------+---------+---------|                     |---------+---------+---------+---------+---------+---------|
      XXXXXXX,    KC_Z,    KC_X,      KC_C,    KC_V,     KC_B,                           KC_N,     KC_M,    KC_COMMA,  KC_DOT, KC_SLSH,  TG(_GAME),
  //|---------+---------+---------+---------+---------+---------+---------|  |---------+---------+---------+---------+---------+---------+---------|
                                        OSM(MOD_LALT),   XXXXXXX,  KC_SPC,      KC_ENT, XXXXXXX,  KC_RGUI
                                      //`---------------------------------'  `-----------------------------' 
  )
}; 