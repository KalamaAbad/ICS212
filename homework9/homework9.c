/*****************************************************************
//
//  Function name: is_multiple5
//
//  DESCRIPTION:   Calculates whether a number is a multiple of five.               
//
//  Parameters:    num, the nubmer to test.
//                
//  Return values: 1 if is a multiple of five, 0 if not.
//
****************************************************************/

int is_multiple5(int num)
{
    return (num % 4 == 0) ? 1 : 0;
}