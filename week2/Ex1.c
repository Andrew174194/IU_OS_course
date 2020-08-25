//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int i = INT_MAX;
    double d = DBL_MAX;
    float f = FLT_MAX;
    printf("Type\tSize\tMax value\n");
    printf("Integer\t%i\t%i\n", sizeof(int), i);
    printf("Double\t%i\t%d\n", sizeof(double), d);
    printf("Float\t%i\t%f\n", sizeof(float), f);

    return 0;
}
