#pragma once
#include "GridItem.hpp"
#include "Robot.hpp"
#include <utility>

class Interactable : public GridItem{
    public:
        enum InteractableType{
            GOAL,
            OBSTACLE
        };

        Interactable(int x, int y, int width, int height){
            this->gridWidth = width;
            this->gridHeight = height;
            this->coordinates = std::make_pair(x, y);
        }

        Interactable(){
            this->gridWidth = 0;
            this->gridHeight = 0;
            this->coordinates = std::make_pair(0, 0);
        }

        virtual bool interact(Robot* player) = 0;

        virtual InteractableType getType() = 0;

        int getActiveInteractableCount(){
            return activeGridItemCount;
        }

        ~Interactable(){
            activeGridItemCount--;
        }

};