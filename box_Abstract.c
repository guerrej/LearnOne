/*
 ============================================================================
 Name        : Abstraction10.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define BorderChar ("=")
#define MiddleChar (".")

void border(int size) {
    int k = 0;
    for (k=0; k<size; k++) {
        printf(BorderChar);
    }/*for*/
    printf("\n");
}/*border*/

void middle(int size) {
    int k = 0;
    printf(BorderChar);
    for (k=0; k<size-2; k++) {
        printf(MiddleChar);
    }/*for*/
    printf(BorderChar);
    printf("\n");
}/*middle*/

void drawBox(int size) {
    int k = 0;
    border(size);
    for (k=0;k < size-2; k++){
        middle(size);
    }/*for*/
    if (size > 1) border(size);
}/*drawBox*/

int initBoxSize(void) {
    int size;
    printf("Enter box size or -1 to exit: ");
    fflush(stdout);
    scanf("%d",&size);
    return size;
}/*initBoxSize*/

int initNoBoxes(void) {
    int boxes;
    printf("Enter number of boxes or -1 to exit: ");
    fflush(stdout);
    scanf("%d",&boxes);
    return boxes;
}/*initNoBoxes*/

void printStats(int boxes, int size) {
    if (boxes == 1)
        printf("Draw %d box of size %d\n", boxes, size);
    else
        printf("Draw %d boxes of size %d\n", boxes, size);
}/*printStats*/

void drawBoxes(int boxes, int size) {
    int k = 0;
    for (k=0; k < boxes; k++){
        drawBox(size);
        printf("\n"); /* empty line between boxes */
    }/*for*/
}/*drawBoxes*/

int main(void) {
    int BoxSize, NoBoxes;
    for (int i=0;i<4;i++) { /* infinite loop */
        BoxSize = initBoxSize();
        if (BoxSize < 0) break;
        NoBoxes = initNoBoxes();
        if (NoBoxes < 0) break;
        printStats(NoBoxes, BoxSize);
        drawBoxes(NoBoxes, BoxSize);
    }/*for*/
    printf("Bye bye\n");
    return EXIT_SUCCESS;
}/*main*/
