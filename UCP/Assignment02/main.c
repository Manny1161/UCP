#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "input.h"
#include "terminal.h"
#include "random.h"
#include "linkedlist.h"



int main(int argc, char * argv[])
{

    struct Node *start = NULL;
    
    initRandom();
    if(argc != 3)
    {
        printf("ERROR: INCORRECT ARGUMENTS!\n");
    }
    else if(atoi(argv[2])<2)
    {
        printf("ERROR: FOOD AMOUNT MUST BE ATLEAST 2!");
    }
    else
    {
        

        /* Successful file open */
        int mrow, mcol;
        char tail[3];
        int i;
        int ch;
        unsigned int_size = sizeof(int);
        
       
        
        FILE *fp;
        i = 0;
        
        fp = fopen(argv[1], "r");
        if(fp == NULL)
        {
            perror("Could not open file :(");
        }
        /*retrives the size of the map in the first line of the file*/
        for(i=0;i<1;i++)
        {
            fscanf(fp, "%d %d\n", &mrow, &mcol);
        }
        /*retrieves the character count and scans the contents into the linked list starting from the second line of the file*/
        ch = getc(fp);
        for(i=1;i<ch/2;i++)
        {
            fscanf(fp, "%s", tail);
            insertFirst(&start, tail,int_size);
              
        }
        printList(start, print);
        fclose(fp);
    }  
    return 0;
}