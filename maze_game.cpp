#include <iostream>
#include <conio.h> // For _getch() function

using namespace std;

// Function to print the maze
void printMaze(const char maze[][10], int playerX, int playerY) {
    system("cls"); // Clear screen

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerY && j == playerX)
                cout << "P"; // Print player position
            else
                cout << maze[i][j];
        }
        cout << endl;
    }
}

int main() {
    // Define the maze
    const char maze[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int playerX = 1; // Initial player X position
    int playerY = 1; // Initial player Y position

    printMaze(maze, playerX, playerY);

    while (maze[playerY][playerX] != 'G') {
        char move = _getch(); // Read a character without displaying it

        // Move the player based on input
        switch (move) {
            case 'w': // Move up
                if (maze[playerY - 1][playerX] != '#')
                    playerY--;
                break;
            case 's': // Move down
                if (maze[playerY + 1][playerX] != '#')
                    playerY++;
                break;
            case 'a': // Move left
                if (maze[playerY][playerX - 1] != '#')
                    playerX--;
                break;
            case 'd': // Move right
                if (maze[playerY][playerX + 1] != '#')
                    playerX++;
                break;
            default:
                break;
        }

        printMaze(maze, playerX, playerY);
    }

    cout << "Congratulations! You reached the goal!" << endl;
    return 0;
}
