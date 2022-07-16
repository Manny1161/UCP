#include <stdio.h>
#include <stdlib.h>
#include "random.h"
int main()
{
    initRandom();
    int num1 = random_(0, 10);
    int num2 = random_(0, 10);
    printf("%d, %d", num1, num2);
    return 0;
}