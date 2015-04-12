#include "valero-assn4.h"
#include "barron-assn4.h"
using namespace std;

//GLOBAL CONSTANTS

//Declare our predefined array size of 100,000
const int SIZE 	= 100000;
//minimum value for numbers in array
const int MINIMUM = 1;
//maximum value for numbers in array
const int MAXIMUM = 30000;

//COMMON FUNCTION PROTOTYPES

//Function that verifies that an array is sorted in ascending order
bool verifySorted(int* arr, int size);

//Function to display the user menu
void printDisplay();

//Function that displays a brief description of what the program does
void displayHeader();
//Function to process the users input
string processInput();

//Function that takes a string and returns the two sort method choices
char* choices(string s);

//Function that prompts user for number of times to execute sorts
int sortInput();

//Function that executes a sort based on a character input and returns the number of tics it took to run
int executeSort(char choice, int* arr, int size);

//Function to return a string based on the sort char passed in
string parseChoice(char c);
