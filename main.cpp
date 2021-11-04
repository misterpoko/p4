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
  string subLine; 
	bool exit = false;
  bool check = true;
  bool found = false;
	int valueOfInt;
  int length; 
	float valueOfFloat;
 	char userSelectChar,listType;
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
				listy.insert(valueOfInt);
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
				listy2.insert(valueOfFloat);
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
				listy3.insert(subLine);
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
			case 'i': //Insert
				cout<< "Enter Item to insert: ";
				cin >> userSelect; 
				if(caseI == listType)
				{
					valueOfInt = stoi(userSelect);
					listy.insert(valueOfInt);
          cout << "In-Order:  ";
          listy.inOrder();
          cout << endl << endl ;
				}//if
				else if(caseF ==listType)
				{
					valueOfFloat = stof(userSelect);
					listy2.insert(valueOfFloat);
          cout << "In-Order:  ";
          listy2.inOrder();
          cout << endl << endl ;
				}//if
				else
				{
					listy3.insert(userSelect);
          cout << "In-Order:  ";
          listy3.inOrder();
          cout << endl << endl;
				}//else
				break;
			case 'd': // Delete
				cout<< "Enter Item to Delete: ";
				cin >> userSelect; 
				if(caseI == listType)
				{
					valueOfInt = stoi(userSelect);
					listy.deleteItem(valueOfInt);
				}//if
				else if(caseF ==listType)
				{
					valueOfFloat = stof(userSelect);
					listy2.deleteItem(valueOfFloat);
				}//if
				else
				{
					listy3.deleteItem(userSelect);
				}//else
				break;
			case 'r': // Retrieve retrieve
        found = false;
        cout<< "Item to be retrieved: ";
				cin >> userSelect; 
				if(caseI == listType)
				{
					valueOfInt = stoi(userSelect);
					listy.retrieve(valueOfInt, found);
          if(found == true)
          {
            cout << "Item in tree" << endl; 
          }
          else 
          {
            cout << "Item not in tree" << endl;
          } 
				}//if
				else if(caseF ==listType)
				{
					valueOfFloat = stof(userSelect);
					listy2.retrieve(valueOfFloat, found);
          if(found == true)
          {
            cout << "Item in tree" << endl; 
          }
          else 
          {
            cout << "Item not in tree" << endl;
          } 
				}//if
				else
				{
					listy3.retrieve(userSelect,found);
          if(found == true)
          {
            cout << "Item in tree" << endl; 
          }
          else 
          {
            cout << "Item not in tree" << endl;
          } 
				}//else
				break;
			case 'l': // Length 
				if(caseI == listType)
				{
					length = listy.getLength();
          cout << "Tree Length: " << length << endl; 
				}
				else if(caseF ==listType)
				{
					length = listy2.getLength();
				  cout << "Tree Length: " << length << endl; 
				}
				else 
				{
					length = listy3.getLength(); 
					cout << "Tree Length: " << length << endl; 
				}
				break;
			case 'n': // In-Order
				if(caseI == listType)
				{
          cout << "In-Order:  ";
					listy.inOrder();
          cout << endl << endl ;
				}				
				else if(caseF ==listType)
				{
          cout << "In-Order:  ";
					listy2.inOrder();
          cout << endl << endl ;
				}
				else 
				{
          cout << "In-Order:  ";
					listy3.inOrder(); 
          cout << endl << endl ;
				}
				break;
					
			case 'p': // Pre-Order
				if(caseI == listType)
				{
          cout << "Pre-Order:  ";
					listy.preOrder();
          cout << endl << endl ;
				}
				else if(caseF ==listType)
				{
          cout << "Pre-Order:  ";
					listy2.preOrder();
          cout << endl << endl ;
				}
				else 
				{
          cout << "Pre-Order:  ";
					listy3.preOrder(); 
          cout << endl << endl ;
				}
				break;
			case 'o': // Post-Order
				if(caseI == listType)
				{
          cout << "Post-Order:  ";
					listy.postOrder();
          cout << endl << endl ;
				}
				else if(caseF ==listType)
				{
          cout << "Post-Order:  ";
					listy2.postOrder();
          cout << endl << endl ;
				}
				else 
				{
          cout << "Post-Order:  ";
					listy3.postOrder(); 
          cout << endl << endl ;
				}
				break;
			case 's': // getNumSingleParent 
 					if(caseI == listType)
				{
					listy.getNumSingleParent();
					cout << endl;
				}
				else if(caseF ==listType)
				{
					listy2.getNumSingleParent();
					cout << endl;
				}
				else 
				{
					listy3.getNumSingleParent(); 
					cout << endl;
				}
				break;
			case 'f'://getNumLeafNodes 
        if(caseI == listType)
				{
					listy.getNumLeafNodes();
					cout << endl;
				}
				else if(caseF ==listType)
				{
					listy2.getNumLeafNodes();
					cout << endl;
				}
				else 
				{
					listy3.getNumLeafNodes(); 
					cout << endl;
				}
				break;
			case 't': // getSumOfSubtrees
        cout << "Item to get sum of subtrees: ";
        cin >> userSelect;
        if(caseI == listType)
				{
         	valueOfInt = stoi(userSelect);
					listy.getSumOfSubtrees(valueOfInt);
					cout << endl;
				}
				else if(caseF ==listType)
				{
          valueOfFloat = stof(userSelect);
					listy2.getSumOfSubtrees(valueOfFloat);
					cout << endl;
				}
				else 
				{
				  cout << "String sum not supported" << endl << endl; 
				}
				break;
			case 'q':
				listy.~BinaryTree();
				listy2.~BinaryTree();
				listy3.~BinaryTree();
				cout << "Quitting..." <<endl;
				return 0;
				exit = true;
				break;
			default:
				cout << "Command not recognized. Try again" << endl;
				break;
			}
	}//while
	return 0;
} // main
