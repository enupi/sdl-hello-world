#include "draw.h"
#include <stdio.h>
#include <switch.h>
#include <string.h>

int main()
{
	// initialize and get graphics context
	Graphics* g = init();// 画面のセットアップ

	// draw hello world string
	drawString(g, "Hello, world!", 0, 1);
	drawColorString(g, 0, 3, "This is Nintendo Switch", 255, 0, 0);
	drawColorString(g, 0, 5, "You can write", 0, 255, 0);

	char colorful_string[] = "Colorful Text!";
	int colorful_string_len = strlen(colorful_string);
	int diff = (350 - 5) / colorful_string_len; // グラデーションの差分

	for (int i = 0; colorful_string[i] != '\0'; i++){

		float hsv[3];
		hsv[0] = 5 + i * diff; // Hue
		hsv[1] = 85; // Saturation
		hsv[2] = 92; // Value

		HSVtoRGB(hsv);
		drawColorString(g, 14 + i, 5, &colorful_string[i], (int)hsv[0], (int)hsv[1], (int)hsv[2]);
	}


	// wait 10s
	sleep(10);
  
	// clean up graphics
	deinit(g);

	return 0;
}
