#include <iostream>
#include <string>

using namespace std;

class Room{
    public:
        double lenght = 10;
        double height = 3;
        double width = 6;
        Room(){
            cout<<lenght<<endl
                <<height<<endl
                <<width<<endl;
        }
};

int freq_of_elemnt(int elem, int array[], int size){
    int count = 0;
    for(int i = 0; i <size; i++){
        if(array[i] == elem) count++;
    }
    return count;
}

int main(){
    int size;
    cout << "Enter size of an array >> ";
    cin >> size;
    int* array =  new int[size];
    int looked_num;
    for(int i = 0; i < size; i++){
        cout << "Enter element of an array " << i << " >> ";
        cin >> array[i];
    }
    cout << endl;
    cout << "Enter number which amount you want to know >> ";
    cin>> looked_num;
    int freq = freq_of_elemnt(looked_num, array, size);
    cout << "Frequency of the element " << looked_num << " is >> "<< freq << endl;
    delete[] array;
    Room room;
    // cout << room.sq_m() << endl;
    return 0;
}