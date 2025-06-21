#ifndef UI_CONFIGSCREEN_H
#define UI_CONFIGSCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

// SCREEN: ui_ConfigScreen
extern void ui_ConfigScreen_screen_init(void);
extern void ui_ConfigScreen_screen_destroy(void);
extern void ui_ConfigScreen_screen_relocalize(void);
extern lv_obj_t *ui_ConfigScreen;
// CUSTOM VARIABLES

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
