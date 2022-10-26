#include <Windows.h>
#include <random>
#include <iostream>

/*
	Roblox Auto Clicker
	Author: TSJ_Electronics & WSJ
	My son wanted to cheat in roblox so we made this together.
	A viewer asked for code so posted on github.
*/

int getRand(int min, int max) {// generate a random number in a given range.
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(min, max);
	auto output = uni(rng);
	return output;
}

int main() {
	bool click = false;
	POINT p;
	int sleepMin = 32;
	int sleepMax = 65;
	int clickDeviation = 5; // deviate by + or minus 5 pixels each click, to try and appear somewhat human.

	while (1 == 1) {// infinite loop, you can add a close or exit condition if desired
		if (GetAsyncKeyState('Z') & 0x8000) {
			click = true;
			GetPhysicalCursorPos(&p);
			std::cout << "Start Clicking\n";
			Sleep(300);
		}

		if (GetAsyncKeyState('X') & 0x8000) {
			click = false;
			std::cout << "Stop Clicking\n";
			Sleep(300);
		}

		if (click) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, p.x + getRand(-clickDeviation, clickDeviation), p.y + getRand(-clickDeviation, clickDeviation)), 0, 0);
			Sleep(getRand(sleepMin, sleepMax));
			mouse_event(MOUSEEVENTF_LEFTUP, p.x + getRand(-clickDeviation, clickDeviation), p.y + getRand(-clickDeviation, clickDeviation), 0, 0);
			std::cout << "clicked!\n";
			Sleep(getRand(sleepMin, sleepMax));
		}
	}
}

