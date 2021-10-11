/*
* This program will randomly determine the number of different colored marbles within a user-defined number of bags
*  06/29/2021
*/

//HEADER FILES
#include "cpp_fn_marbles.h"

//MAIN PROGRAM
int main()
{
  displayMessage("This program will randomly determine the number of different colored marbles within a user-defined number of bags\n");
  int bags = (getNumBags());
  table(bags);
  displayMessage("Program is now exiting. Goodbye!");

  return 0;
}