#include "ui.h"

lv_obj_t *ui_MainScreen = NULL;
lv_obj_t *ui_ActivePicto = NULL;
lv_obj_t *ui_TopPanel = NULL;
lv_obj_t *ui_Bolletjes = NULL;

// event functions
void ui_event_MainScreen(lv_event_t *e) {
  lv_event_code_t event_code = lv_event_get_code(e);
  int _pspref_current_activity_index = 0;
  _pspref_current_activity_index = get_pspref_current_activity_index();

  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
    lv_indev_wait_release(lv_indev_get_act());
    leftSwipe(e, _pspref_current_activity_index);
  }
  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
    lv_indev_wait_release(lv_indev_get_act());
    rightSwipe(e, _pspref_current_activity_index);
  }
  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
    lv_indev_wait_release(lv_indev_get_act());
    setActivityDone(e, _pspref_current_activity_index);
  }
  if (event_code == LV_EVENT_GESTURE && lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
    lv_indev_wait_release(lv_indev_get_act());
    setActivityUndone(e, _pspref_current_activity_index);
  }
}

// build functions
void ui_MainScreen_screen_init(void) {
  ui_MainScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_ActivePicto = lv_img_create(ui_MainScreen);
  lv_obj_set_width(ui_ActivePicto, 140);
  lv_obj_set_height(ui_ActivePicto, 140);
  lv_obj_set_x(ui_ActivePicto, 0);
  lv_obj_set_y(ui_ActivePicto, -6);
  lv_obj_set_align(ui_ActivePicto, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_ActivePicto, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_ActivePicto, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_TopPanel = lv_obj_create(ui_MainScreen);
  lv_obj_set_width(ui_TopPanel, 230);
  lv_obj_set_height(ui_TopPanel, 30);
  lv_obj_set_x(ui_TopPanel, 0);
  lv_obj_set_y(ui_TopPanel, -102);
  lv_obj_set_align(ui_TopPanel, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_TopPanel, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_Bolletjes = lv_obj_create(ui_MainScreen);
  //lv_obj_remove_style_all(ui_Bolletjes);
  lv_obj_set_width(ui_Bolletjes, 214);
  lv_obj_set_height(ui_Bolletjes, 28);
  lv_obj_set_x(ui_Bolletjes, -2);
  lv_obj_set_y(ui_Bolletjes, 95);
  lv_obj_set_align(ui_Bolletjes, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_Bolletjes, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  lv_obj_add_event_cb(ui_MainScreen, ui_event_MainScreen, LV_EVENT_ALL, NULL);
}

void ui_MainScreen_screen_destroy(void) {
  if (ui_MainScreen) {
    lv_obj_del(ui_MainScreen);
  }

  // NULL screen variables
  ui_MainScreen = NULL;
  ui_ActivePicto = NULL;
  ui_TopPanel = NULL;
  ui_Bolletjes = NULL;
}

void ui_MainScreen_screen_relocalize(void) {
  // label widgets on screen
}
