#include <stdio.h>

int main() 
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    if (x + y <= z || x + z <= y || y + z <= x)
        printf("non-triangle.\n");
    else if (x == y || y == z || x == z)
     {

        if (x == y && y == z)
            printf("equilateral triangle.\n");
        else
            printf("isoceles triangle.\n");
    }
    else
        printf("triangle.\n");
        return 0;

}