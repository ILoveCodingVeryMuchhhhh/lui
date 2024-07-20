#ifndef LUI_INPUT_BOX_
#define LUI_INPUT_BOX_

#include <iostream>

#include "lui_root.hpp"
#include "lui_window.hpp"
#include "lui_event.hpp"

class Inputbox : public UI_ROOT{
	std::string content;
	int x = 0, y = 0, w = 100, h = 40;
	bool selected = false;
	public:
		virtual void update(){
			setfillcolor(WHITE, buf);
			ege_fillrect(x, y, w, h, buf);
			setcolor(BLACK, buf);
			ege_rectangle(x, y, w, h, buf);
			setfont(20, 0, "¿¬Ìå", buf);
			setbkmode(TRANSPARENT, buf);
			outtextrect(x+5, y+5, w-10, h-10, 
						(selected ? (content+'|') : content).c_str(),
						buf);
			
			if(mousemsg_){
				mouse_msg m = mouse_;
				if(m.is_down() && m.is_left()){
					if(m.x <= w+x && m.x >= x &&
					   m.y <= h+y && m.y >= y){
					   	selected = true;
					}
					else{
						selected = false;
					}
				}
			}
			
			if(keymsg_){
				key_msg k = key_;
				if(selected){
					if(k.key == 8){
						if(content.size() > 0)
							content.erase(content.end()-1);
					}
					else if(k.msg == key_msg_char){
						if(k.key == 13)
							content += "\n";
						else
							content += k.key;
					}
				}
			}
		}
		
		void setx(int x_){
			x = x_;
		}
		
		void sety(int y_){
			y = y_;
		}
		
		void setwh(int w_, int h_){
			w = w_;
			h = h_;
		}
		
		void gettext(std::string &buf){
			buf = content;
		}
		
		void settext(std::string content_){
			content = content_;
		}
};

#endif
