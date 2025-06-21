#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void leftSwipe(lv_event_t *e, int _pspref_current_activity_index);
void rightSwipe(lv_event_t *e, int _pspref_current_activity_index);
void setActivityDone(lv_event_t *e, int _pspref_current_activity_index);
void setActivityUndone(lv_event_t *e, int _pspref_current_activity_index);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
