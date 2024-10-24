#pragma once
#include "Interactable.hpp"
#include <cmath>

class Obstacle : public Interactable{
    protected:
        InteractableType type;
    public:
        Obstacle(int x, int y, int width, int height){
            this->coordinates = std::make_pair(x, y);
            this->gridWidth = width;
            this->gridHeight = height;
            this->type = OBSTACLE;
        }

        bool interact(Robot* player){
            int x1 = std::get<0>(this->coordinates);
            int y1 = std::get<1>(this->coordinates);
            int x2 = std::get<0>(player->getCoordinates());
            int y2 = std::get<1>(player->getCoordinates());

            int xdist = x2 - x1;
            int ydist = y2 - y1;

            double distance = sqrt(pow(xdist, 2) + pow(ydist, 2));
            
            if (distance == 0){
                player->takeHit(); 
                if (player->getHealth() == 0){
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        InteractableType getType(){
            return OBSTACLE;
        }
};