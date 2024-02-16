#include <stdio.h>
#include <math.h>

int main() {
    int N, M, Y;

    printf("Enter three numbers (N M Y): ");
    scanf("%d %d %d", &N, &M, &Y);

    if (N < -10 || N > 10 || M < -10 || M > 10 || Y < 0 || Y > 10) {
        printf("Invalid input. Please make sure -10 <= N <= 10, -10 <= M <= 10, and 0 <= Y <= 10.\n");
        return 1;
    }

    for (int i = N; i <= M; ++i) {
        printf("%d: ", i);
        for (int j = 0; j <= Y; ++j) {
            printf("%.0f ", pow(i, j));
        }
        printf("\n");
    }

    return 0; 
}
