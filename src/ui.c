#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// EVENTS
lv_obj_t *ui____initial_actions0;

// IMAGES AND IMAGE SETS

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
#error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 0
#error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////

void ui_init(void) {
  lv_disp_t *dispp = lv_disp_get_default();
  lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);
  ui_MainScreen_screen_init();
  ui_SplashScreen_screen_init();
  ui_ConfigScreen_screen_init();
  ui____initial_actions0 = lv_obj_create(NULL);
  lv_disp_load_scr(ui_MainScreen);
}

void ui_destroy(void) {
  ui_MainScreen_screen_destroy();
  ui_SplashScreen_screen_destroy();
  ui_ConfigScreen_screen_destroy();
}

void ui_relocalize(void) {
  ui_MainScreen_screen_relocalize();
  ui_SplashScreen_screen_relocalize();
  ui_ConfigScreen_screen_relocalize();
}
