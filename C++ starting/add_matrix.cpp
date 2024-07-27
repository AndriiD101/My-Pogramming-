#include <iostream>

using namespace std;

int main(){
    int matrix1[2][4] = {{1,2,3,4},
                         {1,2,3,4}};
    int matrix2[2][4] = {{1,2,3,4},
                         {1,2,3,4}};
    int final_matrix[2][4];
    for(int row = 0; row < 2; ++row){
        for(int col = 0; col < 4; ++col){
            final_matrix[row][col] = matrix1[row][col]+matrix2[row][col];
        }
    }
    for(int row = 0; row < 2; ++row){
        for(int col = 0; col < 4; ++col){
            cout << final_matrix[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}