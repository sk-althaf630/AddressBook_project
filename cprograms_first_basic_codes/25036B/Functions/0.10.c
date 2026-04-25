#include <stdio.h>
int add(int, int);
int sub(int, int);
int mut(int, int);
int divi(int, int);

int main()
{
  int num1, num2, res;
  printf("enter the num's: ");
  scanf("%d %d", &num1, &num2);

  res = add(num1, num2);
  printf("Res: %d\n", res);

  res = sub(num1, num2);
  printf("Res: %d\n", res);

  res = mut(num1, num2);
  printf("Res: %d\n", res);

  res = divi(num1, num2);
  printf("Res: %d\n", res);
}
int add(int num1, int num2)
{
  return num1 + num2;
}
int sub(int num1, int num2)
{
  return num1 - num2;
}
int mut(int num1, int num2)
{
  return num1 * num2;
}
int divi(int num1, int num2)
{
  return num1 / num2;
}