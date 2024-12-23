#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for usleep
#include <termios.h>
#include <fcntl.h>

// Game area dimensions
#define WIDTH 20
#define HEIGHT 10

char gameArea[HEIGHT][WIDTH];

// Mario's position
int marioX = 1;
int marioY = HEIGHT - 2;

// Function to initialize the game area
void initializeGameArea() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1) {
                gameArea[i][j] = '=';
            } else {
                gameArea[i][j] = ' ';
            }
        }
    }
    gameArea[marioY][marioX] = 'M';
}

// Function to draw the game area
void drawGameArea() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", gameArea[i][j]);
        }
        printf("\n");
    }
}

// Function to update Mario's position
void updateMarioPosition(char input) {
    // Clear Mario's current position
    gameArea[marioY][marioX] = ' ';

    // Update position based on input
    if (input == 'w' && marioY > 0) {
        marioY--;
    } else if (input == 's' && marioY < HEIGHT - 2) {
        marioY++;
    } else if (input == 'a' && marioX > 0) {
        marioX--;
    } else if (input == 'd' && marioX < WIDTH - 1) {
        marioX++;
    }

    // Place Mario at the new position
    gameArea[marioY][marioX] = 'M';
}

// Function to detect if a key has been pressed
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Function to clear the screen
void clearScreen() {
    printf("\e[1;1H\e[2J");
}

int main() {
    char input;

    initializeGameArea();

    while (1) {
        // Clear the screen
        clearScreen();

        // Draw the game area
        drawGameArea();

        // Check if a key has been pressed
        if (kbhit()) {
            input = getchar();
            // Update Mario's position based on input
            updateMarioPosition(input);
        }

        // Slow down the loop
        usleep(100000); // 100 milliseconds
    }

    return 0;
}
