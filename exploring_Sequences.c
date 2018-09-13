/*  Description:  Code for CSC 111 A2 Part 2
 */

#include <stdio.h>
#include <stdlib.h>

/* ArithmeticSequence(start, increment, count)
   Print an arithmetic sequence with the provided properties:
    - start: first value in the sequence
    - increment: the increment value between each pair of values in the sequence
    - count: number of terms to generate
*/
void ArithmeticSequence(int start, int increment, int count){
    printf("Arthmetic sequence: ");
    int k;
    int a=start;
    for (k = 0; k < count;k++){
        printf("%d ", a);
        a=a+increment;

    }
    printf("\n");

}/*ArithmeticSequence*/

/* LeonardoSequence(k, count)
   Print count terms of the Leonardo sequence starting with the kth term
*/void LeonardoSequence(int k, int count){
    printf("LeonardoSequence: ");

    int a;
    int k1;
    int next;
    int k2;

    if (k<5) {
        k1 = 1, k2 = 1;
    }
    else {k1=5, k2=9;}

       for (a=1; a<=count; a++) {

           next=k1+k2+1;
           k1=k2;
           k2=next;
           printf("%d ", k1);
       }


    printf("\n");
}/*LeonardoSequence*/

/* HarmonicSequence(k, count)
   Print count terms of the harmonic sequence starting with the kth term
*/
void HarmonicSequence(int k, int count){
    printf("HarmonicSequence: ");
        int a;
        float n;
        const float ONE=1;
    for (a=1;a<=count;a++,k++){
        n=ONE/k;
        printf("%.3f ",n);


    }printf("\n");
}/*HarmonicSequence*/


int main(void){
    ArithmeticSequence(17, 6, 5);
    ArithmeticSequence(34, 6, 8);
    LeonardoSequence(2, 7);
    LeonardoSequence(5, 7);
    HarmonicSequence(1, 6);
    HarmonicSequence(3, 6);
    return EXIT_SUCCESS;
}/*main*/