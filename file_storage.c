/*Jose Guerrero
 * Description: Program that converts integers to roman numerals and stores roman numerals in a file.*/



#include <stdio.h>
#include <stdlib.h>
#define FILENAME ("RomanN.txt")
#define ERR1 ("Error opening")
#define ERR2 ("Error creating")

FILE* createFile(char*);
FILE* openFile(char*);
void writeFile(FILE* f);




int main(void){

    FILE* f = createFile(FILENAME);
     writeFile(f);
     fclose(f);

    int num=0;
    int remainder, count, c;



    for (c=0;c<20;c++) {
        printf("\nEnter a number between 1 and 4999");
        fflush(stdout);
        fscanf(stdin,"%d", &num);
        if (num>4999||num<=0){printf("\nSorry! Invalid Number! The program will now exit. Bye Bye.");break;}


            printf("The value of %d in roman numerals is ",num);
            for (count = 1; count <= num / 1000; count++)
                printf("M");
            remainder = num % 1000;
            for (count = remainder / 900; count == 1; count++)
                printf("CM");
            remainder = remainder % 900;
            for (count = remainder / 500; count == 1; count++)
                printf("D");
            remainder = remainder % 500;
            for (count = remainder / 400; count == 1; count++)
                printf("CD");
            remainder = remainder % 400;
            for (count = 1; count <= remainder / 100; count++)
                printf("C");
            remainder = remainder % 100;
            for (count = remainder / 90; count == 1; count++)
                printf("XC");
            remainder = remainder % 90;
            for (count = remainder / 50; count == 1; count++)
                printf("L");
            remainder = remainder % 50;
            for (count = remainder / 40; count == 1; count++)
                printf("XL");
            remainder = remainder % 40;
            for (count = remainder / 10; count >= 1; count--)
                printf("X");
            remainder = remainder % 10;
            for (count = remainder / 9; count == 1; count++)
                printf("IX");
            remainder = remainder % 9;
            for (count = remainder / 5; count == 1; count++)
                printf("V");
            remainder = remainder % 5;
            for (count = remainder / 4; count == 1; count++)
                printf("IV");
            remainder = remainder % 4;
            for (count = remainder; count >= 1; count--)
                printf("I");
            printf("\n");



    }
    return EXIT_SUCCESS;
}/*main*/


FILE *openFile(char *fnam) {
    FILE *f = fopen(fnam, "r");
    if (f == NULL) {
        printf("%s %s\n", ERR1, fnam);
        exit(EXIT_FAILURE);
    }/*if*/
    return f;
}/*openFile*/

FILE *createFile(char *fnam) {
    FILE *f = fopen(fnam, "w");
    if (f == NULL) {
        printf("%s %s\n", ERR2, fnam);
        exit(EXIT_FAILURE);
    }/*if**/
    return f;
}/*createFile*/

void writeFile(FILE* f){
    int num, remainder, counter;
    for (num=1;num<5000;num++){
        fprintf(f,"\n%d=",num);
        for (counter = 1; counter <= num / 1000; counter++)
            fprintf(f,"M");
        remainder = num % 1000;
        for (counter = remainder / 900; counter == 1; counter++)
            fprintf(f,"CM");
        remainder = remainder % 900;
        for (counter = remainder / 500; counter == 1; counter++)
            fprintf(f,"D");
        remainder = remainder % 500;
        for (counter = remainder / 400; counter == 1; counter++)
            fprintf(f,"CD");
        remainder = remainder % 400;
        for (counter = 1; counter <= remainder / 100; counter++)
            fprintf(f,"C");
        remainder = remainder % 100;
        for (counter = remainder / 90; counter == 1; counter++)
            fprintf(f,"XC");
        remainder = remainder % 90;
        for (counter = remainder / 50; counter == 1; counter++)
            fprintf(f,"L");
        remainder = remainder % 50;
        for (counter = remainder / 40; counter == 1; counter++)
            fprintf(f,"XL");
        remainder = remainder % 40;
        for (counter = remainder / 10; counter >= 1; counter--)
            fprintf(f,"X");
        remainder = remainder % 10;
        for (counter = remainder / 9; counter == 1; counter++)
            fprintf(f,"IX");
        remainder = remainder % 9;
        for (counter = remainder / 5; counter == 1; counter++)
            fprintf(f,"V");
        remainder = remainder % 5;
        for (counter = remainder / 4; counter == 1; counter++)
            fprintf(f,"IV");
        remainder = remainder % 4;
        for (counter = remainder; counter >= 1; counter--)
            fprintf(f,"I");
    }
}


