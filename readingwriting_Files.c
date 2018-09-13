/*
 *  Author:      Jose Guerrero
 *  Description: Reading, writing, and encoding files
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define INPUT_FILENAME    ("A6P1TestingSherlock.txt")
#define OUTPUT_FILENAME   ("A6P1SherlockEncoded.txt")
#define WORDLEN (20)
#define LEN (1000)

void process_file(FILE*, FILE*);
FILE* openFile(char*);FILE* createFile(char*);

int main(void) {
    printf("Starting text encoding...\n\n");
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    FILE* ifp = openFile(INPUT_FILENAME);
    FILE* ofp = createFile(OUTPUT_FILENAME);

    process_file(ifp, ofp);

    fclose(ofp);
    fclose(ifp);
    printf("\nEncoding finished\n");
    return EXIT_SUCCESS;
} /*main*/

void process_file(FILE* ifp, FILE* ofp) {
    char str[LEN];
    typedef char words[WORDLEN];
    words list[50];



    printf("Begin file processing\n\n");


        while ((fgets(str, LEN, ifp)) != NULL) {
            int LEN2;
            int space = 0;
            char temp[WORDLEN];
            LEN2 = (int) strlen(str);
            for (int rows = 0; rows < LEN2; rows++) {

                if ((isspace(str[rows])) && (isalpha(str[rows + 1])))space++;

            }// counts the number of spaces in each line that is used to adjust the number of words needed to be stored


            if (space==0){
                fprintf(ofp,"\n");
            }// if there are no spaces then it moves to a new line
            if (space < 7) {
                sscanf(str, "%s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5]);
            }

            if (space == 7) {
                sscanf(str, "%s %s %s %s %s %s %s %s  ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7]);

            }

            if (space == 8) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8]);
            }
            if (space == 9) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9]);

            }
            if (space == 10) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10]);
            }
            if (space == 11) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11]);

            }
            if (space == 12) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12]);

            }
            if (space == 13) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13]);
            }
            if (space == 14) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s   ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14] );
            }
            if (space == 15) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s  ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14],
                       list[15]);

            }
            if (space == 16) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14],
                       list[15], list[16]);
            }
            if (space == 17) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14],
                       list[15], list[16], list[17]);
            }
            if (space == 18) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2], list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14],
                       list[15], list[16], list[17], list[18]);

            }
            if (space == 19) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s ", list[0], list[1], list[2],
                       list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14],
                       list[15], list[16], list[17], list[18], list[19]);
            }
            if (space == 20) {
                sscanf(str, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s  ", list[0], list[1], list[2],
                       list[3],
                       list[4], list[5], list[6], list[7], list[8], list[9], list[10], list[11], list[12], list[13],
                       list[14],
                       list[15], list[16], list[17], list[18], list[19], list[20]);
            }



            if(isspace(str[0]))space = space-1;// if there is a space in the beginning of the word, the word is adjusted

            for (int i = 0; i < space+1; i++) {
                int slen = 0;

                char first = 0;
                char second = 0;
                words c;
                strcpy(temp, list[i]);

                slen = (int) strlen(temp);
                int s2len = slen;
                for (int g=0;g<s2len; g++){
                    if(isalpha(temp[g])==false)slen= slen-1;
                }//Counts the number of non alphabetic numbers and adjustes each word length randomization accordingly


                if (slen == 4) {
                    first = temp[1];
                    for (int b = 2; b < slen - 1; b++) {

                        temp[b - 1] = temp[b];

                    }
                    temp[slen - 2] = first;
                }// algorithm to randomize the inner characters of words that are four letters long
                if (slen > 4) {
                    first = temp[1];
                    second = temp[2];
                    for (int k = 0; k < 2; k++) {
                        for (int b = 2; b < slen - 1; b++) {

                            temp[b - 1] = temp[b];

                        }
                    }
                    temp[slen - 3] = first;
                    temp[slen - 2] = second;

                }//algorithm to randomize the ineer characters of words that are greater than four letters long


                strcpy(list[i], temp);// returns each word to array and then each word is printed into the file
                fputs(list[i], ofp);
                fputs(" ", ofp);


            }
            fprintf(ofp, "\n");


        }//end of while loop to process each line that is received




    printf("\nEnd file processing\n");

}
/* process_file */


FILE* openFile(char* fnam) {
    FILE* ifp = fopen(fnam, "r");
    if (ifp == NULL) {
        printf("Cannot open input file %s\n", fnam);
        exit(EXIT_FAILURE);
    } /* if */
}/*openFile*/

FILE* createFile(char* fnam) {
    FILE* ifp = fopen(fnam, "w");
    if (ifp == NULL) {
        printf("Cannot create output file %s\n", fnam);
        exit(EXIT_FAILURE);
    } /* if */
}/*createFile*/

