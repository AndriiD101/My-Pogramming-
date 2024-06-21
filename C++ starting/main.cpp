#include <iostream>
#include <string>
#include "house.h"

using namespace std;


int main(){
    House my_house;
    House your_house;
    House another_house(6, 8, "yellow");

    my_house.print_house_data();

    cout << endl;

    my_house.set_num_stories(2);
    my_house.set_num_windows(6);
    my_house.set_color("red");

    your_house.set_num_stories(3);
    your_house.set_num_windows(10);
    your_house.set_color("blue");

    my_house.print_house_data();

    cout << endl;

    your_house.print_house_data();
}

