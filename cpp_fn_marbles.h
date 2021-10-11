/*
* This file defines custom functions to be used later in the main program
*  Johnny Nguyen
*  06/29/2021
*/

//HEADER FILES
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//GLOBAL CONSTANTS
int MIN_BAGS = 5;
int MAX_BAGS = 15;
int MIN_MARBLES = 180;
int MAX_MARBLES = 220;
string FILENAME = "MarblesReport.txt";

//FUNCTION PROTOTYPES
void seed();
void header(ofstream& f);
void row(int& r, int& o,int& y,int& g,int& b,int& p,ofstream& f);
int rng(int upper, int lower);
void footer(int& r,int& o,int& y,int& g,int& b,int& p,ofstream& f);

//FUNCTION DEFINITIONS
void displayMessage(string msg)
/*
* PURPOSE: Displays a simple message
* RETURNS: n/a
* IN: msg, to be displayed
* OUT: n/a
*/
{
  cout << (msg);
}

int getNumBags()
/*
* PURPOSE: prompt user for number of bags
* RETURNS: number of bags
* IN: n/a
* OUT: n/a
*/
{
  int num;
  cout << "Please enter a number of bags between 5 and 15: ";
  cin >> num;
  while (num < MIN_BAGS || num > MAX_BAGS)
  {
    cout << "Please enter a number between the specified range: ";
    cin >> num;
  }
  return num;
}

void table(int bags)
/*
* PURPOSE: controls generation of table by calling other functions
* RETURNS: n/a
* IN: bags, number of bags provided by user
* OUT: n/a
*/
{
  int r,o,y,g,b,p;
  r=0;
  o=0;
  y=0;
  g=0;
  b=0;
  p=0;
  seed();
  ofstream f;
  f.open(FILENAME);
  header(f);
  for(int i = 0; i < bags ; i++)
  {
    row(r,o,y,g,b,p,f);
  }
  footer(r,o,y,g,b,p,f);
  f.close();
}

void seed()
/*
* PURPOSE: seeds random number generator
* RETURNS: n/a
* IN: n/a
* OUT: n/a
*/
{
  srand(time(0));
}

void header(ofstream& f)
/*
* PURPOSE: display table header and writes it to file
* RETURNS: n/a
* IN: f, the output file
* OUT: n/a
*/
{
  cout << setw(3) << "BAG" << setw(6) << "RED" << setw(6) << "ORG" << setw(6) << "YEL" << setw(6) <<" GRN" << setw(6) << "BLU" << setw(6) << "PPL" << setw(6) <<  "TOT" << endl << "---------------------------------------------"<< endl;
  f << setw(3) << "BAG" << setw(6) << "RED" << setw(6) << "ORG" << setw(6) << "YEL" << setw(6) <<" GRN" << setw(6) << "BLU" << setw(6) << "PPL" << setw(6) <<  "TOT" << endl << "---------------------------------------------"<< endl;
}

void row(int& r, int& o,int& y,int& g,int& b,int& p,ofstream& f)
/*
* PURPOSE: displays a table row and writes it to the file
* RETURNS: n/a
* IN:r count of red marbles, o, count of orange marbles, y, count of yellow marbles, g, count of green marbles, b, count of blue marbles, p, count of purple marbles, f, the output file
* OUT: n/a
*/
{
  int a,m,tot, rr, oo, yy, gg, bb, pp;
  rr = 0;
  oo = 0;
  yy = 0;
  gg = 0;
  bb = 0;
  pp = 0;
  static int id = 1;
  a = (rng(MIN_MARBLES,MAX_MARBLES));
  for (int i = 0; i < a ; i++)
  {
    m = rng(6,1);
    switch(m)
    {
      case 1:
        rr++;
        break;
      case 2:
        oo++;
        break;
      case 3:
        yy++;
        break;
      case 4:
        gg++;
        break;
      case 5:
        bb++;
        break;
      case 6:
        pp++;
        break;
    }
    tot = rr + oo + yy + gg + bb +pp;
  }
  r+= rr;
  o+= oo;
  y+= yy;
  g+= gg;
  b+= bb;
  p+= pp;
  cout<< setw(3) << id << setw(6) << rr << setw(6) << oo << setw(6) << yy << setw(6) << gg << setw(6) << bb << setw(6) << pp <<  setw(6) << tot << endl;
  f << setw(3) << id << setw(6) << rr << setw(6) << oo << setw(6) << yy << setw(6) << gg << setw(6) << bb << setw(6) << pp <<  setw(6) << tot << endl;
  id++;
}

int rng(int upper, int lower)
/*
* PURPOSE: Generates and returns a random number within given bounds
* RETURNS: num, random number
* IN: upper, upper bound for number generator, lower, lower bound for number generator
* OUT: n/a
*/
{
  int num;
  num = (rand() % (upper - lower + 1)) + lower;
  return num;
}

void footer(int& r,int& o,int& y,int& g,int& b,int& p,ofstream& f)
/*
* PURPOSE: displays the table footer and writes it to the file
* RETURNS: n/a
* IN: r count of red marbles, o, count of orange marbles, y, count of yellow marbles, g, count of green marbles, b, count of blue marbles, p, count of purple marbles, f, the output file
* OUT: n/a
*/
{
  int tot;
  tot = r + o + y + g + b +p;
  cout << "---------------------------------------------" << endl;
  cout << setw(3) << "TOT" << setw(6) << r << setw(6) << o << setw(6) << y << setw(6) << g << setw(6) << b << setw(6) << p << setw(6) << tot << setw(6) << endl;
  f << "---------------------------------------------" << endl;
  f << setw(3) << "TOT" << setw(6) << r << setw(6) << o << setw(6) << y << setw(6) << g << setw(6) << b << setw(6) << p << setw(6) << tot << setw(6) << endl;
}

