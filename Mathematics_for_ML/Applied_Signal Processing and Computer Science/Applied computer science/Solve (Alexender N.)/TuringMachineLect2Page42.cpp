#include <stdio.h>

void vPrintTape (int iIteration, 
                 char * pcTape,
				 int iState)
{
	int iIndex = 0;
    printf ("%3d: ", iIteration);
	for (iIndex = 0; iIndex < 100; iIndex++)
	{
	    if (pcTape[iIndex] != '#')
		    printf ("%c", pcTape[iIndex]);
	}
	printf (" => State %d\n", iState);
}

int main ()
{
    char acInputTape[100];
	int iIndex = 0;
	int iState = 0;
	int iStop = 0;
	int iIteration = 0;

	for (iIndex = 0; iIndex < 100; iIndex++)
	    acInputTape[iIndex] = '#';
    acInputTape[50] = '|';
    acInputTape[51] = '|';
    acInputTape[52] = '|';
    acInputTape[53] = '|';
    acInputTape[54] = '|';
	
	iIndex = 50;
    while (iStop != 1)	
	{
	    vPrintTape (iIteration, acInputTape, iState);
	    switch (iState)
		{
		    case 0:
			    switch (acInputTape[iIndex])
				{
				    case '|':
					    iState = 1;
						acInputTape[iIndex] = 'X';
						iIndex--;
					    break;
				    case '#':
					    iState = 2;
						acInputTape[iIndex] = '#';
						iIndex--;
					    break;
				    case 'X':
					    iState = 0;
						acInputTape[iIndex] = 'X';
						iIndex++;
					    break;
				    case '0':
					    iState = 0;
						acInputTape[iIndex] = '0';
						iIndex++;
					    break;
				    case '1':
					    iState = 0;
						acInputTape[iIndex] = '1';
						iIndex++;
					    break;
				}
			    break;
			case 1:
			    switch (acInputTape[iIndex])
				{
				    case '#':
					    iState = 0;
						acInputTape[iIndex] = '1';
						iIndex++;
					    break;
				    case '0':
					    iState = 0;
						acInputTape[iIndex] = '1';
						iIndex++;
					    break;
				    case '1':
					    iState = 1;
						acInputTape[iIndex] = '0';
						iIndex--;
					    break;
				    case 'X':
					    iState = 1;
						acInputTape[iIndex] = 'X';
						iIndex--;
					    break;
				}
			    break;
			case 2:
			    switch (acInputTape[iIndex])
				{
				    case 'X':
					    iState = 2;
						acInputTape[iIndex] = '#';
						iIndex--;
					    break;
				    case '1':
					    iState = 3;
						acInputTape[iIndex] = '1';
						iIndex;
					    break;
				    case '0':
					    iState = 3;
						acInputTape[iIndex] = '0';
						iIndex;
					    break;
				}
			    break;
			case 3:
			    iStop = 1;
				break;
		}
		iIteration++;
	}
    
    return 0;
}

// Example: Initial tape #|||||#
// Iteration: Tape => State
//  0: ||||| => State 0
//  1: X|||| => State 1
//  2: 1X|||| => State 0
//  3: 1X|||| => State 0
//  4: 1XX||| => State 1
//  5: 1XX||| => State 1
//  6: 0XX||| => State 1
//  7: 10XX||| => State 0
//  8: 10XX||| => State 0
//  9: 10XX||| => State 0
// 10: 10XX||| => State 0
// 11: 10XXX|| => State 1
// 12: 10XXX|| => State 1
// 13: 10XXX|| => State 1
// 14: 11XXX|| => State 0
// 15: 11XXX|| => State 0
// 16: 11XXX|| => State 0
// 17: 11XXX|| => State 0
// 18: 11XXXX| => State 1
// 19: 11XXXX| => State 1
// 20: 11XXXX| => State 1
// 21: 11XXXX| => State 1
// 22: 10XXXX| => State 1
// 23: 00XXXX| => State 1
// 24: 100XXXX| => State 0
// 25: 100XXXX| => State 0
// 26: 100XXXX| => State 0
// 27: 100XXXX| => State 0
// 28: 100XXXX| => State 0
// 29: 100XXXX| => State 0
// 30: 100XXXX| => State 0
// 31: 100XXXXX => State 1
// 32: 100XXXXX => State 1
// 33: 100XXXXX => State 1
// 34: 100XXXXX => State 1
// 35: 100XXXXX => State 1
// 36: 101XXXXX => State 0
// 37: 101XXXXX => State 0
// 38: 101XXXXX => State 0
// 39: 101XXXXX => State 0
// 40: 101XXXXX => State 0
// 41: 101XXXXX => State 0
// 42: 101XXXXX => State 2
// 43: 101XXXX => State 2
// 44: 101XXX => State 2
// 45: 101XX => State 2
// 46: 101X => State 2
// 47: 101 => State 2
// 48: 101 => State 3
