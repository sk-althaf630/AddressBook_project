//to print date using predefined macros
#include<stdio.h>
int main()
{
    printf("%s\n", _DATE_);
}

//to print time using predefined macros
#include<stdio.h>
int main()
{
    printf("%s\n", _TIME_);
}

//to print file name using predefined macros
#include<stdio.h>
int main()
{
    printf("%s\n", _FILE_);
}

//to print lines using predefined macros
#include<stdio.h>
int main()
{
    printf("%d\n", _LINE_);
}

//check ANSI standard program or not
#include<stdio.h>
int main()
{
    printf("%d\n", _STDC_);
}