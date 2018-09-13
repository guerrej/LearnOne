/*Name: Jose Guerrero
  * Description: Cone Calculator
*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float volCone(float r,float h);
float heiCone(float vol, float r);
float radiusCone(float vol, float h);


// Computes the volume of a Cone
float volCone(float r, float h){
    return M_PI*r*r*(h/3);
}//volCone

//Computes the height of a Cone
float heiCone(float vol, float r){
    return (3*vol)/(M_PI*r*r);
}//heiCone

//Computes the radius of a Cone
float radiusCone(float vol, float h){
    return sqrt((3*vol)/(M_PI*h));
}


int main() {

    float x;
    float h, r, v;
    int k;

    printf("Welcome to the ConeCalulator2.0!\n");


    for(k=1;k<20; k++){
        x = (rand()%4);

        if (x==0 && k<6){k=k+1; x = (rand()%4);}


        if (x == 1) {
        printf("Enter a height and a radius:");
        scanf("%1f %1f", &h, &r);
        v = volCone(r, h);
        printf("%d Cone Calc: r = %.2f h=%.2f v=%.2f\n\n",k, r, h, v);
         }
        if (x == 2) {
        printf("Enter a volume and a radius:");
        scanf("%1f %1f", &v, &r);
        h = heiCone(v, r);
        printf("%d Cone Calc: r = %.2f h=%.2f v=%.2f\n\n",k, r, h, v);
         }

        if (x == 3) {
        printf("Enter a volume and a height:");
        scanf("%1f %1f", &v, &h);
        r = radiusCone(v, h);
        printf("%d Cone Calc: r = %.2f h=%.2f v=%.2f\n\n", k, r, h, v);
        }
        if (x==0 && k>5)break;


}

    printf("\nBye Bye!");

    return EXIT_SUCCESS;
}