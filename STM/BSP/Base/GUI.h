#ifndef _GUI_H
#define _GUI_H




#include "stm32f10x.h"
#include "Types.h"

//记录显示的图片编号
extern uint32		g_draw_pic_number;

//最后显示时间
extern uint32		g_draw_pic_time;

u16 LCD_BGR2RGB(u16 c);
void Gui_Circle(u16 X,u16 Y,u16 R,u16 fc); 
void Gui_DrawLine(u16 x0, u16 y0,u16 x1, u16 y1,u16 Color);  
void Gui_box(u16 x, u16 y, u16 w, u16 h,u16 bc);
void Gui_box2(u16 x,u16 y,u16 w,u16 h, u8 mode);
void DisplayButtonDown(u16 x1,u16 y1,u16 x2,u16 y2);
void DisplayButtonUp(u16 x1,u16 y1,u16 x2,u16 y2);


void Gui_DrawFont_PIC(u16 x, u16 y, u16 width, u16 height, u16 fc, u16 bc, u8 *index_s, u8 *buff_s, u16 buff_len);
void Gui_Clear_Rect(u16 x, u16 y, u16 width, u16 height, u16 fc);

#endif















