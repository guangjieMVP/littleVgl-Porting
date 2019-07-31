#ifndef _LV_APP_H_
#define _LV_APP_H_

#include "sys.h"
#include "lcd.h"

extern void my_lv_display_init(void);
extern void my_lv_touchpad_init(void);

extern u8 iSTouchFlag;
extern int16_t touchpad_x;
extern int16_t touchpad_y;

#endif

