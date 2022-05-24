#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y)
{
    y=0;
    if (x >= 0)
    {
        y = x;
    }
    else
    {
        y = (-x);
    }
    
}

int main(void)
{

    int a, res;
    res = 0;
    a = -98;
    absolute(a, res);
    printf("res:=%d\n", res);

    return EXIT_SUCCESS; // r := 0
}