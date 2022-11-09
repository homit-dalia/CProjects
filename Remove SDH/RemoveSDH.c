#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


void main(void) {

    FILE *file1;
    int ch1;
    file1 = fopen("subtitles.txt", "r+"); // replace file name (inside quotes) to your subtitle file name in "txt" format
    int num = 1;
    bool squareBracket = false;

    if(file1 == NULL){
        printf("Cannot open file1");
        exit(1);
    }

    while((ch1 = fgetc(file1)) != EOF)
    {
        if(ch1 == '[' || ch1 == '(' )
        {
             if(ch1 == '[' || ch1 == '(')
            {
                if(ch1 == '[')
                {
                    squareBracket = true;
                }
          fseek(file1, -1, SEEK_CUR);
          fputc('#',file1);
          fseek(file1, 0 , SEEK_CUR);
            }

            if(squareBracket)
            {
                    while((ch1 = fgetc(file1)) != ']')
                    {
                    fseek(file1, -1, SEEK_CUR);
                    fputc('#',file1);
                    fseek(file1, 0 , SEEK_CUR);
                    }
            }
          else{
            while((ch1 = fgetc(file1)) != ')')
            {
            fseek(file1, -1, SEEK_CUR);
            fputc('#',file1);
            fseek(file1, 0 , SEEK_CUR);
            }
          }

        if(ch1 == ']' || ch1 == ')')
            {
          fseek(file1, -1, SEEK_CUR);
          fputc('$',file1);
          fseek(file1, 0 , SEEK_CUR);
          printf("Removed SDH line %d \n", num++);
            }
        }
    }



 fseek(file1, 0, SEEK_SET);

FILE *file3;
int ch2;

    file3 = fopen("subtitles_wo_SDH.txt","w");

        if(file3 == NULL)
         {
            printf("Cannot open File3");
            exit(1);
         }

    while((ch2 = fgetc(file1)) != EOF)
    {

        if(ch2 == '$')
            {
                ch2 = fgetc(file1);
                ch2 = fgetc(file1);
            }

        if(ch2 != '#')
            {
                fputc(ch2, file3);
            }
    }


              printf("\n\n        SDH Removed subtitles added to new file...   \n\n\n");


    fclose("subtitles.txt");
    fclose("subtitles_wo_SDH.txt.txt");
}
