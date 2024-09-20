#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

struct Dimensions   {
	int terminalWidth;
	int terminalHeight;
};

int main()  {
	int y;
	int x;

	struct winsize ws;
	ioctl( 0, TIOCGWINSZ, &ws );

	struct Dimensions screen = {ws.ws_col, ws.ws_row};
	char renderScreen[screen.terminalWidth][screen.terminalHeight];

	system("clear");

	for (y = (sizeof(renderScreen) / screen.terminalWidth); y >= 1; y--)	{
		for (x = (sizeof(renderScreen) / screen.terminalHeight); x >= 1; x--)	{
			renderScreen[x - 1][y] = 35;
		};

	};
	
	printf("\033[0;30m");

	for (y = 0;  y != (sizeof(renderScreen) / screen.terminalWidth); y++)	{
		for (x = 0;  x != (sizeof(renderScreen) / screen.terminalHeight); x++)	{
			printf("%c", renderScreen[x][y]);
	
		};
	};

	getchar();
	system("clear");


	return 0;
}

