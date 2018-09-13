/*Jose Guerrero
  * Description: This program generates 20 pumpkins using HTML of different appearances. */
#include <stdio.h>
#include <stdlib.h>
#define FILENAME ("MyPumpkin.html")
#define ERR ("Error creating")
#define CANVASWIDTH (1100)
#define CANVASHEIGHT (400)
#define PXOFFSET (800)
#define PYOFFSET (120)
#define PUMPKIN_COLOUR (255)
#define PUMPKIN_COLOUR2 (0)

FILE* createFile(char*);
void writePrologue(FILE*);
void writePumpkin(FILE*, int, int, int, int, float);
void writeEpilogue(FILE*);

int main(void){
    FILE* f = createFile(FILENAME);
    int x = rand() % PXOFFSET;
    int y = rand() % PYOFFSET;
    float sf = 0.85;
    int col = PUMPKIN_COLOUR;
    int col2=PUMPKIN_COLOUR2;
    writePrologue(f);
    for (int k=0; k<20; k++) {
        writePumpkin(f, x, y, col, col2, sf);
        col = col-12;
        col2=col2+4;

        x=rand()% PXOFFSET;
        y=rand()% PYOFFSET;
        sf=sf-0.015;
    }
    writeEpilogue(f);
    fclose(f);
    return EXIT_SUCCESS;
}/*main*/

FILE* createFile(char* fnam) {
    FILE* ofp = fopen(fnam, "w");
    if (ofp == NULL) {
        printf("%s %s\n", ERR, fnam);
        exit(EXIT_FAILURE);
    }/*if*/
    return ofp;
}/*createFile*/

void writePrologue(FILE* ofp) {
    printf("Write prologue\n");
    fprintf(ofp, "<!DOCTYPE html>\n");
    fprintf(ofp, "<html>\n");
    fprintf(ofp, "<head>\n");
    fprintf(ofp, "<title>My CSC 111 Web Page</title>\n");
    fprintf(ofp, "</head>\n");
    fprintf(ofp, "<body>\n");
    fprintf(ofp, "<svg width=\"%d\" height=\"%d\">\n", CANVASWIDTH, CANVASHEIGHT);
    fprintf(ofp, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" style=\"fill:rgb(0,0,0)\"></rect>\n", CANVASWIDTH, CANVASHEIGHT);
}/*writePrologue*/

void writePumpkin(FILE* ofp, int px, int py, int col, int col2, float sf) {


    printf("Write pumpkin\n");
    fprintf(ofp, "<g transform=\"translate(%d, %d) scale(%f)\">\n",px,py,sf);
    fprintf(ofp, "<circle cx=\"150\" cy=\"150\" r=\"100\" style=\"fill:rgb(%d,110,%d)\"></circle>\n", col, col2);
    fprintf(ofp, "<circle cx=\"210\" cy=\"153\" r=\"102\" style=\"fill:rgb(%d,105,%d)\"></circle>\n", col, col2);
    fprintf(ofp, "<rect x=\"160\" y=\"-50\" height=\"60\" width=\"20\" rx=\"20\" ry=\"20\" style=\"fill:rgb(25,%d,50)\" transform=\"rotate(30 50 50)\"></rect>\n", col);
    fprintf(ofp, "<text x=\"120\" y=\"230\" >Happy Halloween!</text>\n");
    fprintf(ofp, "</g>\n");

}/*writePumpkin*/

void writeEpilogue(FILE* ofp) {
    printf("Write epilogue\n");
    fputs("</svg>\n", ofp);
    fputs("</body>\n", ofp);
    fputs("</html>\n", ofp);
}/*writeEpilogue*/