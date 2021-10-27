#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <fstream> 
#include <string.h>
#include <sstream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;
int main(int argc, char *argv[]) 
{
	string userSelect; 
	char userSelectChar,listType;
	bool exit = false;
	string subLine, upperBound, lowerBound;
	int valueOfInt;
	float valueOfFloat;
	bool check = true;
	char caseI = 'i';
	char caseF = 'f';
	char caseS = 's';
	DoublyLinkedList<int> listy;
	DoublyLinkedList<float> listy2;
	DoublyLinkedList<string> listy3;
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
				listy.insertItem(valueOfInt);
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
				listy2.insertItem(valueOfFloat);
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
				listy3.insertItem(subLine);
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
	cout << "Command Options \ninsert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), printReverse(r), swapAtl(s), quit (q)"<< endl;
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
			case 'i': //Insert
					cout<< "Enter Item to insert: ";
					cin >> userSelect; 
					if(caseI == listType)
					{
						valueOfInt = stoi(userSelect);
						listy.insertItem(valueOfInt);
						listy.print();
					}//if
					else if(caseF ==listType)
					{
						valueOfFloat = stof(userSelect);
						listy2.insertItem(valueOfFloat);
						listy2.print();
					}//if
					else
					{
						listy3.insertItem(userSelect);
						listy3.print();
					}//else
				break;
			
			case 'd': //Delete
					cout<< "Enter Item to delete: ";
					cin >> userSelect; 
					if(caseI == listType)
					{
						valueOfInt = stoi(userSelect);
						listy.deleteItem(valueOfInt);
						if(listy.lengthIs() > 0 )
						{
							listy.print();
						}//if
						else
						{
							cout<<endl;
						}//else 

					}
					else if(caseF ==listType)
					{
						valueOfFloat = stof(userSelect);
						listy2.deleteItem(valueOfFloat);
						if(listy2.lengthIs() > 0 )
						{
							listy2.print();
						}//if
						else
						{
							cout<<endl;
						}//else 
					}
					else
					{
						listy3.deleteItem(userSelect);
						if(listy3.lengthIs() > 0 )
						{
							listy3.print();
						}//if
						else
						{
							cout<<endl;
						}//else 
					}
				break;
			case 'l': //Length
					if(caseI == listType)
					{
						cout << "The length is: " << listy.lengthIs() << endl;
					}//if
					else if(caseF ==listType)
					{
						cout << "The length is: " << listy2.lengthIs()<< endl;
					}//if
					else
					{
						cout << "The length is: " << listy3.lengthIs()<< endl;
					}//else 
				break;
			case 'p':
					if(caseI == listType)
					{
						listy.print();
					}//if
					else if(caseF ==listType)
					{
						listy2.print();
					}//if
					else
					{
						listy3.print();
					}//else 
				break;
			case 'b':
					cout<< "Enter lower bound: "; 
					cin >> lowerBound;
					cout << "Enter upper bound: ";
					cin >> upperBound;
					if(caseI == listType)
					{	
						int upper,lower; 
						upper = stoi(upperBound);
						lower = stoi(lowerBound);
						listy.deleteSubsection(lower,upper);
					}//if
					else if(caseF ==listType)
					{	
						float upper,lower; 
						upper = stof(upperBound);
						lower = stof(lowerBound);
						listy2.deleteSubsection(lower,upper);
					}//if
					else
					{
						listy3.deleteSubsection(lowerBound,upperBound);
					}//else 
				break;
			case 'm':
					if(caseI == listType)
					{
						listy.mode();
					}//if
					else if(caseF ==listType)
					{
						listy2.mode();
					}//if
					else
					{
						listy3.mode();
					}//else 
				break;
			case 'r':
					if(caseI == listType)
					{
						listy.printReverse();
					}//if
					else if(caseF ==listType)
					{
						listy2.printReverse();
					}//if
					else
					{
						listy3.printReverse();
					}//else 
				break;
			case 's':
					if(caseI == listType)
					{
						listy.swapAlternate();
					}//if
					else if(caseF ==listType)
					{
						listy2.swapAlternate();
					}//if
					else
					{
						listy3.swapAlternate();
					}//else
				break;
			case 'q':
				cout << "Quitting..." <<endl;
				listy.~DoublyLinkedList();
				listy2.~DoublyLinkedList();
				listy3.~DoublyLinkedList();
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
