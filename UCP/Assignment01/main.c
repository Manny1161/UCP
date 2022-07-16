#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "input.h"
#include "terminal.h"
#include "random.h"


int main(int argc, char * argv[])
{
    /*if make is ran with 'unbeatable' argument, run this code*/
    #ifdef UNBEATABLE
        initRandom();
        if(argc != 4)
        {
            printf("ERROR: INSUFFICIENT ARGUMENTS!\n");
        }
        else if(atoi(argv[1]) < 5 || atoi(argv[2]) < 5 || atoi(argv[3]) < 3)
        {
            printf("ERROR: MINIMUM!");
        }
        else
        {
            
            int row_size = atoi(argv[1]);
            int col_size = atoi(argv[2]);
            int snake_len = atoi(argv[3]);
            int r;
            char *snake = ">";
            char *snake_w = "^";
            char *snake_s = "v";
            char *snake_a =  "<";
            char *tail = "#";
            char *food = "@";
            char *body_h = "-";
            char *body_v = "|";
            int player_row = 1;
            int player_col = 3;
            
            
            int tail_row = player_row;
            int tail_col = 1;
            int body_row = player_row;
            int body_col = player_col-1;
            char **map = (char**)malloc(row_size * sizeof(char*));
            
            
            int food_row = random_(player_row+1, row_size-2);
            int food_col = random_(player_col+1, col_size-2);


            
            for(r=0;r<row_size;r++)
            {
                map[r] = (char*)malloc(col_size * sizeof(char));
            }
            
            map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
            input1(map, row_size, col_size, snake_len, snake, food,player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
            for(r=0;r<row_size;r++)
            {
                free(map[r]);
            }
            free(map);
        }
    #else
        initRandom();
        if(argc != 4)
        {
            printf("ERROR: INSUFFICIENT ARGUMENTS!\n");
        }
        else if(atoi(argv[1]) < 5 || atoi(argv[2]) < 5 || atoi(argv[3]) < 3)
        {
            printf("ERROR: MINIMUM!");
        }
        else
        {
            /*atoi function to convert string to int values*/
            int row_size = atoi(argv[1]);
            int col_size = atoi(argv[2]);
            int snake_len = atoi(argv[3]);
            int r;
            char *snake = ">";
            char *snake_w = "^";
            char *snake_s = "v";
            char *snake_a =  "<";
            char *tail = "#";
            char *food = "@";
            char *body_h = "-";
            char *body_v = "|";
            int player_row = 1;
            int player_col = 3;
            
            
            int tail_row = player_row;
            int tail_col = 1;
            int body_row = player_row;
            int body_col = player_col-1;
            char **map = (char**)malloc(row_size * sizeof(char*));
            
            /*food row and col will never be on the same position as the min is set to the snake head position+1 to the end of the map exclusive of the border*/
            int food_row = random_(player_row+1, row_size-2);
            int food_col = random_(player_col+1, col_size-2);


            
            for(r=0;r<row_size;r++)
            {
                map[r] = (char*)malloc(col_size * sizeof(char));
            }
            
            map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
            input(map, row_size, col_size, snake_len, snake, food,player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
            for(r=0;r<row_size;r++)
            {
                free(map[r]);
            }
            free(map);
        }

        
    #endif
    return 0;
}