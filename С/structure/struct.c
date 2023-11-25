#include <stdio.h>
#include <stdlib.h>


struct point {

    int x;
    int y;
};

int main()
{
    struct point p1;
    printf("enter x coordinate: ");
    scanf("%d", &p1.x);
    printf("enter y coordinate: ");
    scanf("%d", &p1.y);

    printf("(%d, %d)\n", p1.x, p1.y);
    return 0;
}