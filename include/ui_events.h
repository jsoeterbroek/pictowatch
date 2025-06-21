#ifndef _UI_EVENTS_H
#define _UI_EVENTS_H

#ifdef __cplusplus
extern "C" {
#endif

void leftSwipe(lv_event_t *e);
void rightSwipe(lv_event_t *e);
void setActivityDone(lv_event_t *e);
void setActivityUndone(lv_event_t *e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
