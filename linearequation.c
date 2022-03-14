/* Problem Description
For linear equation of the form aY + b + c = 0, we need to input value of a,b,c. After having values of all the constants we need to solve for Y and create a function which will return the calculated value of Y.

Expected Input and Output
Case 1. When the coefficient of Y is zero.

If a = 0, then we cannot predict the value of Y
because the product "a*Y" in the equation will become 0.
Case 2. When all the constants are positive:
For example:

If the value of a = 1, b = 1 and c = 1
then Y = -2.
Case 3. When constants are both negative and positive:
For example:

If the value of a = 1, b = -2 and c = -1
then Y = 3.  
*/

#include <stdio.h>
#include <string.h>
float solve_for_y(float a, float b, float c)
{
     float Y;
     if(a == 0)
     {
          printf("Value of Y cannot be predicted\n");
     }
     else
     {
          Y = -(b + c) / a;
     }
    return Y;
}
int main()
{
  float a, b, c, Y;
  printf("\nEnter a linear equation in one variable of the form aY + b + c = 0 ");
  printf("\nEnter the value of a, b, c respectively: ");
  scanf("%f%f%f", &a, &b, &c);
  Y = solve_for_y(a, b, c);
  printf("\nSolution is Y = %f", Y);
  return 0;
}
