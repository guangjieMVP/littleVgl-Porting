#include "lvgl.h"
#include "lv_conf.h"
#include "lv_app.h"

void my_disp_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p);
void my_disp_fill(int32_t x1,int32_t y1,int32_t x2,int32_t y2,lv_color_t color);
void my_disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p);

void my_lv_display_init(void)
{
	lv_disp_drv_t disp_drv;               /*Descriptor of a display driver*/
	lv_disp_drv_init(&disp_drv);          /*Basic initialization*/
	disp_drv.disp_flush = my_disp_flush;     /*Set your driver function*/
	disp_drv.disp_fill  = my_disp_fill;
	disp_drv.disp_map   = my_disp_map;
	lv_disp_drv_register(&disp_drv);      /*Finally register the driver*/
}


void my_disp_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
    int32_t x, y;
    for(y = y1; y <= y2; y++) 
		{
        for(x = x1; x <= x2; x++) 
				{
//         sep_pixel(x, y, *color_p);  /* Put a pixel to the display.*/
						LCD_Fast_DrawPoint(x,y,(*color_p).full);
            color_p++;
        }
    }

    lv_flush_ready();                  /* Tell you are ready with the flushing*/
}

void my_disp_fill(int32_t x1,int32_t y1,int32_t x2,int32_t y2,lv_color_t color)
{
	LCD_Color_Fill(x1,y1,x2,y2,(u16 *)&color.full);
}

void my_disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
    /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    int32_t x;
    int32_t y;
    for(y = y1; y <= y2; y++) 
		{
        for(x = x1; x <= x2; x++) 
				{
            /* Put a pixel to the display. For example: */
            /* put_px(x, y, *color_p)*/
						LCD_Fast_DrawPoint(x,y,(*color_p).full);
            color_p++;
        }
    }
}

