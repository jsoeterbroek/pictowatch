#include "ui.h"

lv_obj_t *ui_SplashScreen = NULL;
lv_obj_t *ui_TextArea1 = NULL;
// event functions

// build functions

void ui_SplashScreen_screen_init(void) {
  ui_SplashScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_SplashScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_TextArea1 = lv_textarea_create(ui_SplashScreen);
  lv_obj_set_width(ui_TextArea1, 188);
  lv_obj_set_height(ui_TextArea1, 154);
  lv_obj_set_align(ui_TextArea1, LV_ALIGN_CENTER);
  lv_textarea_set_text(ui_TextArea1, "PictoWatch\nVersion 1.0.0\nPrototype");
  lv_textarea_set_placeholder_text(ui_TextArea1, "Placeholder...");
}

void ui_SplashScreen_screen_destroy(void) {
  if (ui_SplashScreen) {
    lv_obj_del(ui_SplashScreen);
  }

  // NULL screen variables
  ui_SplashScreen = NULL;
  ui_TextArea1 = NULL;
}

void ui_SplashScreen_screen_relocalize(void) {
  // label widgets on screen
}
