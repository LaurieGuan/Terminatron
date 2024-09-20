#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

struct Dimensions   {
	int terminalWidth;
	int terminalHeight;
};

int main()  {
	char Example[] = "Exemple";
	int fill;
	int i;

	struct winsize ws;
	ioctl( 0, TIOCGWINSZ, &ws );

	struct Dimensions screen = {ws.ws_row, ws.ws_col};
	fill = ws.ws_row * ws.ws_col;
	
	for (i = ((ws.ws_row / 2) - 1); i != 0; i--)	{
		printf("\n");
	}

	for (i = (ws.ws_col / 2 - (strlen(Example) / 2)); i != 0; i--)	{
		printf(" ");
	}
	printf("%s\n", Example);
	printf("\x01\x01\x01\x01");

	for (i = (ws.ws_col / 2 - 1); i != 0; i--)	{
		printf(" ");
	}

	printf("Test\n");

	return 0;
}

