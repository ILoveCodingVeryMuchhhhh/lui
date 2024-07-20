#ifndef LUI_
#define LUI_

#include <vector>

#include "lui_button.hpp"
#include "lui_window.hpp"
#include "lui_root.hpp"
#include "lui_label.hpp"
#include "lui_inputbox.hpp"

std::vector<UI_ROOT*> widgets;

void Add_Widget(UI_ROOT* widget){
	widgets.push_back(widget);
}

void Lui_Main(int fps = 60){
	for(; is_run(); delay_fps(fps)){
		if(mousemsg()){
			mouse_ = getmouse();
			mousemsg_ = 1;
		}
		if(kbmsg()){
			key_ = getkey();
			keymsg_ = 1;
		}
		
		for(auto i : widgets)
			i->update();
			
		putimage(0, 0, buf);
		cleardevice(buf);
		
		keymsg_ = 0;
		mousemsg_ = 0;
	}
	delimage(buf);
    closegraph();
}

#endif
