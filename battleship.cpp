/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "battleship.h"

CellContent my[FIELDSIZE][FIELDSIZE];
CellContent op[FIELDSIZE][FIELDSIZE];
CellContent guesses[FIELDSIZE][FIELDSIZE];

void load_game(){
  FILE* my_fd=fopen("battleship.my","r");
  FILE* op_fd=fopen("battleship.op","r");

  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&my[i][j],sizeof(CellContent),1,my_fd);
      fread(&op[i][j],sizeof(CellContent),1,op_fd);
      guesses[i][j]=Unknown;
    }
  }
  fclose(my_fd);
  fclose(op_fd);
}

bool is_out_of_range(int row, int col);

CellContent get_shot(int row, int col){
  if(is_out_of_range(row,col))
  {
    return OutOfRange;
  }
  return my[row][col];
}

bool is_out_of_range(int row, int col){
  if(row<0 || col<0 || row>=FIELDSIZE || col>=FIELDSIZE)
  {
    return true;
  }
  return false;
}

bool shoot(int row, int col){
  if(is_out_of_range(row,col))
  {
    return false;
  }

  if(op[row][col]==Boat)
  {
    for (int i = row-1; i <= row+1; i++) {
      for (int j = col-1; j <= col+1; j++) {
        if(!is_out_of_range(i,j))
        {
          guesses[i][j]=Water;
        }
      }
    }
  }
  guesses[row][col]=op[row][col];
  return true;
}

CellContent get_my_guess(int row, int col){
  if(is_out_of_range(row,col))
  {
    return OutOfRange;
  }
  return guesses[row][col];
}
