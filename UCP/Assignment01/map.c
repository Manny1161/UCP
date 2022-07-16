#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void map_arr(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    /*inner for loop to print the snakes body if it is greater than 3*/
                    for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][c] = *body_h;
                            printf("%c", map[r][c]);
                            
                        }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrW(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake_w;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][body_col] = *body_v;
                            
                            
                        }
                        printf("%c", map[r][body_col]);
                        
                        
                     }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrS(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake_s;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        
                        map[r][c] = *body_v;
                        printf("%c", map[r][c]);
                    
                        
                        
                        
                        
                     } 
                     
                     
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrA(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake_a;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][body_col] = *body_h;
                            
                            
                        }
                        printf("%c", map[r][body_col]);
                        
                        
                     }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrS1(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake_s;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][body_col] = *body_h;
                            
                            
                        }
                        printf("%c", map[r][body_col]);
                        
                        
                     }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrW1(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake_w;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][body_col] = *body_h;
                            
                            
                        }
                        printf("%c", map[r][body_col]);
                        
                        
                     }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrD1(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][body_col] = *body_v;
                            
                            
                        }
                        printf("%c", map[r][body_col]);
                        
                        
                     }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}

void map_arrA1(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    int r = 0; int c = 0; int br = 0; int bc = 0;
    system("clear");
    for(r=0;r<row_size;r++)
    {
        for(c=0;c<col_size;c++)
        {
            if((r==0) || (r==row_size-1) || (c==0) || (c==col_size-1))
            {
                printf("*");
            }
            else
            {
                if(r==player_row && c == player_col)
                {
                    map[r][c] = *snake_a;
                    printf("%c", map[r][c]);
                }
                else if(r==tail_row && c ==tail_col)
                {
                    map[r][c] = *tail;
                    printf("%c", map[r][c]);
                }
                else if(r==body_row && c == body_col)
                {
                    for(br=2;br<snake_len;br++)
                    {
                        for(bc=2;bc<snake_len;bc++)
                        {
                            
                            map[r][body_col] = *body_v;
                            
                            
                        }
                        printf("%c", map[r][body_col]);
                        
                        
                     }
                       
                }
                else if(r==food_row && c == food_col)
                {
                    map[r][c] = *food;
                    printf("%c", map[r][c]);
                }
                else
                {
                    printf(" ");
                }
            }   
        }printf("\n");
    }
}