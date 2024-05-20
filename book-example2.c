/* Displays screen size and draws intersecting lines */
#include <graphics.h>

int main(void)
{
    int bigX; /* largest x-coordinate */
    int bigY; /* largest y-coordinate */

    bigX = getmaxwidth();  /* get largest x-coordinate */
    bigY = getmaxheight(); /* get largest y-coordinate */
    initwindow(bigX, bigY,
               "Full screen window - press a key to close");

    /* Draw intersecting lines */
    /* Draw white line from (0, 0) to (bigX, bigY) */
    line(0, 0, bigX, bigY);
    setcolor(BLUE); /* Change color to blue */
                    /* Draw blue line from (bigX, 0) to (0, bigY) */
    line(bigX, 0, 0, bigY);

    /* Display window size in console */
    printf("Window size is %d X %d", bigX, bigY);

    /* Close screen when ready */
    getch();      /* pause until user presses a key */
    closegraph(); /* close the window */

    return (0);
}
