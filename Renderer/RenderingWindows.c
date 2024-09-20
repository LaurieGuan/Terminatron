#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct Dimensions   {
	int terminalWidth;
	int terminalHeight;
};

int main()  {
	CONSOLE_SCREEN_BUFFER_INFO test;

	HANDLE tmpConsole = CreateConsoleScreenBuffer(GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	GetConsoleScreenBufferInfo(tmpConsole, &test);
	CloseHandle(tmpConsole);


	int y;
	int x;

	struct Dimensions screen = {test.dwMaximumWindowSize.X, test.dwMaximumWindowSize.Y};
	char renderScreen[screen.terminalWidth][screen.terminalHeight];
	char (*renderPointer) = &renderScreen;

	system("cls");

	for (y = (sizeof(renderScreen) / screen.terminalWidth); y >= 1; y--)	{
		for (x = (sizeof(renderScreen) / screen.terminalHeight); x >= 1; x--)	{
			renderScreen[x - 1][y - 1] = '\u2588';
		};

	};

	for (y = 0;  y != (sizeof(renderScreen) / screen.terminalWidth); y++)	{
		for (x = 0;  x != (sizeof(renderScreen) / screen.terminalHeight); x++)	{
			printf("%c", renderScreen[x][y]);
	
		};
	};

	getchar();

	system("cls");

	strcpy("Test",renderPointer);

	for (y = 0;  y != (sizeof(renderScreen) / screen.terminalWidth); y++)	{
		for (x = 0;  x != (sizeof(renderScreen) / screen.terminalHeight); x++)	{
			printf("%c", renderScreen[x][y]);
	
		};
	};

	getchar();

	system("cls");

	return 0;
}

