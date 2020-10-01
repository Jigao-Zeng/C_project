/* ENGGEN131 Project - C Project - 2018 */
/* Connect Four */

#include "connect4.h"

/*
name: Jigao Zeng
UPI: 711273867
*/

int SecondPlacePrize(int prize1, int prize2, int prize3)
{
	int SecondPrize;
	// find a prize between another two prize
		if (((prize1 <= prize2) && (prize1 >= prize3))||(((prize1<=prize3)&&(prize1>=prize2)))){
			SecondPrize = prize1;
	}
		else if (((prize2 <= prize1) && (prize2 >= prize3))||(((prize2<= prize3) && (prize2>= prize1)))) {
			SecondPrize = prize2;
		}
		else {
			SecondPrize = prize3;
		}
	return SecondPrize;
}

int FourInARow(int values[], int length)
{
	int i=0;
	// check if subsequent four values are same
	while (i < length - 3) {
		if ((values[i] == values[i + 1]) && (values[i + 1] == values[i + 2]) && (values[i + 2] == values[i + 3])) {
			return i; 
		}
		else {
			i++;
		}
	}
		return -1; // return -1 if "four-in-a-row" can not be found
		}

	

		
	
			
	


int BinaryToDecimal(int binary)
{
	int decimal = 0;
	int base = 1;
	int quotient;
	int significantNumber;
	quotient = binary / 10;
    significantNumber = binary % 10;
	decimal = decimal + base * significantNumber;
	// do the first operation for the condition of while loop
	while (quotient > 0) 
	{
		significantNumber = quotient % 10; //significantNumber is the remainder
		quotient = quotient / 10; // get the new quotient to check if the next operation can carry on
		base = base * 2; //base double in each operation
		decimal = decimal + base * significantNumber; // calculate the new decimal value
	}
	
	return decimal;
}

void RearrangeArray(double *array, int length)
// This helper function aims to rearrange elements in the array in an increasing manner
{
	double largerValue;
	int i;
	int j;
	// For every subsequent two values, if back value is smaller than front value, swap their positions 
	for (i = 0; i < length; i++) {
		for (j = i + 1; j < length; j++) {
			if (array[i] > array[j]) {
				 largerValue= array[i]; // a is used to help swap the value
				array[i] = array[j];
				array[j] = largerValue;
			}
		}
	}
}
double MedianAbility(double abilities[], int length)
{
	double middle;
	RearrangeArray(abilities, length); // rearrange elements of array in an increasing manner
	if (length % 2 == 0) {
		middle = ((double)abilities[length / 2] + abilities[length / 2 - 1 ])/ 2;
	}
	// if length of abilities is an even number, result is the average of two middle values
	else if (length % 2 == 1) {
		middle = (double)abilities[length / 2];
	}
	// if length of abilities is an odd number, result is the middle value



	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	return middle;
}

void RemoveSpaces(char *name)

{
	int i = 0;
	int j;
	int n = strlen(name); 
	while (i < n) {
		if (name[i] == ' '&&name[i + 1] == ' ') {
			for (j = i + 1; j < n; j++) {
				name[j] = name[j + 1]; // move all characters forward from where the extra space is found
			}
			n = n - 1; //decrease the total length by one
		}
		else {
			i++;
		}
	}
}










void InitialiseBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
	int i;
	int j;
	// first set all elements within the size to be 0
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = 0;
		}
	}
	// If size is an odd number, set the middle of the board to be 3
	if (size % 2 == 1) {
		board[size / 2][size / 2] = 3;
	}
	// If size is an even number, set the middle four position of the board to be 3
	else if (size % 2 == 0) {
		board[size / 2][size / 2] = 3;
		board[size / 2 - 1][size / 2] = 3;
		board[size / 2][size / 2 - 1] = 3;
		board[size / 2 - 1][size / 2 - 1] = 3;
	}
}





void AddMoveToBoard(int board[MAX_SIZE][MAX_SIZE], int size, char side, int move, int player, int *lastRow, int *lastCol)
{
	if (side == 'N') {
		if (board[0][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // set the lastRow and lastCol to -1 if cannot make the move
		else {
			int i = 0;
			board[i][move] = player;
			while (i < size - 1) {
				if (board[i + 1][move] == 0) {
					board[i + 1][move] = player;
					board[i][move] = 0;
					*lastRow = i + 1;
					*lastCol = move;
					i++;
				} // Start the piece at the first row and keep moving piece down if there is a empty place 
				else {
					board[i][move] = player;
					*lastRow = i;
					*lastCol = move;
					break;
				} // stop moving and record the position if a piece( '1' or '2) or a barrier('3') gets in the way
			}
		}
	}

	else if (side == 'E') {
		if (board[move][size - 1] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // set the lastRow and lastCol to -1 if cannot make the move
		else {
			int i = size - 1;
			board[move][i] = player;
			while (i > 0) {
				if (board[move][i - 1] == 0) {
					board[move][i - 1] = player;
					board[move][i] = 0;
					*lastRow = move;
					*lastCol = i - 1;
					i--;
				} // Start the piece at last column and keep moving piece to the left if there is a empty place 
				else {
					board[move][i] = player;
					*lastRow = move;
					*lastCol = i;
					break;	
				} // stop moving and record the position if a piece( '1' or '2) or a barrier('3') gets in the way
			}
		}
	}

	else if (side == 'S') {
		if (board[size - 1][move] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // set the lastRow and lastCol to -1 if cannot make the move
		else {
			int i = size - 1;
			board[size - 1][move] = player;
			while (i > 0) {
				if (board[i - 1][move] == 0) {
					board[i - 1][move] = player;
					board[i][move] = 0;
					*lastRow = i - 1;
					*lastCol = move;
					i--;
				} // Start the piece at last row and keep moving piece up if there is a empty place 
				else {
					board[i][move] = player;
					*lastRow = i;
					*lastCol = move;
					break;	// stop moving and record the position if a piece( '1' or '2) or a barrier('3') gets in the way		
				}
			}
		}
	}
	
	else if (side == 'W') {
		if (board[move][0] != 0) {
			*lastRow = -1;
			*lastCol = -1;
		} // set the lastRow and lastCol to -1 if cannot make the move
		else {
			int i = 0;
			board[move][0] = player;
			while (i < size - 1) {
				if (board[move][i + 1] == 0) {
					board[move][i + 1] = player;
					board[move][i] = 0;
					*lastRow = move;
					*lastCol = i + 1;
					i++;
				} // Start the piece at first column and keep moving piece to the right if there is a empty place
				else {
					board[move][i] = player;
					*lastRow = move;
					*lastCol = i;
					break; 
				} // stop moving and record the position if a piece( '1' or '2) or a barrier('3') gets in the way	
			}
		}
	}
}
				
	



	
		int CheckGameOver(int board[MAX_SIZE][MAX_SIZE], int size, int player, int row, int col)
{
			int result;
			int i;
			
			if (row == -1 && col == -1) {
				return 0;
			} // game is not over when player make an invalid move
			
			// The following code check if "connect four" take place
			
			//four in a row:
		
			else if (board[row][col]==player&&board[row][col + 1] ==player&& board[row][col + 2] ==player&& board[row][col + 3] ==player&&col + 3 <= size - 1) {
				result = player;
			} // three pieces to the right of the last piece

			else if (board[row][col] == player && board[row][col - 1] == player && board[row][col + 1] == player && board[row][col + 2] == player && col - 1 >= 0 && col + 2 <= size - 1) {
				result = player;
			} // one piece to the left, and two pieces to the right of the last piece
			 
			else if (board[row][col] == player && board[row][col - 1] == player && board[row][col - 2] == player && board[row][col + 1] == player&&col-2>=0&&col+1<=size-1) {
				result = player;
			} // one piece to the right, and two pieces to the left of the last piece

			else if (board[row][col] == player && board[row][col - 1] == board[row][col] && board[row][col - 2] == board[row][col - 1] && board[row][col - 2] == board[row][col - 3]&&col - 3 >= 0) {
				result = player;
			} // three pieces to the left of the last piece

			//four in a column:
			else if (board[row][col] == player && board[row][col] == board[row + 1][col] && board[row + 1][col] == board[row + 2][col] && board[row + 2][col] == board[row + 3][col]&&row + 3 <= size - 1  ) {
				result = player;
			} // three pieces under the last piece

			else if (board[row][col] == player && board[row - 1][col] == player && board[row + 1][col] == player && board[row + 2][col] == player && row - 1 >= 0 && row + 2 <= size - 1) {
				result = player;
			} // one piece upper and two pieces lower to the last piece

			else if (board[row][col] == player && board[row - 1][col] == player && board[row - 2][col] == player && board[row + 1][col] == player && row - 2 >= 0 && row + 1 <= size - 1) {
				result = player;
			} // two pieces upper and one piece lower to the last piece

			else if (board[row][col] == player && board[row][col] == board[row - 1][col] && board[row - 1][col] == board[row - 2][col] && board[row - 3][col] == board[row - 2][col]&&row - 3 >= 0  ) {
				result = player;
			} // three pieces upper to the last piece


			// four in a diagonal:
			else if (board[row][col] == player && board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 2] && board[row][col] == board[row + 3][col + 3]&&row + 3 <= size - 1&& col + 3 <= size - 1) {
				result = player;
			} // three pieces to the lower right of last piece

			else if (board[row][col] == player && board[row - 1][col - 1] == player && board[row - 2][col - 2] == player && board[row + 1][col + 1] == player && row - 2 >= 0 && col - 2 >= 0 && row + 1 <= size - 1 && col + 1 <= size - 1) {
				result = player;
			} // two pieces to the upper left and one piece to the lower right of last piece

			else if (board[row][col] == player && board[row - 1][col - 1] == player && board[row + 1][col + 1] == player && board[row + 2][col + 2] == player && row - 1 >= 0 && col - 1 >= 0 && col + 2 <= size - 1 && row + 2 <= size - 1) {
				result = player;
			} // two pieces to the lower right and one piece to the upper left of last piece

			else if (board[row][col] == player && board[row - 1][col - 1] == player && board[row - 2][col - 2] == player && board[row - 3][col - 3] == player&&row-3>=0&&col-3>=0) {
				result = player;
			} // three pieces to the upper left of last piece


			// four in another diagonal
			else if (board[row][col] == player && board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 2][col - 2] && board[row][col] == board[row + 3][col - 3]&&row + 3 <= size - 1&& col - 3 >= 0) {
				result = player;
			} // three pieces to the lower left of the last piece
			
			else if (board[row][col] == player && board[row + 1][col - 1] == player && board[row - 1][col + 1] == player && board[row - 2][col + 2] == player&&row-2>=0&&col+2<=size-1) {
				result =player;
			} // one piece to the lower left and two pieces to the upper right of the last piece

			else if (board[row][col] == player && board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 2][col + 2] && board[row][col] == board[row - 3][col + 3]&&row - 3 >= 0 && col + 3 <= size - 1) {
				result = player;
			} // three pieces to the upper right of the last piece

			else if (board[row][col] == player && board[row + 1][col - 1]==player && board[row + 2][col - 2]==player && board[row - 1][col + 1]==player&&row+2<=size-1&&col-2>=0) {
				result = player;
			} 
			  //  one piece to the upper right and two pieces to the lower left to the last piece
			

	     // if there is no "connect four",check if there is a token space in 4 sides, if there is no space, the player who makes the last move is winner,
		 // else game is not over.
			else {
				for (i = 0; i <= size - 1; i++) {
					if (board[0][i] == 0) {
						return 0;
					}
					else {
						if (board[i][0] == 0) {
							return 0;
						}
						else {
							if (board[size - 1][i] == 0) {
								return 0;
							}
							else {
								if (board[i][size - 1] == 0) {
									return 0;
								}
								else {
									result=player;
								}
							}
						}
					}
				}
			}
		return result;
}

		void GetDisplayBoardString(int board[MAX_SIZE][MAX_SIZE], int size, char *boardString)
		{
			int i;
			int j;

			// initialse the board with space character and add elements to it
			for (i = 0; i < (size + 4)*(size + 5); i++) {
				boardString[i] = ' ';
			}

			// add a '/n' character in appropriate position
			for (j = 0; j < size + 4; j++) {
				boardString[size + 4 + j * (size + 5)] = '\n';
			}

			// add 'W' 'N' 'S' 'E' character in appropriate position
			for (j = 2; j < size + 2; j++) {
				boardString[j*(size + 5)] = 'W';
			}
			for (j = 2; j < size + 2; j++) {
				boardString[j*(size + 5) + (size + 3)] = 'E';
			}
			for (j = 2; j < size + 2; j++) {
				boardString[j] = 'N';
			}
			for (j = 2 + (size + 3)*(size + 5); j < size + 2 + (size + 3)*(size + 5); j++) {
				boardString[j] = 'S';
			}

			// add '0' '1' '2' '3'....(until size-1) in appropriate position
			for (j = 0; j < size; j++) {
				boardString[size + 7 + j] = '0' + j;
			}
			for (j = 2; j < size + 2; j++) {
				boardString[j*(size + 5) + 1] = '0' + j - 2;
			}
			for (j = 2; j < size + 2; j++) {
				boardString[j*(size + 5) + (size + 2)] = '0' + j - 2;
			}
			for (j = 0; j < size; j++) {
				boardString[(size + 2)*(size + 5) + 2 + j] = '0' + j;
			}

			// add '-' in appropriate position
			for (j = 0; j < size + 5; j++) {
				for (i = 0; i < size + 5; i++) {
					if ((j == 0 || j == 1 || j == size + 2 || j == size + 3) && (i == 0 || i == 1 || i == size + 2 || i == size + 3)) {
						boardString[j*(size + 5) + i] = '-';
					}
				}
			}

			//  change '1' to 'X' 
			//  change '2' to 'O'
			//  change '3' to '#'
			//  change empty space to '.'

			int m;
			int n;
			for (m = 0; m < size; m++) {
				for (n = 0; n < size; n++) {
					boardString[(2 + m)*(size + 5) + 2 + n] = board[m][n];
						 if (board[m][n] == 1) {
							 boardString[(2 + m)*(size + 5) + 2 + n] = 'X';
						 }
						 else if (board[m][n] == 2) {
							 boardString[(2 + m)*(size + 5) + 2 + n] = 'O';
						 }
						 else if (board[m][n] == 3) {
							 boardString[(2 + m)*(size + 5) + 2 + n] = '#';
						 }
						 else if (board[m][n] == 0) {
							 boardString[(2 + m)*(size + 5) + 2 + n] = '.';
						 }
			    }
			
			}
		


	
	// This definition is WRONG.  To avoid compiler warnings, all of the input variables have been
	// referred to below.  Fix this function by *deleting this comment* and the code below, and
	// writing a correct definition.  If you do not attempt this task, leave this definition unchanged.
	//board[0][0] = size-size;
	boardString[(size + 4)*(size + 5)] = '\0';

}

		void GetMoveBot1(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
		{  
			int lastRow;
			int lastCol;
			// add token to each position along the 'N' side, and use check if any move can make game over
			for (int i = 0; i <= size - 1; i++) {
				AddMoveToBoard(board, size, 'N', i, player, &lastRow, &lastCol);
				if (0==CheckGameOver(board, size, player, lastRow, lastCol)) {
					board[lastRow][lastCol] = 0; // if the move can not make game over, delete the move
				} 
				else if (CheckGameOver(board, size, player, lastRow, lastCol)==player) {
					*side = 'N';
					*move = i;
					return;
				}
			}

			for (int i = 0; i < size - 1; i++) {
				AddMoveToBoard(board, size, 'S', i, player, &lastRow, &lastCol);
				if (CheckGameOver(board, size, player, lastRow, lastCol) == 0) {
					board[lastRow][lastCol] = 0; // if the move can not make game over, delete the move
				}
				else if (CheckGameOver(board, size, player, lastRow, lastCol) == player) {
					*side = 'S';
					*move = i;
					return;
				}
			}

			for (int i = 0; i < size - 1; i++) {
				AddMoveToBoard(board, size, 'E', i, player, &lastRow, &lastCol);
				if (CheckGameOver(board, size, player, lastRow, lastCol) == 0) {
					board[lastRow][lastCol] = 0; // if the move can not make game over, delete the move
				}
				else if (CheckGameOver(board, size, player, lastRow, lastCol) == player) {
					*side = 'E';
					*move = i;
					return;
				}
			}

			for (int i = 0; i < size - 1; i++) {
				AddMoveToBoard(board, size, 'W', i, player, &lastRow, &lastCol);
				if (CheckGameOver(board, size, player, lastRow, lastCol) == 0) {
					board[lastRow][lastCol] = 0; // if the move can not make game over, delete the move
				}
				else if (CheckGameOver(board, size, player, lastRow, lastCol) == player) {
					*side = 'W';
					*move = i;
					return;
				}
			}

			for (int i=0;i<=size-1;i++) {
				if (board[0][i] == 0) {
					*side = 'N';
					*move = i;
					break;
				}
			
				else {
					if (board[i][0] == 0) {
						*side = 'W';
						*move = i;
						break;
					}
					else {
						if (board[size - 1][i] == 0) {
							*side = 'S';
							*move = i;
							break;
						}
						else {
							if (board[i][size - 1] == 0) {
								*side='E';
								*move = i;
							}
			
							}

						}

					}

				}

			}
			
		void GetMoveBot2(int board[MAX_SIZE][MAX_SIZE], int size, int player, char *side, int *move)
		{
			for (int i = 0; i <= size - 1; i++) {
				if (board[0][i] == 0) {
					*side = 'N';
					*move = i;
					break;
				}

				else {
					if (board[i][0] == 0) {
						*side = 'W';
						*move = i;
						break;
					}
					else {
						if (board[size - 1][i] == 0) {
							*side = 'S';
							*move = i;
							break;
						}
						else {
							if (board[i][size - 1] == 0) {
								*side = 'E';
								*move = i;
							}

						}

					}

				}

			}

		}
