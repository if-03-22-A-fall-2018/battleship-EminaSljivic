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
  FILE *fd = fopen("battleship.my", "r");

  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&my[i][j],sizeof(CellContent),1,fd);
    }
  }

	fd = fopen("battleship.op", "r");

  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&op[i][j],sizeof(CellContent),1,fd);
    }
  }

  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      guesses[i][j]=Unknown;
    }
  }
  fclose(fd);
}

CellContent get_shot(int row, int col){
  if(row<0||row>=FIELDSIZE||col<0||col>=FIELDSIZE)
  {
    return OutOfRange;
  }
  return my[row][col];
}

bool shoot(int row, int col){
  if(row<0||row>=FIELDSIZE||col<0||col>=FIELDSIZE)
  {
    return false;
  }


  if (op[row][col]==Boat) {
    for (int i = row-1; i <= row+1; i++) {
      for (int j = col-1; j <= col+1; j++) {
        if(row>=0&&row<FIELDSIZE&&col>=0&&col<FIELDSIZE)
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
  if(row<0||row>=FIELDSIZE||col<0||col>=FIELDSIZE)
  {
    return OutOfRange;
  }
  return guesses[row][col];
}
