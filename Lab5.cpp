/*********************************************************************
 ** Program name: Lab5.cpp
 ** Author: reuben youngblom
 ** Date: 2/12/17
 ** Description: main implementation file for Lab 5
 *********************************************************************/


#include <iostream>
#include <cstring>
using namespace std;

/*********************************************************************
this function reverses a string.  It takes the string a recursively takes the beginning of the string and puts it at the end, and when it's done returns the string.  This function is one that I looked up "reversing string" to see how to do it non-recursively but this function came up so I modified it to fit my needs.  So the structure of it was taken from google (stack overflow, if I remember properly)
 *********************************************************************/
string reverse(string reverser)
{
    if (reverser.length() == 1)  //this makes it easy.  If it's just one character, it just prints it back out because it's reversed already.
    {
        return reverser;  //and returns it
    }
    else  //but if it's longer...
    {
        return reverse(reverser.substr(1,reverser.length())) + reverser.at(0);   //calls reverse function again, but sends the first letter to the end, and sends a substring (starting from the "next" next letter, which moves down the string as things get chopped off the front so eventually things move back-to-front.
    }
}


/*********************************************************************
 this function sums an array.  It takes in the array and length, and kills the function whenever length is zero.  When it's not, it takes the sum and adds it to the next lowest array spot until the array gets to zero, at which point it spits the sum back out.  I adapted this code from Stack Overflow.
 *********************************************************************/

int yarra(int arraySum[], int length){
 
        if (length == 0)// base case
        {
            return 0;
        }
    
        else //if array is longer than zero...
        {
            int sum = arraySum[length-1];  // the sum int takes the array minus one place down
            return sum + yarra(arraySum, length - 1);  //and recursilve y sends that back in to be re-added to the sum (so basically, every time through it adds the next lowest array position to the sum integer
        }
    }



/*********************************************************************
 this function the elements of a triangle.  I noticed that the triangle element total is just x! where x is the rows, so this one was pretty easy.  just sums along down the numbers by removing one each time.
 *********************************************************************/

int triangleAdd(int x)
{
    if(x != 0)  //base case
        return x + triangleAdd(x - 1);  //sums the current integer, and then subtracts one and recursively adds that number, and so on.
    return 0;
}


int main() {

    bool checkBool = true;  //for the menu
    int select, triangle;
    int arrayInt=0;  //ints for the menu
    int arrayFinal [99999];
    string userReverse;  //holds user reverseable string

    
    
        while (checkBool == true)   //only exits the menu when this is false (case 4)
    {
        
        cout << "Please enter an option from 1-4" << endl;  //instructions
        cout << "To reverse a string, select 1" << endl;
        cout << "To add numbers, select 2" << endl; //in the form of a menu
        cout << "To see how many objects are in a triangle, press 3" << endl;
        cout << "To exit the program, choose 4" << endl;
        
        cin >> select;  //takes user input
        
    /*i took this menu from Lab 4 and modified it to work for this code.  it loops through while the bool is true but once the bool is false (case 4) it ends.*/
        
        switch (select)  //menu
        {
        case 1:
                {
                    cout << "please enter a string to reverse:" << endl;
                    cin >> userReverse;  //takes in string
                    cout << reverse(userReverse);  //and sends to reverse function
                    cout << " /n";   //outputs newline
                    cout << endl;
                    
                    break;
                }
        case 2:
            {
                int arrayInt=0;  //ints for the menu

                int counter = 0; // counter for array
                
                cout << "please enter some numbers to add and then enter -1 to end:" << endl;  //takes in numbers
                
                while (arrayInt >= 0)
                {
                    cin >> arrayInt;  //takes in user input
                    
                    arrayFinal[counter] = arrayInt;  //and places it into the array
                    
                    counter++;  //and counts number of times through and send that to the array function
                    
                }
                

                cout << yarra(arrayFinal, counter) +1;  //sends the test array to the array sum function
                cout << endl;
                break;
            }
        case 3:
            {
                cout<< "How many rows should your triangle have?" << endl;
                cin >> triangle;  //takes in input
                cout << triangleAdd (triangle);  //and sends it to trangleadd function
                cout << endl;
                break;
            }
        case 4: //if user chooses this one, bool switches to false and menu loop will end
            {
                checkBool = false;
                break;
            }

        }
        
    }
    
    return 0;
}
