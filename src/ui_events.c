#ifdef __cplusplus
extern "C" {
#include "PSpref.h"
#endif
#include "ui.h"

// Declare if defined elsewhere
extern int pspref_current_activity_index;

void leftSwipe(lv_event_t *e) {
  incr_pspref_current_activity_index(pspref_current_activity_index);
}

void rightSwipe(lv_event_t *e) {
  decr_pspref_current_activity_index(pspref_current_activity_index);
}

void setActivityDone(lv_event_t *e) {
  set_pspref_activity_done(pspref_current_activity_index);
}

void setActivityUndone(lv_event_t *e) {
  set_pspref_activity_undone(pspref_current_activity_index);
}
#ifdef __cplusplus
} /*extern "C"*/
#endif
