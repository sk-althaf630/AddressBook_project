#include <stdio.h>
/*enum color
{
    red,
    green,
    blue,
    yellow
};

int main()
{
    enum color var;
    printf("%lu %lu\n", sizeof(enum color), sizeof(var));
    return 0;
}*/

/*enum color
{
    red,
    green,
    blue,
    yellow,
    pink,
    violot
};

int main()
{
    //enum colot var;
    //printf("%lu %lu\n", sizeof(enum color), sizeof(var));
    printf("red = %d\n", red);
    printf("green = %d\n", green);
    printf("blue = %d\n", yellow);
    printf("pink = %d\n", pink);

}*/

/*#define  FAILURE 0
#define  SUCCESS 1
int greater(int num)
{
    if(num>5)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}
int main()
{
    if(greater(7))
    {
        printf("greater than 5\n");
    }
    else
    {
        printf("lesser than 5\n");
    }

}*/

typedef enum stuent
{
    a_failed,
    b_failed
}str;
str greater(int num)
{
    if(num>5)
    {
        return b_failed;
    }
    else
    {
        return a_failed;
    }
}
int main()
{
    if(greater(7))
    {
        printf("greater than 5\n");
    }
    else
    {
        printf("lesser than 5\n");
    }

}