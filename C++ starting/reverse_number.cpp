#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //234 -> 432
    cout << "Enter positive number: ";
    int input_number;
    cin >> input_number;
    cout << "Your number is: " << input_number <<endl;
    int result = 0;
    int count_digits = 0;
    int copy_input_number = input_number;
    int digit;

    while(copy_input_number%10 != 0){
        count_digits++;
        copy_input_number /= 10;
    }
    cout << "Count digits: "<< count_digits << endl;

    while(input_number%10 != 0){
        digit = input_number % 10;
        // cout << digit << endl;
        result = result * 10 + digit;
        input_number /= 10;
    }
    cout <<"Reversed number is: " << result << endl;
    return 0;
}