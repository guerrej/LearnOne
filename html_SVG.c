/*Jose Guerrero
 * Program Description: Generates a svg html file.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILENAME ("MyCSC111Art.html")
#define ERR ("Error creating")
#define BACKGROUNDCOL ("white")
#define FRAMECOL ("blue")
#define FRAMEWIDTH (10)
#define CANVASWIDTH (700)
#define CANVASHEIGHT (400)
#define PXMIN (0)
#define PXMAX (700)
#define PYMIN (0)
#define PYMAX (400)
#define RADMIN (20)
#define RADMAX (150)
#define CRMIN (0)
#define CRMAX (255)
#define CGMIN (100)
#define CGMAX (255)
#define CBMIN (0)
#define CBDMAX (255)
#define OPMIN (0.1)
#define OPMAX (1.0)
#define LENMIN (10)
#define LENMAX (90)
#define RXMIN (10)
#define RXMAX (70)
#define RYMIN (20)
#define RYMAX (80)
#define SQMIN (25)
#define SQMAX (75)
#define SCMIN (0.2)
#define SCMAX (1.2)

int randInt(int, int);
double randFloat(double, double);
void genIntsFloats(int, int, int, double, double);
FILE* createFile(char*);
void writePrologue(FILE*);
void writeEpilogue(FILE*);
void genCSC111Art(FILE*);
void circle(FILE*, int, int, int, int, int, int, double, int, int, double);
void ellipse(FILE*, int, int, int, int, int, int, int, double, int, int, double);
void rectangle(FILE*, int, int, int,int, int, double, int, int, double);
void square(FILE*, int, int, int, int, double, int, int, double);
void circlerand(int*, int*, int*, int*, int*, int*, double *, int*, int*);
void transform(int*, int*, double* );
void rectrand(int*, int*, int*, int*, int*, int*, double*);
int main(void);

int main(void) {
    time_t t;
    srand((unsigned)time(&t)); // init random number generator

    FILE* ofp = createFile(FILENAME);
    printf("File %s open\n", FILENAME);

    writePrologue(ofp);
    printf("Prologue written into %s\n", FILENAME);
    genCSC111Art(ofp);
    printf("CSC111 Art written into of %s\n", FILENAME);
    writeEpilogue(ofp);
    printf("Epilogue written into %s\n", FILENAME);

    fclose(ofp);
    printf("File %s closed\n", FILENAME);
    return EXIT_SUCCESS;
}/*main*/

void genCSC111Art(FILE* ofp){
    int cx = 0, cy=0, rad=0, cr=0, cg=0, cb= 0, px=0, py=0, rx=0,ry=0, width=0, hei=0, side=0;
    double op=0, sf=0;
    int *pcx = &cx;
    int *pcy = &cy;
    int *prad = &rad;
    int *pcr = &cr;
    int *pcg = &cg;
    int *pcb = &cb;
    int *ppy=  &py;
    int *ppx = &px;
    double  *psf = &sf;
    double *pop =&op;
    int *pwidth = &width;
    int *phei = &hei;
    int *pside = &side;
    int *prx = &rx;
    int *pry = &ry;
    int i=0;
    for(int k=0;k<2000;k++) {
        circlerand(pcx, pcy, prad, pcr, pcg, pcb, pop, prx, pry);
        transform(ppx, ppy, psf);

        circle(ofp, cx, cy, rad, cr, cg, cb, op, py, px, sf);

        int* ip=&i;

        if (k < 3) {
            *ip=*ip+1;
            printf("%d %9s %7s %7s %7s %7s %7s %7s %7s %7s %7s %8s",i,"Circle:", "CX", "CY", "Radius", "CR", "CG", "CB", "Opacity", "PY", "PX", "Scale\n");
            printf("  %17d %7d %7d %7d %7d %7d %7.2f %7d %7d %7.2f\n", cx, cy, rad, cr, cg, cb, op, py, px, sf);
        }

        rectrand(pwidth, phei, pside, pcr, pcg, pcb, pop);
        transform(ppx, ppy, psf);

        rectangle(ofp, width, hei, cr, cg, cb, op, px, py, sf);
        if (k < 3) {
            *ip=*ip+1;
            printf("%d %9s %7s %6s %6s %7s %7s %7s %7s %7s %8s", i, "Rectangle:", "Width", "Height", "CR","CG","CB", "Opacity", "PY", "PX", "Scale\n");
            printf("  %17d %7d %7d %7d %7d %7.2f %7d %7d %7.2f\n", width, hei, cr, cg, cb, op, py, px, sf);
        }


        rectrand(pwidth, phei, pside, pcr, pcg, pcb, pop);
        transform(ppx, ppy, psf);

        square(ofp, side, cr, cg, cb, op, px, py, sf);
        if (k < 2) {
            *ip=*ip+1;
            printf("%d %9s %7s %7s %7s %7s %7s %7s %7s %8s",i, "Square:", "Length", "CR", "CG", "CB", "Opacity", "PY", "PX", "Scale\n");
            printf("  %17d %7d %7d %7d %7.2f %7d %7d %7.2f\n", side, cr, cg, cb, op, py, px, sf);
        }

        circlerand(pcx, pcy, prad, pcr, pcg, pcb, pop, prx, pry);
        transform(ppx, ppy, psf);

        ellipse(ofp, cx, cy, rx, ry, cr, cg, cb, op, px, py, sf);
        if (k < 2) {
            *ip=*ip+1;
            printf("%d %9s %7s %7s %7s %7s %7s %7s %7s %7s %7s %7s %8s",i, "Ellipse", "CX", "CY", "RX", "RY", "CR","CG","CB","Opacity","PY","PX","Scale\n");
            printf("  %17d %7d %7d %7d %7d %7d %7d %7.2f %7d %7d %7.2f\n", cx, cy, rx, ry, cr, cg, cb, op, py, px, sf);
        }
    }

}/*genCSC111Art*/
void rectrand( int* pwidth, int* phei, int* pside, int* pcr, int* pcg, int* pcb, double* pop){
    *pwidth = randInt(LENMIN,LENMAX);
    *phei = randInt(LENMIN,LENMAX);
    *pside = randInt(SQMIN, SQMAX);
    *pcr = randInt(CRMIN, CRMAX);
    *pcg = randInt(CGMIN, CGMAX);
    *pcb = randInt(CBMIN, CBDMAX);
    *pop = randFloat(OPMIN, OPMAX);

}

void circlerand(int* pcx, int* pcy,int* prad, int* pcr, int* pcg, int* pcb, double* pop, int* prx, int*pry) {
     *pcx = randInt(PXMIN, PXMAX);
     *pcy = randInt(PYMIN, PYMAX);
    *prad = randInt(RADMIN, RADMAX);
     *pcr = randInt(CRMIN, CRMAX);
    *pcg = randInt(CGMIN, CGMAX);
    *pcb = randInt(CBMIN, CBDMAX);
    *pop = randFloat(OPMIN, OPMAX);
    *prx = randInt(RXMIN,RXMAX);
    *pry = randInt(RYMIN, RYMAX);
}

void transform(int*ppx, int*ppy, double* psf){
    *ppx=randInt(PXMIN,PXMAX);
    *ppy= randInt(PYMIN, PYMAX);
    *psf = randFloat(SCMIN,SCMAX);

}

void circle(FILE* ofp, int cx, int cy, int rad, int cr, int cg, int cb, double op, int px, int py, double sf){
    fprintf(ofp, "<g transform=\"translate(%d, %d) scale(%f)\">\n",px,py,sf);
    fprintf(ofp, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\"", cx, cy, rad);
    fprintf(ofp, " style=\"fill:rgb(%d,%d,%d);", cr, cg, cb);
    fprintf(ofp, " fill-opacity:%.2f\"></circle>\n", op);
    fprintf(ofp, "</g>\n");
}/*circle*/
void rectangle(FILE* ofp, int width, int hei, int cr, int cg, int cb, double op, int px, int py, double sf){
    fprintf(ofp, "<g transform=\"translate(%d, %d) scale(%f)\">\n",px,py,sf);
    fprintf(ofp, "<rect width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d);stroke-width:0;stroke:rgb(0,0,0); ",width, hei, cr, cg,cb);
    fprintf(ofp, "fill-opacity:%.2f\"></rect>\n",op);
    fprintf(ofp, "</g>\n");
}

void ellipse(FILE* ofp, int cx, int cy, int rx, int ry, int cr, int cg, int cb, double op, int px, int py, double sf){
    fprintf(ofp, "<g transform=\"translate(%d, %d) scale(%f)\">\n",px,py,sf);
    fprintf(ofp, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\"", cx, cy, rx, ry);
    fprintf(ofp, "style=\"fill:rgb(%d,%d,%d);stroke:purple;stroke-width:0; fill-opacity:%.2f\" ></ellipse>\n",cr, cg, cb, op);
    fprintf(ofp, "</g>\n");


}
void square(FILE* ofp, int side, int cr, int cg, int cb, double op, int px, int py, double sf){
    fprintf(ofp, "<g transform=\"translate(%d, %d) scale(%f)\">\n",px,py,sf);
    fprintf(ofp, "<rect width=\"%d\" height=\"%d\" style=\"fill:rgb(%d,%d,%d);stroke-width:0;stroke:rgb(150,200,0);",side,side,cr,cg,cb);
    fprintf(ofp, "fill-opacity:%.2f\"></rect>\n",op);
    fprintf(ofp, "</g>\n");

}
int randInt(int min, int max) {
    return (rand() % (max - min + 1) + min);
}/*randInt*/

double randFloat(double min, double max){
    double r = (double)rand() / (double)RAND_MAX;
    return ((max-min) * r + min);
}/*randFloat*/
/*
void genIntsFloats(int rands, int imin, int imax, double fmin, double fmax){
    printf("RandInts: ");
    for (int k=0; k<5; k++) printf("%d ", randInt(imin, imax));
    printf("\n");
    printf("RandFloats: ");
    for (int k=0; k<5; k++) printf("%.2f ", randFloat(fmin, fmax));
    printf("\n");
}/*genIntsFloats*/

FILE* createFile(char* fnam) {
    FILE* ofp = fopen(fnam, "w");
    if (ofp == NULL) {
        printf("%s %s\n", ERR, fnam);
        exit(EXIT_FAILURE);
    }/*if*/
    return ofp;
}/*createFile*/

void writePrologue(FILE* ofp) {
    fprintf(ofp, "<!DOCTYPE html>\n");
    fprintf(ofp, "<html>\n");
    fprintf(ofp, "<head>\n");
    fprintf(ofp, "<title>My CSC 111 Art</title>\n");
    fprintf(ofp, "</head>\n");
    fprintf(ofp, "<body>\n");
    fprintf(ofp, "<svg width=\"%d\" height=\"%d\">\n", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" ", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "fill=\"%s\" stroke=\"%s\" stroke-width=\"%d\"></rect>\n", BACKGROUNDCOL, FRAMECOL,FRAMEWIDTH);
}/*writePrologue*/

void writeEpilogue(FILE* ofp) {
    fprintf(ofp, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" ", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "fill=\"none\" stroke=\"%s\" stroke-width=\"%d\"></rect>\n", FRAMECOL,FRAMEWIDTH);
    fputs("</svg>\n", ofp);
    fputs("</body>\n", ofp);
    fputs("</html>\n", ofp);
}/*writeEpilogue*/
