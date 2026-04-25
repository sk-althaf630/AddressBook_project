/*Description:-
     Date:-13 oct 25
     Time:-5h
     Code Name:-subetration of 2 variable
                        */

 #include <stdio.h>
 
 int main()
 {
    int num1, num2;

    printf("Enter the number: ");
    scanf("%d%d", &num1, &num2);

    int difference = num1 - num2;
    printf("Answer is %d\n", difference);

    return 0;
 }