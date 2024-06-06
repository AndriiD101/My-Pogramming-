#include <iostream>

using namespace std;

void plus_five(int* x){
    *x += 5;
}

int main(){
    int num;
    cout<<"Enter number >> ";
    cin >> num;
    plus_five(&num);
    cout<<"Number >> "<< num<<endl;
    return 0;
}