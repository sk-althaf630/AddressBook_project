#include <stdio.h>

#include "ifndef.h"
int main()
{
    mom s1 = {45,"manie", "nellore"};
    printf("%d %s %s\n", s1.id, s1.name, s1.address);
    return 0;
}