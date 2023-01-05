#include "boards/HiFive1RevB.h"

HiFive1RevB board = {};

int main(void)
{
	// Init Board
	board.Init();

	board.Write("HiFive1RevB Active\n");
	board.Write("Hi From App\n");

	board.LedRed.Set(true);

	/* For now, just halt */
	for (;;)
		;
}
