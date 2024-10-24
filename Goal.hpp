#pragma once
#include "Interactable.hpp"
#include "Helper.hpp"
#include "Robot.hpp"

class Goal : public Interactable{
    protected:
        InteractableType type;
    public:
        Goal(int width, int height){
            this->gridWidth = width;
            this->gridHeight = height;
            this->type = GOAL;
            this->coordinates = std::make_pair(width - 1, height - 1);
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
                return true;
            } else{
                return false;
            }
        }

        InteractableType getType(){
            return GOAL;
        }
};