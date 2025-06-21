#ifndef UI_SPLASHSCREEN_H
#define UI_SPLASHSCREEN_H

#ifdef __cplusplus
extern "C" {
#endif

// SCREEN: ui_SplashScreen
extern void ui_SplashScreen_screen_init(void);
extern void ui_SplashScreen_screen_destroy(void);
extern void ui_SplashScreen_screen_relocalize(void);
extern lv_obj_t *ui_SplashScreen;
extern lv_obj_t *ui_TextArea1;
// CUSTOM VARIABLES

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
