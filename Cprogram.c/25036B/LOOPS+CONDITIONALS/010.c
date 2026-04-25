/* WAP to implement a basic calculator(switch case).
sample input :- 10 + 5
sample output :- 10 + 5 = 15 */
#include <stdio.h>

int main() 
{
    char op;
    double first, second;
    printf("Enter expression (e.g., 10 + 5): ");
    scanf("%lf %c %lf", &first, &op, &second);

    switch (op) 
    {
        case '+': printf("%.1lf + %.1lf = %.1lf\n", first, second, first + second); break;
        case '-': printf("%.1lf - %.1lf = %.1lf\n", first, second, first - second); break;
        case '*': printf("%.1lf * %.1lf = %.1lf\n", first, second, first * second); break;
        case '/': 
            if(second != 0.0) printf("%.1lf / %.1lf = %.2lf\n", first, second, first / second);
            else printf("Error! Division by zero.\n");
            break;
        default: printf("Error! Operator is not correct\n");
    }
    return 0;
}