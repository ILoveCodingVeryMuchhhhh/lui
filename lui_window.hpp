#ifndef LUI_WINDOW_
#define LUI_WINDOW_

#include <graphics.h>

PIMAGE buf;

void Lui_Init(int w, int h){ 
	initgraph(w, h);
	buf = newimage(w, h);
}

#endif
