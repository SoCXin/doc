/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：GUI.c
 * 描述    ：GUI图形驱动
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2016-04-08
 * 硬件连接:					
 * 调试方式：J-Link-OB
********************************************************************************/
#include "GUI.h"
#include "Lcd_Driver.h"
#include "SYSTICK.h"
#include "font.h"
#include "user_config.h"


uint32 g_draw_pic_number = 0xF;

//刷新时间
uint32		g_draw_pic_time = 0;

 /**
  * @file   LCD_BGR2RGB
  * @brief  从ILI93xx读出的数据为GBR格式，而我们写入的时候为RGB格式。通过该函数转换
  * @param  c GBR格式的颜色值
  * @retval RGB格式的颜色值
  */
u16 LCD_BGR2RGB(u16 c)
{
  u16  r,g,b,rgb;   
  b=(c>>0)&0x1f;
  g=(c>>5)&0x3f;
  r=(c>>11)&0x1f;	 
  rgb=(b<<11)+(g<<5)+(r<<0);		 
  return(rgb);
}

 /**
  * @file  Gui_Circle
  * @brief 绘制一个圆，笔宽为1个像素
  * @param 
	*			     X,Y  ：圆心的坐标
	*			     R ：圆的半径
  *          fc:
  * @retval 无
  */
void Gui_Circle(u16 X,u16 Y,u16 R,u16 fc) 
{//Bresenham算法 
    unsigned short  a,b; 
    int c; 
    a=0; 
    b=R; 
    c=3-2*R; 
    while (a<b) 
    { 
        Gui_DrawPoint(X+a,Y+b,fc);     //        7 
        Gui_DrawPoint(X-a,Y+b,fc);     //        6 
        Gui_DrawPoint(X+a,Y-b,fc);     //        2 
        Gui_DrawPoint(X-a,Y-b,fc);     //        3 
        Gui_DrawPoint(X+b,Y+a,fc);     //        8 
        Gui_DrawPoint(X-b,Y+a,fc);     //        5 
        Gui_DrawPoint(X+b,Y-a,fc);     //        1 
        Gui_DrawPoint(X-b,Y-a,fc);     //        4 
        if(c<0) c=c+4*a+6; 
        else 
        { 
            c=c+4*(a-b)+10; 
            b-=1; 
        } 
       a+=1; 
    } 
    if (a==b) 
    { 
			Gui_DrawPoint(X+a,Y+b,fc); 
			Gui_DrawPoint(X+a,Y+b,fc); 
			Gui_DrawPoint(X+a,Y-b,fc); 
			Gui_DrawPoint(X-a,Y-b,fc); 
			Gui_DrawPoint(X+b,Y+a,fc); 
			Gui_DrawPoint(X-b,Y+a,fc); 
			Gui_DrawPoint(X+b,Y-a,fc); 
			Gui_DrawPoint(X-b,Y-a,fc); 
    } 
	
} 
 /**
  * @file  Gui_DrawLine
  * @brief 采用 Bresenham 算法，在2点间画一条直线。
  * @param 
	*					 x0, y0 ：起始点坐标
	*					 x1, y1 ：终止点Y坐标
	*					_ucColor     ：颜色
  * @retval 无
  */
void Gui_DrawLine(u16 x0, u16 y0,u16 x1, u16 y1,u16 Color)   
{
		int dx,         // difference in x's
    dy,             // difference in y's
    dx2,            // dx,dy * 2
    dy2, 
    x_inc,          // amount in pixel space to move during drawing
    y_inc,          // amount in pixel space to move during drawing
    error,          // the discriminant i.e. error i.e. decision variable
    index;          // used for looping	


	Lcd_SetXY(x0,y0);
	dx = x1-x0;//计算x距离
	dy = y1-y0;//计算y距离

	if (dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx    = -dx;  
	} 
	
	if (dy>=0)
	{
		y_inc = 1;
	} 
	else
	{
		y_inc = -1;
		dy    = -dy; 
	} 

	dx2 = dx << 1;
	dy2 = dy << 1;

	if (dx > dy)//x距离大于y距离，那么每个x轴上只有一个点，每个y轴上有若干个点
	{//且线的点数等于x距离，以x轴递增画点
		// initialize error term
		error = dy2 - dx; 

		// draw the line
		for (index=0; index <= dx; index++)//要画的点数不会超过x距离
		{
			//画点
			Gui_DrawPoint(x0,y0,Color);
			
			// test if error has overflowed
			if (error >= 0) //是否需要增加y坐标值
			{
				error-=dx2;

				// move to next line
				y0+=y_inc;//增加y坐标值
			} // end if error overflowed

			// adjust the error term
			error+=dy2;

			// move to the next pixel
			x0+=x_inc;//x坐标值每次画点后都递增1
		} // end for
	} // end if |slope| <= 1
	else//y轴大于x轴，则每个y轴上只有一个点，x轴若干个点
	{//以y轴为递增画点
		// initialize error term
		error = dx2 - dy; 

		// draw the line
		for (index=0; index <= dy; index++)
		{
			// set the pixel
			Gui_DrawPoint(x0,y0,Color);

			// test if error overflowed
			if (error >= 0)
			{
				error-=dy2;

				// move to next line
				x0+=x_inc;
			} // end if error overflowed

			// adjust the error term
			error+=dx2;

			// move to the next pixel
			y0+=y_inc;
		} // end for
	} // end else |slope| > 1
}

 /**
  * @file   Gui_box
  * @brief  
  * @param  
  * @retval 
  */

void Gui_box(u16 x, u16 y, u16 w, u16 h,u16 bc)
{
	Gui_DrawLine(x,y,x+w,y,0xEF7D);
	Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
	Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
	Gui_DrawLine(x,y,x,y+h,0xEF7D);
    Gui_DrawLine(x+1,y+1,x+1+w-2,y+1+h-2,bc);
}
 /**
  * @file   Gui_box2
  * @brief  
  * @param  
  * @retval 
  */
void Gui_box2(u16 x,u16 y,u16 w,u16 h, u8 mode)
{
	if (mode==0)	{
		Gui_DrawLine(x,y,x+w,y,0xEF7D);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
		Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
		Gui_DrawLine(x,y,x,y+h,0xEF7D);
		}
	if (mode==1)	{
		Gui_DrawLine(x,y,x+w,y,0x2965);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xEF7D);
		Gui_DrawLine(x,y+h,x+w,y+h,0xEF7D);
		Gui_DrawLine(x,y,x,y+h,0x2965);
	}
	if (mode==2)	{
		Gui_DrawLine(x,y,x+w,y,0xffff);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xffff);
		Gui_DrawLine(x,y+h,x+w,y+h,0xffff);
		Gui_DrawLine(x,y,x,y+h,0xffff);
	}
}

/**
  * @file   DisplayButtonDown
  * @brief  在屏幕显示一凸起的按钮框
  * @param  u16 x1,y1,x2,y2 按钮框左上角和右下角坐标
  * @retval 
  */
void DisplayButtonDown(u16 x1,u16 y1,u16 x2,u16 y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, GRAY2);  //H
	Gui_DrawLine(x1+1,y1+1,x2,y1+1, GRAY1);  //H
	Gui_DrawLine(x1,  y1,  x1,y2, GRAY2);  //V
	Gui_DrawLine(x1+1,y1+1,x1+1,y2, GRAY1);  //V
	Gui_DrawLine(x1,  y2,  x2,y2, WHITE);  //H
	Gui_DrawLine(x2,  y1,  x2,y2, WHITE);  //V
}

/**
  * @file   DisplayButtonUp
  * @brief  在屏幕显示一凸起的按钮框
  * @param  u16 x1,y1,x2,y2 按钮框左上角和右下角坐标
  * @retval 
  */
void DisplayButtonUp(u16 x1,u16 y1,u16 x2,u16 y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, WHITE); //H
	Gui_DrawLine(x1,  y1,  x1,y2, WHITE); //V
	
	Gui_DrawLine(x1+1,y2-1,x2,y2-1, GRAY1);  //H
	Gui_DrawLine(x1,  y2,  x2,y2, GRAY2);  //H
	Gui_DrawLine(x2-1,y1+1,x2-1,y2, GRAY1);  //V
    Gui_DrawLine(x2  ,y1  ,x2,y2, GRAY2); //V
}

void Gui_DrawFont_PIC(u16 x, u16 y, u16 width, u16 height, u16 fc, u16 bc, u8 *index_s, u8 *buff_s, u16 buff_len)
{
	int i, j;
	u16 color = 0;
	int all_len = width * height;
	int x_len = all_len / 8 + 1;
	int pos = 0;
	u8 *buff_s_pos = buff_s;
	
	if(x >= 128 || y >= 128 || x + width > 128 || y + height > 128)
		return;
	
	//显示编号累加
	g_draw_pic_number++;
	
	//更新刷新时间
	g_draw_pic_time = g_time_now;
	
	//设置显示区域
	Lcd_SetRegion(x, y, x + width - 1, y + height - 1);		//坐标设置
	
	for(i =0; i < x_len; i++)
	{
		for(j=0; j < 8; j++)
		{
			//防止越界
			if(pos >= all_len)
				break;
			pos++;
			
			color = bc;
			if(index_s[i] & (1 << (j % 8)))
			{
				if(buff_s_pos - buff_s < buff_len)
				{
					color = ((fc & BLUE) * *buff_s_pos / 255) |  (((fc & GREEN) >> 5) * *buff_s_pos / 255) << 5 | (((fc & RED) >> 11) * *buff_s_pos / 255) << 11;
					buff_s_pos++;
				}
				else
				{
					color = fc;
				}
			}

			LCD_WriteData_16Bit(color);
		}
	}
}

void Gui_Clear_Rect(u16 x, u16 y, u16 width, u16 height, u16 fc)
{
	int i;
	int all_len = width * height;
	
	Lcd_SetRegion(x, y, x + width - 1, y + height - 1);		//坐标设置
	for(i =0; i < all_len; i++)
		LCD_WriteData_16Bit(fc);
}
