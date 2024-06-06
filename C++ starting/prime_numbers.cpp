#include <iostream>
using namespace std;

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int end_point, count = 0;
    cout << "Enter the endpoint of the sequence: ";
    cin >> end_point;

    for (int i = 2; i <= end_point; ++i) {
        if (is_prime(i)) {
            cout << "Prime number: " << i << endl;
            count++;
        }
    }

    cout << "Total prime numbers: " << count << endl;

    return 0;
}
