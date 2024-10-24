#pragma once
#include "GridItem.hpp"
#include "Helper.hpp"
#include "Interactable.hpp"
#include "Robot.hpp"
#include "Goal.hpp"
#include "Obstacle.hpp"
#include <utility>
#include <vector>
#include <iostream>

class Game{
    protected:
        enum GameState{
            PLAYING,
            WIN,
            LOSE
        };
        int width;
        int height;
        Robot* player;
        Goal* goal;
        std::vector<Obstacle*> obstacles;
        GameState state;
    public:
        Game(int width, int height, std::vector<std::pair<int, int>> obstacleCoordinates){
            this->width = width;
            this->height = height;
            
            player = new Robot(width, height);
            goal = new Goal(width, height);

            for (int i = 0; i < obstacleCoordinates.size(); i++){
                int tempX = std::get<0>(obstacleCoordinates[i]);
                int tempY = std::get<1>(obstacleCoordinates[i]);

                if (tempX != 0 && tempY != 0){
                    if (tempX != (width - 1) && tempY != (height -1)){\
                        Obstacle* newObstacle = new Obstacle(tempX, tempY, width, height);
                        obstacles.push_back(newObstacle);
                    }
                }
            }

            this->state = PLAYING;
        }

        bool displayState(){
            switch(state){
                case WIN:
                    std::cout << "You win!" << std::endl;
                    return true;
                case LOSE:
                    std::cout << "You lose!" << std::endl;
                    return true;
                case PLAYING:
                    std::cout << "Game on" << std::endl;
                    return false;
            }
        }

        void movePlayer(int dx, int dy){
            if (state != PLAYING) {
                return;
            }

            bool moved = player->move(dx, dy);

            if (moved) {

                for (int i = 0; i < obstacles.size(); ++i) {
                    Obstacle* obstacle = obstacles[i];


                    if (Helper::euclideanDistance(player->getCoordinates(), obstacle->getCoordinates()) == 0) {

                        bool lost = obstacle->interact(player);
                        if (lost) {
                            state = LOSE;
                            return;
                        }
                    }
                }


                if (Helper::euclideanDistance(player->getCoordinates(), goal->getCoordinates()) == 0) {
                    state = WIN;
                }
            }
        }

        void printGrid(){
            for (int i = 0; i < width; i++){
                for (int j = 0; j < height; j++){


                    int playerX = std::get<0>(player->getCoordinates());
                    int playerY = std::get<1>(player->getCoordinates());

                    if (i == (width - 1) && j == (height - 1)){
                        std::cout<< "G";
                    } else if (i == playerX && j == playerY){
                        std::cout<< "P";
                    } else {
                        bool isObstacle = false;
                        for (int k = 0; k < obstacles.size(); k++){
                            int tempX = std::get<0>(obstacles[k]->getCoordinates());
                            int tempY = std::get<1>(obstacles[k]->getCoordinates());

                            if (i == tempX && j == tempY){
                                std::cout<< "O";
                                isObstacle = true;
                                break;
                            }
                        }

                        if (isObstacle == false){
                            std::cout<< "_";
                        }

                    }

                }
                std::cout << std::endl;
            }
        }

        int getPlayerHealth() {
            return player->getHealth();
        }

        ~Game() {
            delete player;
            delete goal;
            for (auto obstacle : obstacles) {
                delete obstacle;
            }
        }
};