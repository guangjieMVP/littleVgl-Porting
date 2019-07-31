#include "lvgl.h"
#include "lv_conf.h"
#include "lv_app.h"

u8 iSTouchFlag = 0;
int16_t touchpad_x = -1;
int16_t touchpad_y = -1;

bool my_input_read(lv_indev_data_t*data);

void my_lv_touchpad_init(void)
{
	lv_indev_drv_t indev_drv;                       /*Descriptor of an input device driver*/
	lv_indev_drv_init(&indev_drv);                  /*Basic initialization*/
	indev_drv.type = LV_INDEV_TYPE_POINTER;         /*The touchpad is pointer type device*/
	indev_drv.read = my_input_read;                 /*Library ready your touchpad via this function*/
	lv_indev_drv_register(&indev_drv);              /*Finally register the driver*/
}

bool my_input_read(lv_indev_data_t*data)
{
    static lv_coord_t last_x = 0;
    static lv_coord_t last_y = 0;
		
		if(iSTouchFlag)     //触摸屏按下
		{
			iSTouchFlag = 0;
			data->state = LV_INDEV_STATE_PR;
			data->point.x = touchpad_x;
			data->point.y = touchpad_y;
		}
		else         //没有按下
		{
			last_x = data->point.x;
			last_y = data->point.y; 
			data->state = LV_INDEV_STATE_REL;
		}

    return false; /*Return `false` because we are not buffering and no more data to read*/
}

