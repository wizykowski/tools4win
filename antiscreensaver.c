#include <windows.h>
#include <stdio.h>

int main() {
	printf("This program prevents your screensaver from being activated.\n");
	printf("If you close this window, screensaver will not be blocked anymore.\n");

	while (1) {
		INPUT input[1];

		input[0].type = INPUT_MOUSE;
		input[0].mi.dx = 0;
		input[0].mi.dy = 0;
		input[0].mi.mouseData = 0;
		input[0].mi.dwFlags = MOUSEEVENTF_MOVE;
		input[0].mi.time = 0;
		input[0].mi.dwExtraInfo = (ULONG_PTR) NULL;

		SendInput(1, input, sizeof(input));

		Sleep(60000); // wait one minute
	}
}
