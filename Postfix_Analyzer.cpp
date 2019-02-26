#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

bool alpha(char ch);
bool digit(char ch);

int main()
{
    
    char ch, temp1, temp2;

//  Opening the file, prints and error if it failed to open.
    fstream fin("expressio.txt");   
    if(!fin.is_open())
	{
        cout << "Unable to open the file.\n";
        exit(0);
    }
    
//  Printing out the table header.
    cout << "_____________________________________________\n"; 
    cout << "| Lexemes         | Tokens                  |\n";
	cout << "|-----------------|-------------------------|\n";              
    
    while(!fin.eof())
	{
        ch = fin.get();
		
//		Checking the first char if its a number,
//		Then we look ahead to see if the next one is another number or a delimiter.
      
	    if( digit(ch)== true)
		{
			temp1 = ch;
			ch = fin.get();
			
			if(ch != '_')
			{
				temp2 = ch;
				ch = fin.get();
				
				if(ch != '_')
				{
					cout << "| " << temp1 << temp2 << ch <<"             | Integer literal         |\n";
					ch = fin.get();	
				}
				else
				{
					cout << "| " << temp1 << temp2 << "              | Integer literal         |\n";
				}
			}
			else
			{
				cout << "| " << temp1 << "               | Integer literal         |\n";
			}
		}
		
//		Checking the first char if its a letter,
//		Then we look ahead to see if the next one is another letter or a delimiter.	
	
        if(alpha(ch)== true)
		{
			temp1 = ch;
			ch = fin.get();
			if(ch != '_')
			{
				temp2 = ch;
				ch = fin.get();
				
				if(ch != '_')
				{
					cout << "| " << temp1 << temp2 << ch <<"             | Variable expression     |\n";
					ch = fin.get();	
				}
				else
				{
					cout << "| " << temp1 << temp2 << "              | Variable expression     |\n";
				}
			}	
			else
			{
				cout << "| " << temp1 << "               | Variable expression     |\n";
			}
		}			
  
		switch (ch) 
   		{ 
			case '_': // case for reading delimiters
				{
					cout << "| " << ch << "               | Delimiter               |\n";	
				} 
            	break; 
            	
            case '+': // case for reading addition
				{
					cout << "| " << ch << "               | Addition operator       |\n";	
				} 
				break;
				
			case '-': // case for reading subtraction
				{
					cout << "| " << ch << "               | Subtraction operator    |\n";	
				}
            	break; 
            	
            case '*': // case for reading multiplication
				{
					cout << "| " << ch << "               | Multiplication operator |\n";	
				} 
				break;
				
			case '/': // case for reading division
				{
					cout << "| " << ch << "               | Division operator       |\n";	
				} 
				break;			
			
			case '\n':
				break; 
				       		
			default :
				cout << "|_________________|_________________________|\n";
                break;   
   		}          
    }
   
    fin.close();   // Closes the file after we reach the end of it.
    
    return 0;
}


// This function is used to check if a character is a letter and return a boolean value.
bool alpha(char ch)
{
	if((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))
      	return true;
    else
    	return false;
	
}

// This function is used to check if a character is a number and return a boolean value.
bool digit(char ch)
{
	if( ch >= '0' && ch <= '9' )
		return true;
    else
    	return false;		
}
