#pragma once
#include <cmath>
#include <utility>

class Helper{
    public:
        static double euclideanDistance(std::pair<int, int> item1, std::pair<int, int> item2){
            int x1 = std::get<0>(item1);
            int y1 = std::get<1>(item1);
            int x2 = std::get<0>(item2);
            int y2 = std::get<1>(item2);

            int xdist = x2 - x1;
            int ydist = y2 - y1;

            double distance = sqrt(pow(xdist, 2) + pow(ydist, 2));
            return distance;
        }

};