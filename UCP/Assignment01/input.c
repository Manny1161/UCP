#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "terminal.h"
#include "map.h"

void input(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    char choice;
    do
    {
        disableBuffer();
        scanf(" %c", &choice);
        enableBuffer();
        switch(choice)
        {
            /*switch statement to handle the player mvoement using the (wasd) char keys, incrementing or decrementing the player postion respectfully*/
            case 'w':
                if(player_row-1 != 0)
                {
                    if(body_col < player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row][tail_col++] = *tail;
                        map_arrW1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(body_col > player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row][tail_col--] = *tail;
                        map_arrW1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col > player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row][tail_col--] = *tail;
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col < player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row][tail_col++] = *tail;
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_row > body_row)
                    {
                        
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row--][tail_col] = *tail;
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    printf("Can't go outside map!");
                }
                break;
            case 'a':
                if(player_col-1 != 0)
                {
                    if(body_row > player_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row--][tail_col] = *tail;;
                        map_arrA1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_row > body_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row++][body_col] = *tail;
                        map_arrA1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row < player_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row++][tail_col] = *tail;
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row > player_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row--][tail_col] = *tail;
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_col > body_col)
                    {
                        
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row][tail_col--] = *tail;
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    printf("Can't go outside map!");
                }
                break;
            case 's':
                if(player_row+2 != row_size)
                {
                    if(body_col < player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row][tail_col++] = *tail;
                        map_arrS1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(body_col > player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row][tail_col--] = *tail;
                        map_arrS1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col < player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row][tail_col++] = *tail;
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col > player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row][tail_col--] = *tail;
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_row < body_row)
                    {
                        
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row++][tail_col] = *tail;
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);    
                    printf("Can't go outside map!");
                }
                break;
            case 'd':
                if(player_col+2 != col_size)
                {
                    if(body_row < player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row++][tail_col] = *tail;
                        map_arrD1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(body_row > player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row--][tail_col] = *tail;
                        map_arrD1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row < player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row++][tail_col] = *tail;
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row > player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row--][tail_col] = *tail;
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_col < body_col)
                    {
                        
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row][tail_col++] = *tail;
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    printf("Can't go outside map!");
                }
                break;
            default:
                    printf("Invalid key!");
                break;
        }
    } while(map[player_row][player_col] != map[food_row][food_col]);
    printf("You Win!\n");
}

void input1(char **map, int row_size, int col_size, int snake_len, char *snake, char *food, int player_row, int player_col, int food_row, int food_col, char *tail, int tail_row, int tail_col, char *snake_w, char *snake_s, char *snake_a, char *body_h, int body_row, int body_col, char *body_v)
{
    char choice;
    do
    {
        disableBuffer();
        scanf(" %c", &choice);
        enableBuffer();
        switch(choice)
        {
            /*switch statement to handle the player mvoement using the (wasd) char keys, incrementing or decrementing the player postion respectfully*/
            case 'w':
                if(player_row-1 != 0)
                {
                    if(body_col < player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row][tail_col++] = *tail;
                        map_arrW1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(body_col > player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row][tail_col--] = *tail;
                        map_arrW1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col > player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row][tail_col--] = *tail;
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col < player_col)
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row][tail_col++] = *tail;
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_row > body_row)
                    {
                        
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row--][player_col] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row--][tail_col] = *tail;
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    printf("Can't go outside map!");
                }
                break;
            case 'a':
                if(player_col-1 != 0)
                {
                    if(body_row > player_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row--][tail_col] = *tail;;
                        map_arrA1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_row > body_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row++][body_col] = *tail;
                        map_arrA1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row < player_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row++][tail_col] = *tail;
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row > player_row)
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row--][tail_col] = *tail;
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_col > body_col)
                    {
                        
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row][player_col--] = *snake_a;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row][tail_col--] = *tail;
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    printf("Can't go outside map!");
                }
                break;
            case 's':
                if(player_row+2 != row_size)
                {
                    if(body_col < player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row][tail_col++] = *tail;
                        map_arrS1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(body_col > player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row][body_col--] = *body_h;
                        map[tail_row][tail_col--] = *tail;
                        map_arrS1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col < player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row][tail_col++] = *tail;
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_col > player_col)
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row][tail_col--] = *tail;
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_row < body_row)
                    {
                        
                        map_arrW(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row++][player_col] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row++][tail_col] = *tail;
                        map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arrS(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);    
                    printf("Can't go outside map!");
                }
                break;
            case 'd':
                if(player_col+2 != col_size)
                {
                    if(body_row < player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row++][body_col] = *body_v;
                        map[tail_row++][tail_col] = *tail;
                        map_arrD1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(body_row > player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row--][body_col] = *body_v;
                        map[tail_row--][tail_col] = *tail;
                        map_arrD1(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row < player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row++][tail_col] = *tail;
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(tail_row > player_row)
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row--][tail_col] = *tail;
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                    else if(player_col < body_col)
                    {
                        
                        map_arrA(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                        printf("Can't go backwards!");
                    }
                    else
                    {
                        map[player_row][player_col++] = *snake;
                        map[body_row][body_col++] = *body_h;
                        map[tail_row][tail_col++] = *tail;
                        map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    }
                }
                else
                {
                    map_arr(map, row_size, col_size, snake_len, snake, food, player_row, player_col, food_row, food_col, tail, tail_row, tail_col, snake_w, snake_s, snake_a, body_h, body_row, body_col, body_v);
                    printf("Can't go outside map!");
                }
                break;
            default:
                    printf("Invalid key!");
                break;
        }
    } while(map[player_row][player_col] != map[food_row][food_col]);
    printf("You Win!\n");
}   