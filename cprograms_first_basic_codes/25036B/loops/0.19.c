//printing the reversal triangle
/*sample o/p:- a a a a 
               b b b
               c c 
               d
  sample i/p:-r-5, c-5*/
  #include <stdio.h>
  int main()
  {
    int i, j, line;
    printf("enter the lines: ");
    scanf("%d", &line);

    for(i = 0; i < line; i++)
    {
        for(j = line; j >= i; j--)
        {
            printf("%c ", i + 65);
        }
         printf("\n");
    }

  }