#ifdef __cplusplus
extern "C" {
#include "PSpref.h"
#endif
#include "ui.h"

// Declare if defined elsewhere
//extern int pspref_current_activity_index;

void leftSwipe(lv_event_t *e, int _pspref_current_activity_index) {
  incr_pspref_current_activity_index(_pspref_current_activity_index);
}

void rightSwipe(lv_event_t *e, int _pspref_current_activity_index) {
  decr_pspref_current_activity_index(_pspref_current_activity_index);
}

void setActivityDone(lv_event_t *e, int _pspref_current_activity_index) {
  set_pspref_activity_done(_pspref_current_activity_index);
}

void setActivityUndone(lv_event_t *e, int _pspref_current_activity_index) {
  set_pspref_activity_undone(_pspref_current_activity_index);
}

void btnActivityClicked(lv_event_t *e, int _pspref_current_activity_index) {
  // Your code here
}

#ifdef __cplusplus
} /*extern "C"*/
#endif
