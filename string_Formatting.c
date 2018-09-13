/*
 * Jose Guerrero 
* Description: Reads and Capitalizes the first l
etter of every word.
 */

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>

void read_and_capitalize(){
    int ch;
    //Get the first character from the user
    ch = getchar();
    ch = (char) toupper(ch);
    //Read chars until newline (\n) is encountered
    while(ch != '\n'){

        //Print out the current character
        //(Modify this section to produce the
        //output required by the assignment)
        if (isspace(ch))printf(" ");
        while (isspace(ch)) {
            ch = getchar();
            ch = (char) toupper(ch);
        }


            printf("%c", ch);
        /*if*/

        //Get the next character from the user)
        ch = getchar();
    }/*while*/
    printf("\n");
}/*read_and_capitalize*/

int main(void){
    printf("Enter a line of text: ");
    fflush(stdout);
    read_and_capitalize();
    return EXIT_SUCCESS;
}/*main*/