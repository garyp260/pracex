#include "Game.hpp"
#include <iostream>

int main() {

    int gridWidth = 5;
    int gridHeight = 5;


    std::vector<std::pair<int, int>> obstacleCoordinates = {
        {2, 2},
        {3, 1},
        {1, 3}
    };


    Game game(gridWidth, gridHeight, obstacleCoordinates);


    std::cout << "Initial Game State:" << std::endl;
    game.printGrid();


    game.displayState();


    std::cout << "\nMove player down by 1:" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player right by 1:" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player down by 1:" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();


    std::cout << "\nMove player right by 1 (into obstacle at (2,2)):" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();


    std::cout << "Player Health after hitting obstacle: " << game.getPlayerHealth() << std::endl;

    std::cout << "\nMove player down by 1:" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player right by 1:" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player down by 1 (should reach the goal):" << std::endl;
    game.movePlayer(1, 0);
    game.printGrid();
    game.displayState();

    std::cout << "\nMove player right by 1 (should reach the goal):" << std::endl;
    game.movePlayer(0, 1);
    game.printGrid();
    game.displayState();

    if (game.displayState()) {
        std::cout << "Game Over!" << std::endl;
    } else {
        std::cout << "Game is still ongoing." << std::endl;
    }

    return 0;
}
