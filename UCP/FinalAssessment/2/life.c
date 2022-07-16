#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "table.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("ERROR: INSUFFICIENT ARGUMENTS!\n");
    }
    else if(atoi(argv[2])<0)
    {
        printf("ERROR: CYCLE AMOUNT MUST BE A POSITIVE INTEGER!\n");
    }
    else
    {
        int row=0;
        int col=0;
        int r; int c; int i; int j;
        int **table = (int**)malloc(row*sizeof(int*));
        int **neighbour = (int**)malloc(row*sizeof(int*));
        FILE *fp;
        fp = fopen(argv[1], "r");
        if(fp==NULL)
        {
            perror("ERROR: FAILED TO OPEN FILE\n");
        }
        for(r=0;r<1;r++)
        {
            fscanf(fp, "%d %d\n", &row, &col);
        }
        
        
        for(r=0;r<row;r++)
        {
            table[r] = (int*)malloc(col*sizeof(int));
        }
        for(r=0;r<row;r++)
        {
            neighbour[r] = (int*)malloc(col*sizeof(int));
        }
        for(r=0;r<row && !feof(fp);r++)
        {
            for(c=0;c<col && !feof(fp);c++)
            {           
                fscanf(fp, "%d", &table[r][c]);
            }  
        }     
        for(r=0;r<=atoi(argv[2]);r++)
        {
            system("clear");
            for(i=0;i<row;i++)
            {   printf("\n");
                for(j=0;j<col;j++)
                {
                    if(table[i][j] == 1)
                    {
                        printf("\033[0;100m");
                    }
                    else
                    {
                        printf("\033[0;107m");
                    }
                    neighbour[i][j] = neighbourCount(table, i, j, row, col);
                    printf(" ");
                    printf("\033[0m");
                }     
            }
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if((table[i][j] >= 1))
                    {
                        if(neighbour[i][j] <= 1 || neighbour[i][j] > 3)
                        {
                            table[i][j] = 0;
                        }
                        else if(neighbour[i][j] <=3)
                        {
                            table[i][j] = 1;
                        }
                    }
                    else
                    {
                        if(neighbour[i][j] == 3)
                        {
                            table[i][j] = 1;
                        }
                    }
                }
            }
            printf("\n");
            sleep(1);    
        }
        for(r=0;r<row;r++)
        {
            free(table[r]);
        }
        free(table);
        for(r=0;r<row;r++)
        {
            free(neighbour[r]);
        }
        free(neighbour);
        fclose(fp);
    }
    return 0;
}

