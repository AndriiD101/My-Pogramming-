#include "house.h"
#include <iostream>
using namespace std;

House::House(int num_stories, int num_window, string color){
    this->num_stories = num_stories;
    this->num_windows = num_window;
    this->color = color;
}

House::~House(){
    cout << "The house " << color << " has num windows " << num_windows
         << " and has num stories " << num_stories << " is destroyed." << endl;
}

void House::set_num_stories(int num_stories){
    this->num_stories = num_stories;
}

void House::set_num_windows(int num_windows){
    this->num_windows = num_windows;
}

void House::set_color(string color){
    this->color = color;
}

int House::get_num_stories() const{
    return num_stories;
}

int House::get_num_windows() const{
    return num_windows;
}

string House::get_color() const{
    return color;
}

void House::print_house_data(){
    cout << this->get_color() << endl;
    cout << this->get_num_stories() << endl;
    cout << this->get_num_windows() << endl;
}