#ifndef HOUSE_H
#define HOUSE_H

#include <string>
using namespace std;

class House{
    public:
        House(int num_stories = 0, int num_window = 0, string color = "None");

        ~House();

        void set_num_stories(int num_stories);

        void set_num_windows(int num_windows);

        void set_color(string color);

        int get_num_stories() const;

        int get_num_windows() const;

        string get_color() const;

        void print_house_data();

    private:
        int num_stories;
        int num_windows;
        string color;
};

#endif