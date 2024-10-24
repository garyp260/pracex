#pragma once
#include "GridItem.hpp"
#include <utility>

class Robot : public GridItem{
    protected:
        int health;
    public:
        Robot(int gridWidth, int gridHeight){
            this->gridHeight = gridHeight;
            this->gridWidth = gridWidth;
            std::get<0>(coordinates) = 0;
            std::get<1>(coordinates) = 0;
            this->health = 3;
        }

        int getHealth(){
            return health;
        }

        void takeHit(){
            if (health > 0){
                health--;
            }
        }

        bool move(int xOffest, int yOffset){

            int currX = std::get<0>(coordinates);
            int currY = std::get<1>(coordinates);

            if (xOffest > 0 && yOffset > 0){
                return false;
            }

            int newX = currX + xOffest;
            int newY = currY + yOffset;

            if (0 <= newX && newX <= (gridWidth - 1) && 0 <= newY && newY <= (gridHeight - 1)){
                std::get<0>(coordinates) = newX;
                std::get<1>(coordinates) = newY;
                return true;
            } else {
                return false;
            }

        }
};