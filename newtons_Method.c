/* Jose Guerrero
 * Description: Using Newton's Method to calculate square root. */


#include <stdio.h>


int main() {
    double x = 1.0;
    double y;
    int a, num=1;
    const int COUNT = 10;
    double T=117;

    printf("Computing square roots using Newtwon's Method \n");
    for (a = 1; a <= COUNT; a++, num++) {
        printf("Iteration %d %14.10f \n",num, x);
        y = x - ((x * x - T) / (2 * x));
        x=y;
    }
    printf("The square root of 117.00 with 10 Iterations is %3.10f \n",x);
    printf("The square of %3.10f is %3.20f",x,x*x);
}