#include <iostream>
#include "console.h"

const int movespeed = 15;

int main() {



	console::init();

	// 맵크기
	int height = console::SCREEN_HEIGHT - 2;
	int width = console::SCREEN_WIDTH - 2;

	// 중앙
	int centerx = (height / 2);
	int centery = (width / 2);

	// 맵 
	int centerX = centerx;
	int centerY = centery;


	int start = 0;
	//사과 나타내기
	int applex = rand() % centerX + 1;
	int appley = rand() % centerY + 1;

	int loop = 0;

	int directionX = 0;
	int directionY = 0;

	int score = 0;
	while (true) {

		console::clear();

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
					console::draw(i, j, "s");
				}
				else if (i == centerX && j == centerY) {
					console::draw(i, j, "@"); // 뱀 그리기
				}
				else if (i == applex && j == appley) {
					console::draw(i, j, "o"); // 사과 그리기
				}
			}
		}
		console::wait;

		loop++;
		
		if (centerX <= 0 || centerX >= height - 1 || centerY <= 0 || centerY >= width - 1) {

			std :: cout << "game over" << std::endl;
		}

		if ((directionX == 0 || directionY == 0) && (directionX == directionY)) {
			std::cout << "game over" << std::endl;
		}

		if (centerX == applex && centerY == appley) {

			applex = rand() % centerX + 1;
			appley = rand() % centerY + 1;
		}


		if (loop == movespeed) {
			centerX += directionX;
			centerY += directionY;
		}

		if (console::key(console::K_LEFT) && directionX != 1) {
			directionX = -1;
			directionY = 0;
		}
		else if (console::key(console::K_RIGHT) && directionX != -1) {
			directionX = 1;
			directionY = 0;
		}
		else if (console::key(console::K_DOWN) && directionY != 1) {
			directionX = 0;
			directionY = -1;
		}
		else if (console::key(console::K_UP) && directionY != -1) {
			directionX = 0;
			directionY = 1;
		}

	}




}