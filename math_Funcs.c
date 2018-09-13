/*Name: Jose Guerrero
 * Description: Compute and Print the Perimeter and Area of a Circle and the Volume of a Cylinder, Library of functions

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RadiusRange1 (7.3)
#define RadiusInc (0.7)
#define RadiusRange2 (13.2)
#define CylinderHeight1 (8.2)
#define CylinderHeightInc (1.5)
#define CylinderHeight2 (20.5)

// Computes area of a circle with radius r

double areaCircle(double r){
    return M_PI*r*r;
}// area of cirlce

//Computes perimeter of a Circle with radius r
double periCircle(double r){
    return M_PI*(r+r);
}//periCircle

//Computes volume of a cylinder with base radius r and height h
double volCylinder(double r, double h){
    double areaCi = areaCircle(r);
    double volCy = h*areaCi;
    return volCy;
}// volCylinder

//computes volume of a Sphere with radius r
double volSphere(double r){
    return M_PI*(4/3)*(r*r*r);
}//volSphere

//Computes the surface area of a sphere
double SareaSphere(double r){
    return M_PI*4*r*r;
}//SareaSphere

//Computes the surface area of a cylinder with height h and radius r
double SareaCylinder(double h, double r) {
    return periCircle(r) * h + areaCircle(r);
}//SareaCylinder

//Computes the volume of a cone with radius r and height h
double volCone(double h, double r){
    return areaCircle(r)*(h/3);
}// volCone

//Computes the surface area of a cone
double SareaCone(double h, double r){
    return M_PI*r*(sqrt(h*h + r*r)) + areaCircle(r);
}// SareaCone


int main(void){
    double radius = RadiusRange1;
    int k;
    double height = CylinderHeight1;
    int num =1234567;
    printf("%08d %08d %08d %08d %08d\n",num ,num, num, num, num );
    printf("%8s %8s %8s %8s %8s\n","Radius", "CircArea", "CircPeri", "CylHei", "CylVol");
    for (k=0; (k<9); k++) {
        double area = areaCircle(radius);
        double peri = periCircle(radius);
        double vol = volCylinder(radius, height);
        printf("%8.1f %8.2f %8.2f %8.1f %8.2f\n", radius, area, peri, height, vol);
        radius = radius + RadiusInc;
        height = height + CylinderHeightInc;
    }
    return EXIT_SUCCESS;
}//main