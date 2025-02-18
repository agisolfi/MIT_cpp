#include <iostream>
#include "geometry.h"




int main() {
    // Recatngle
    int lower_left_x = 0;
    int lower_left_y = 0;
    int top_right_x = 0;
    int top_right_y = 0;

    std::cout<<"Lower left (X,Y)";
    std::cin>>lower_left_x;
    std::cin>>lower_left_y;

    Point lower_left = Point(lower_left_x,lower_left_y);

    std::cout<<"Top Right (X,Y)";
    std::cin>>top_right_x;
    std::cin>>top_right_y;

    Point top_right = Point(top_right_x,top_right_y);
    Rectangle rect = Rectangle(lower_left,top_right);

    static_cast<Triangle *>(rect);

    dynamic_cast<Triangle *>(rect);

}