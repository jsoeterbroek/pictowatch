#include "ui.h"

lv_obj_t *ui_MainScreen = NULL;
lv_obj_t *ui_ActivePicto = NULL;
lv_obj_t *ui_TopPanel = NULL;
lv_obj_t *ui_Bolletjes = NULL;
lv_obj_t *ui_ButtonCfg = NULL;
lv_obj_t *ui_ButtonDoneUndone = NULL;

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

// void ui_event_ButtonCfg(lv_event_t *e) {
//   lv_event_code_t event_code = lv_event_get_code(e);

//   if (event_code == LV_EVENT_CLICKED) {
//     _ui_screen_change(&ui_ConfigScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, &ui_ConfigScreen_screen_init);
//   }
// }

// void ui_event_ButtonDoneUndone(lv_event_t *e) {
//   lv_event_code_t event_code = lv_event_get_code(e);
//   int _pspref_current_activity_index = 0;
//   _pspref_current_activity_index = get_pspref_current_activity_index();

//   if (event_code == LV_EVENT_CLICKED) {
//     btnActivityClicked(e, _pspref_current_activity_index);
//   }
// }

// build functions
void ui_MainScreen_screen_init(void) {

  ui_MainScreen = lv_obj_create(NULL);
  lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_ActivePicto = lv_img_create(ui_MainScreen);
  lv_obj_set_width(ui_ActivePicto, 140);
  lv_obj_set_height(ui_ActivePicto, 140);
  lv_obj_set_x(ui_ActivePicto, 21);
  lv_obj_set_y(ui_ActivePicto, -3);
  lv_obj_set_align(ui_ActivePicto, LV_ALIGN_LEFT_MID);
  lv_obj_add_flag(ui_ActivePicto, LV_OBJ_FLAG_ADV_HITTEST);   /// Flags
  lv_obj_clear_flag(ui_ActivePicto, LV_OBJ_FLAG_SCROLLABLE);  /// Flags

  ui_TopPanel = lv_obj_create(ui_MainScreen);
  lv_obj_set_width(ui_TopPanel, 250);
  lv_obj_set_height(ui_TopPanel, 34);
  lv_obj_set_x(ui_TopPanel, 0);
  lv_obj_set_y(ui_TopPanel, -2);
  lv_obj_set_align(ui_TopPanel, LV_ALIGN_TOP_MID);
  lv_obj_clear_flag(
    ui_TopPanel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN
  );  /// Flags
  lv_obj_set_scrollbar_mode(ui_TopPanel, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_style_bg_color(ui_TopPanel, lv_color_hex(0x2095F6), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_TopPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_left(ui_TopPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_TopPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_TopPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_TopPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_color(ui_TopPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_text_opa(ui_TopPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_Bolletjes = lv_obj_create(ui_MainScreen);
  lv_obj_remove_style_all(ui_Bolletjes);
  lv_obj_set_width(ui_Bolletjes, 250);
  lv_obj_set_height(ui_Bolletjes, 32);
  lv_obj_set_align(ui_Bolletjes, LV_ALIGN_BOTTOM_MID);
  lv_obj_add_flag(ui_Bolletjes, LV_OBJ_FLAG_HIDDEN);                                /// Flags
  lv_obj_clear_flag(ui_Bolletjes, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);  /// Flags
  lv_obj_set_style_bg_color(ui_Bolletjes, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_Bolletjes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_Bolletjes, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_Bolletjes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_outline_color(ui_Bolletjes, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_outline_opa(ui_Bolletjes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_color(ui_Bolletjes, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_shadow_opa(ui_Bolletjes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

  // ui_ButtonCfg = lv_btn_create(ui_MainScreen);
  // lv_obj_set_width(ui_ButtonCfg, 46);
  // lv_obj_set_height(ui_ButtonCfg, 50);
  // lv_obj_set_x(ui_ButtonCfg, 89);
  // lv_obj_set_y(ui_ButtonCfg, -40);
  // lv_obj_set_align(ui_ButtonCfg, LV_ALIGN_CENTER);
  // lv_obj_add_flag(ui_ButtonCfg, LV_OBJ_FLAG_SCROLL_ON_FOCUS);  /// Flags
  // lv_obj_clear_flag(ui_ButtonCfg, LV_OBJ_FLAG_SCROLLABLE);     /// Flags

  // ui_ButtonDoneUndone = lv_btn_create(ui_MainScreen);
  // lv_obj_set_width(ui_ButtonDoneUndone, 46);
  // lv_obj_set_height(ui_ButtonDoneUndone, 50);
  // lv_obj_set_x(ui_ButtonDoneUndone, 89);
  // lv_obj_set_y(ui_ButtonDoneUndone, 27);
  // lv_obj_set_align(ui_ButtonDoneUndone, LV_ALIGN_CENTER);
  // lv_obj_add_flag(ui_ButtonDoneUndone, LV_OBJ_FLAG_SCROLL_ON_FOCUS);  /// Flags
  // lv_obj_clear_flag(ui_ButtonDoneUndone, LV_OBJ_FLAG_SCROLLABLE);     /// Flags

  // lv_obj_add_event_cb(ui_ButtonCfg, ui_event_ButtonCfg, LV_EVENT_ALL, NULL);
  // lv_obj_add_event_cb(ui_ButtonDoneUndone, ui_event_ButtonDoneUndone, LV_EVENT_ALL, NULL);
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
  // ui_ButtonCfg = NULL;
  // ui_ButtonDoneUndone = NULL;
}

void ui_MainScreen_screen_relocalize(void) {
  // label widgets on screen
}
