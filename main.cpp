#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream> 
#include <string.h>
#include <sstream>
#include <string>
#include "BinaryTree.h"

using namespace std;
int main(int argc, char *argv[]) 
{
	string userSelect; 
	char userSelectChar,listType;
	bool exit = false;
	string subLine;
	int valueOfInt;
	float valueOfFloat;
	bool check = true;
	char caseI = 'i';
	char caseF = 'f';
	char caseS = 's';
	BinaryTree<int> listy;
	BinaryTree<float> listy2;
	BinaryTree<string> listy3;
	ifstream inFile;
	
	cout << "Enter list type(i - int, f - float, s - std:string): ";
	cin >> userSelect; 
	while (check)
	{
		 //Lines 33-39 make sure the user only inserts 1 char as a selection
		while(userSelect.size()!=1) 
		{
			cout << "Invalid command, try again!" <<endl;
			cout << "Enter a command: ";
			cin >> userSelect;
		}//while
		listType = userSelect[0];
		if (caseI == userSelect[0]) // Int case
		{
			check = false;
			inFile.open(argv[1]);
			if (!inFile.is_open()) //Error checking for if the file can be opened
			{
				cout << "Unable to open int file" << endl;
			}//if
			while (getline(inFile, subLine,' ')) //Gets each variable until it hits a space or EOF
			{
				try 
				{
					valueOfInt = stoi(subLine);
				}//try
				catch(std::invalid_argument)//Catches error if user tries to store strings into a int 
				{
					cout << "Input doesnt match file type.  Quitting..." << endl;
					return 1;
				}//catch 
				// insert method
			} // while
			cout << endl;
		}//if 
		else if (caseF == userSelect[0] ) //Float Case
		{
			check = false;
			inFile.open(argv[1]);
			if (!inFile.is_open()) //Error checking for if the file can be opened
			{
				cout << "Unable to open float file" << endl;
			}//if
			while (getline(inFile, subLine,' '))//Gets each variable until it hits a space or EOF
			{
				try 
				{
					valueOfFloat = stof(subLine);
				}//try
				catch(std::invalid_argument) //Catches error if user tries to store strings into a float
				{
					cout << "Input doesnt match file type. Quitting..." << endl;
					return 1;
				}//catch
				// insert method
			}//while 
			cout << endl;
		}//if 
		else if (caseS == userSelect[0]) //String case
		{
			check = false;
			inFile.open(argv[1]);
			if (!inFile.is_open()) //Error checking for if the file can be opened
			{
				cout << "Unable to open string file" << endl;
			}//if
			while (getline(inFile, subLine,' '))//Gets each variable until it hits a space or EOF
			{
				//insert method
			}//while
			cout << endl;
		}//if
		else //Case for if invalid command
		{
			cout << "Invalid command, try again!" <<endl;
			cout << "Enter a command: ";
			cin >> userSelect;
		}//else
	}
	inFile.close(); //close inFile no longer needed.
	cout << "Command Options \ninsert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)"<< endl;
	while (exit == false) //Loop until user enders q
	{
		cout << "Enter a Command: ";
		cin >> userSelect; 
		//Lines 114 - 120 make sure input us a 1 char string
		while(userSelect.size()!=1) 
		{
			cout << "Invalid command, try again!" <<endl;
			cout << "Enter a command: ";
			cin >> userSelect;
		}//while
		userSelectChar = userSelect[0];

		switch (userSelectChar)
			{
			case 'i': // Insert
					
				break;
			case 'd': // Delete
					
				break;
			case 'r': // Retrieve

				break;
			case 'l': // Length 
					
				break;
			case 'n': // In Order
					
				break;
			case 'p': // Pre Order
					
				break;
			case 'o': // Post Order
					
				break;
			case 's': // getNumSingleParent
 					
				break;
			case 'f'://getNumLeafNodes

				break;
			case 't': // getSumOfSubtrees

				break;
			case 'q':
				cout << "Quitting..." <<endl;
				return 0;
				exit = true;
				break;
			default:
				cout << "Invalid command, try again!" << endl;
				break;
			}
	}//while
	return 0;
} // main
