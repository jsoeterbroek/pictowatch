#include "ui.h"

lv_obj_t *ui_ConfigScreen = NULL;
// event functions

// build functions

void ui_ConfigScreen_screen_init(void) {
  ui_ConfigScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_ConfigScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags
}

void ui_ConfigScreen_screen_destroy(void) {
  if (ui_ConfigScreen) {
    lv_obj_del(ui_ConfigScreen);
  }

  // NULL screen variables
  ui_ConfigScreen = NULL;
}

void ui_ConfigScreen_screen_relocalize(void) {
  // label widgets on screen
}
