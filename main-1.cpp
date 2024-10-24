#include "GridItem.hpp"
#include "Helper.hpp"
#include <iostream>

int main() {

    std::cout << "Testing GridItem class..." << std::endl;


    GridItem item1(2, 3, 10, 10);
    std::cout << "Item 1 Coordinates: (" << std::get<0>(item1.getCoordinates()) << ", " << std::get<1>(item1.getCoordinates()) << ")" << std::endl;
    std::cout << "Item 1 Grid Size: Width = " << item1.getGridWidth() << ", Height = " << item1.getGridHeight() << std::endl;


    std::cout << "Active GridItem Count: " << item1.getActiveGridItemCount() << std::endl;


    GridItem item2(5, 7, 20, 20);
    std::cout << "Item 2 Coordinates: (" << std::get<0>(item2.getCoordinates()) << ", " << std::get<1>(item2.getCoordinates()) << ")" << std::endl;
    std::cout << "Item 2 Grid Size: Width = " << item2.getGridWidth() << ", Height = " << item2.getGridHeight() << std::endl;


    std::cout << "Active GridItem Count: " << item2.getActiveGridItemCount() << std::endl;


    std::cout << "\nTesting Helper class (Euclidean distance calculation)..." << std::endl;


    std::pair<int, int> point1 = item1.getCoordinates();
    std::pair<int, int> point2 = item2.getCoordinates();

    double distance = Helper::euclideanDistance(point1, point2);
    std::cout << "Distance between Item 1 and Item 2: " << distance << std::endl;


    std::cout << "\nDestroying item2..." << std::endl;
    item2.~GridItem();
    std::cout << "Active GridItem Count: " << item1.getActiveGridItemCount() << std::endl;

    return 0;
}