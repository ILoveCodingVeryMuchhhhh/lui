#ifndef LUI_BUTTON_
#define LUI_BUTTON_

#include "./lui_root.hpp"
#include "./lui_window.hpp"
#include "./lui_event.hpp"

class Button : public UI_ROOT{
	std::string text;
	color_t bkc, fgc;
	int w, h, x = 0, y = 0;
	std::function<void()> callback;
	
	public:
		virtual void update(){
			//draw
			setfillcolor(bkc, buf);
			ege_fillrect(x, y, w, h, buf);
			setcolor(fgc, buf);
			setfont(20, 0, "¿¬Ìå", buf);
			setbkmode(TRANSPARENT, buf);
			outtextxy((w+x)/2-textwidth(text.c_str())/2, 
					 (y+h)/2-textheight(text.c_str())/2,
					 text.c_str(), buf);
			//if click
			if(mousemsg_){
				mouse_msg m = mouse_;
				if(m.is_down() && m.is_left()){
					if(m.x <= w+x && m.x >= x &&
					   m.y <= h+y && m.y >= y){
					   	callback();
					}
				}
			}
		}
		
		void setwh(int w_, int h_){
			w = w_;
			h = h_;
		}
		
		void setxy(int x_, int y_){
			x = x_;
			y = y_;
		}
		
		void setbk(color_t c_){
			bkc = c_;
		}
		
		void setfg(color_t c_){
			fgc = c_;
		}
		
		void if_click(std::function<void()> func){
			callback = func;
		}
		
		void settext(std::string text_){
			text = text_;
		}
};

#endif
