#include <iostream>

using namespace std;

int GCD(int x, int y){
    if(x%y == 0){
        return y;
    } else {
        return GCD(y, x%y);
    }
}

int exp(int x, int y){
    if(y ==0)
        return 1;
    return x * exp(x, y-1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    return 0;
}
