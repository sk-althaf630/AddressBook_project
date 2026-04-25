#include <stdio.h>

typedef union Test
{
    char option;
    int id;
    double height;
}un;

int main()
{
    un temp_var;
    printf("%lu %lu\n",sizeof(un),sizeof(temp_var));
    printf("%p %p %p %p\n", &temp_var, &temp_var.option, &temp_var.height, &temp_var.id);

    temp_var.height = 7.2;
    printf("\n<----------------->\n");
    printf("%lf\n", temp_var.height);
    printf("%#hhx\n",temp_var.option);
    printf("%#x\n", temp_var.id);

    temp_var.id = 0x1234;
    printf("\n<----------------->\n");
    printf("%lf\n", temp_var.height);
    printf("%#hhx\n",temp_var.option);
    printf("%#x\n", temp_var.id);

    temp_var.option = '1';
    printf("\n<----------------->\n");
    printf("%lf\n", temp_var.height);
    printf("%#hhx\n",temp_var.option);
    printf("%#x\n", temp_var.id);
    return 0;new_type var;
    printf("The size of the data type is %lu\nvariable is %lu\n", sizeof(new_type), sizeof(var));
}