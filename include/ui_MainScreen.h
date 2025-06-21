// SCREEN: ui_MainScreen
#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

extern void ui_MainScreen_screen_init(void);
extern void ui_MainScreen_screen_destroy(void);
extern void ui_MainScreen_screen_relocalize(void);
extern void ui_event_MainScreen(lv_event_t *e);
extern lv_obj_t *ui_MainScreen;
extern lv_obj_t *ui_ActivePicto;
extern lv_obj_t *ui_TopPanel;
extern lv_obj_t *ui_Bolletjes;
extern void ui_event_ButtonCfg(lv_event_t *e);
extern lv_obj_t *ui_ButtonCfg;
extern void ui_event_ButtonDoneUndone(lv_event_t *e);
extern lv_obj_t *ui_ButtonDoneUndone;

// CUSTOM VARIABLES

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
