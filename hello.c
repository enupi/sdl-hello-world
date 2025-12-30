#include "draw.h"
#include <stdio.h>
#include <switch.h>

int main()
{
	// initialize and get graphics context
	Graphics* g = init();// 画面のセットアップ

	// draw hello world string
	drawString(g, "Hello world!", 2, 1);
	drawColorString(g, 2, 3, "Hello, Np", 255, 0, 0);

	// wait 10s
	sleep(10);
  
	// clean up graphics
	deinit(g);

	return 0;
}
