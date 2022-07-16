#include <stdio.h>
#include <stdlib.h>
#include "table.h"

int neighbourCount(int **table, int i, int j, int row, int col)
{
  int count = 0;
  if (i-1 >= 0 && j-1 >= 0)
  {
    if (table[i-1][j-1] >= 1)
    {
      count++;
    }
  }

  if (i-1 >= 0)
  {
    if(table[i-1][j] >= 1)
    {
      count++;
    }
  }

  if (i-1 >= 0 && j+1 < col)
  {
    if(table[i-1][j+1] >= 1)
    {
      count++;
    }
  }

  if (j-1 >= 0)
  {
    if(table[i][j-1] >= 1)
    {
      count++;
    }
  }

  if (j+1 < col)
  {
    if(table[i][j+1] >= 1)
    {
      count++;
    }
  }

  if (i+1 < row && j-1 >=0)
  {
    if(table[i+1][j-1] >= 1)
    {
      count++;
    }
  }

  if (i+1 < row)
  {
    if(table[i+1][j] >= 1)
    {
      count++;
    }
  }

  if (i+1 < row && j+1 < col)
  {
    if(table[i+1][j+1] >= 1)
    {
      count++;
    }
  }

  return count;
}