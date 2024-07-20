#ifndef LUI_LABEL_
#define LUI_LABEL_

#include <iostream>

#include "lui_root.hpp"
#include "lui_window.hpp"

class Text : public UI_ROOT{
	std::string text, font = "¿¬Ìå";
	color_t	fg = WHITE, bk;
	int bkmode = TRANSPARENT;
	int x = 0, y = 0, fontw = 0, fonth = 20;
	public:
		virtual void update(){
			setfont(fonth, fontw, font.c_str(), buf);
			setcolor(fg, buf);
			setfontbkcolor(bk, buf);
			setbkmode(bkmode, buf);
			outtextxy(x, y, text.c_str(), buf);
		}
		
		void setx(int x_){
			x = x_;
		}
		
		void sety(int y_){
			y = y_;
		}
		
		void settext(std::string text_){
			text = text_;
		}
		
		void set_font(int fontw_, int fonth_, std::string fontname){
			font = fontname;
			fontw = fontw_;
			fonth = fonth_;
		}
		
		void setfg(color_t fg_){
			fg = fg_;
		}
		
		void setbk(color_t bk_, int bkmode_ = TRANSPARENT){
			bk = bk_;
			bkmode = bkmode_;
		}
};

class Photos : public UI_ROOT{
	std::string path;
	PIMAGE p;
	int x = 0, y = 0, h, w;
	public:
		virtual void update(){
			//putimage(x, y, w, h, )
		}
		
		void setw(int w_){
			w = w_;
		}
		
		void seth(int h_){
			h = h_;
		}
		
		void setx(int x_){
			x = x_;
		}
		
		void sety(int y_){
			y = y_;
		}
};

#endif
