#include "Robot.hpp"
#include "Goal.hpp"
#include "Obstacle.hpp"
#include "Helper.hpp"
#include <iostream>

int main() {

    int gridWidth = 5;
    int gridHeight = 5;

    Robot player(gridWidth, gridHeight);


    Goal goal(gridWidth, gridHeight);


    Obstacle obstacle1(2, 2, gridWidth, gridHeight);
    Obstacle obstacle2(3, 3, gridWidth, gridHeight);


    std::cout << "Initial Player Health: " << player.getHealth() << std::endl;

    std::cout << "\nMoving player right by 2 units..." << std::endl;
    if (player.move(2, 0)) {
        std::cout << "Player moved to position (" 
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }


    std::cout << "\nMoving player down by 2 units..." << std::endl;
    if (player.move(0, 2)) {
        std::cout << "Player moved to position ("
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }


    if (Helper::euclideanDistance(player.getCoordinates(), obstacle1.getCoordinates()) == 0) {
        std::cout << "Player has encountered an obstacle at position ("
                  << std::get<0>(obstacle1.getCoordinates()) << ", "
                  << std::get<1>(obstacle1.getCoordinates()) << ")" << std::endl;
        bool lost = obstacle1.interact(&player);
        std::cout << "Player Health after interaction: " << player.getHealth() << std::endl;
        if (lost) {
            std::cout << "Player has lost the game due to zero health." << std::endl;
            return 0;
        }
    }


    std::cout << "\nMoving player right by 2 units..." << std::endl;
    if (player.move(2, 0)) {
        std::cout << "Player moved to position ("
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }

    std::cout << "\nMoving player down by 2 units to reach the goal..." << std::endl;
    if (player.move(0, 2)) {
        std::cout << "Player moved to position ("
                  << std::get<0>(player.getCoordinates()) << ", "
                  << std::get<1>(player.getCoordinates()) << ")" << std::endl;
    } else {
        std::cout << "Player move failed." << std::endl;
    }

    if (Helper::euclideanDistance(player.getCoordinates(), goal.getCoordinates()) == 0) {
        std::cout << "Player has reached the goal at position ("
                  << std::get<0>(goal.getCoordinates()) << ", "
                  << std::get<1>(goal.getCoordinates()) << ")" << std::endl;
        bool won = goal.interact(&player);
        if (won) {
            std::cout << "Player has won the game!" << std::endl;
        } else {
            std::cout << "Player has not met the winning condition." << std::endl;
        }
    }

    return 0;
}
