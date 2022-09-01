#include <iostream>
#include <cmath> // For math calculations. 
/* This program is a basic calculator that divides, multiplies, adds, and/or subtracts decimal
and whole numbers. This doesn't allow for mixed operations so the user must select multiple 
operations in the order of operations. */

// Function prototypes: 
// Displays menu and user selects operation. 
void select_operation (int & menuNum);
// User selected number from menu. 

// Adds requested number of terms. 
double add (double & term, int & numTerms); 
// 1st parameter is the term, 2nd is the amount of terms. 

// Subtracts requested number of terms. 
double subtract (double & term, int & numTerms); 
// 1st parameter is the term, 2nd is the amount of terms. 

// Multiplies requested number of terms. 
double multiply (double & term, int & numTerms); 
// 1st parameter is the term, 2nd is the amount of terms. 

// Divides requested number of terms. 
double divide (double & term, int & numTerms); 
// 1st parameter is the term, 2nd is the amount of terms. 

/* This function asks if the user wants to exit, continue with solution from previous 
 operation or start over with new operation. */
void exit_or_continue (int & exitNum);
// 1st parameter is user selected number from menu. 

using namespace std;

int main()
{
    int menuNum; // User selected number from menu. 
    double term; // Number(s) used in operation(s).
    int numTerms; // Number of terms used in operation(s).
    int exitNum; // Number selected from menu (exit or continue). 
    
    // Call function to get menuNum; 
    select_operation(menuNum); 
    
    // Branching based on menuNum. 
    // For addition. 
    if (menuNum == 1) 
    {
        // Display sum.  
        cout << add(term, numTerms) << endl; 
        exit_or_continue(exitNum); 
    }
    
    // For subtraction. 
    else if (menuNum == 2)
    {
        // Display difference. 
        cout << subtract(term, numTerms) << endl;
        exit_or_continue(exitNum);
    }
    
    // For multiplication. 
    else if (menuNum == 3)
    {
        // Display product. 
        cout << multiply(term, numTerms) << endl; 
        exit_or_continue(exitNum);
    }
    
    // For division. 
    else if (menuNum == 4)
    {
        // Display quocient. 
        cout << divide(term, numTerms) << endl; 
        exit_or_continue(exitNum);
    }

    return 0;
}

// Function definitions:
void select_operation(int & menuNum)
{
    // Display menu. 
    cout << "Welcome to basic calculator!" << endl; 
    cout << "Enter number for the following operations: " << endl;
    cout << "1 for addition." << endl; 
    cout << "2 for subtraction." << endl;
    cout << "3 for multiplication." << endl;
    cout << "4 for division." << endl; 
    cin >> menuNum; 
    
    // Validate that menuNum is 1-4. 
    while (menuNum < 1 || menuNum > 4)
    {
        // Display prompt for menuNum reentry. 
        cout << "Must enter number from menu. Try again." << endl;
        cout << "Enter number from menu: "; 
        cin >> menuNum; 
    }
    
}

double add (double & term, int & numTerms)
{
    int counter(0); // Counts number of terms. 
    double sum; // Sum of terms. 
    
    // Display prompt. 
    cout << "Enter number of terms to add: "; 
    cin >> numTerms; 
    
    // Validate that numTerms isn't less than or = 0. 
    while (numTerms <= 1)
    {
        cout << "Invalid. Number of terms be at least 2." << endl;
        cout << "Enter number of terms to add: "; 
        cin >> numTerms; 
    }
    
    cout << "Enter terms: ";
    
    // Loop term entry and addition of terms. 
    while (counter < numTerms)
    {
        cin >> term; 
        sum = term + sum; 
        counter++;
    }
    
    // Display sum. 
    cout << "Sum: ";
    return sum; 
}

double subtract (double & term, int & numTerms)
{
    int counter(0); // Counts number of terms. 
    double difference(0); // Difference of terms. 
    
    // Display prompt. 
    cout << "Enter number of terms to subtract: "; 
    cin >> numTerms; 
    
    // Validate that numTerms isn't less than or = 0. 
    while (numTerms <= 1)
    {
        cout << "Invalid. Number of terms be at least 2." << endl;
        cout << "Enter number of terms to subtract: "; 
        cin >> numTerms; 
    }
    
    cout << "Enter terms (in order you want to subtract them in): ";
    
    // Loop term entry and subtraction of terms. 
    while (counter < numTerms)
    {
        cin >> term; 
        
        // Branching to account for first term. 
        if (counter == 0)
        {
            difference = term; 
        }
        
        else 
        {
            difference = difference - term; 
        }
        counter++; 
    }
    
    // Display difference. 
    cout << "Difference: ";
    return difference;
}

double multiply (double & term, int & numTerms)
{
    int counter(0); // Counts number of terms. 
    double product(1); // Product of terms. 
    
    // Display prompt. 
    cout << "Enter number of terms to multiply: "; 
    cin >> numTerms; 
    
    // Validate that numTerms isn't less than or = 0. 
    while (numTerms <= 1)
    {
        cout << "Invalid. Number of terms be at least 2." << endl;
        cout << "Enter number of terms to multiply: "; 
        cin >> numTerms; 
    }
    
    cout << "Enter terms: ";
    
    // Loop term entry and multiplication of terms. 
    while (counter < numTerms)
    {
        cin >> term; 
        product = product * term; 
        counter++; 
    }
    
    // Display product. 
    cout << "Product: "; 
    return product;
}

double divide (double & term, int & numTerms)
{
    int counter(0); // Counts number of terms. 
    double quocient; // Quocient of terms. 
    int counter2(0); // Counter for divide by zero situation. 
    
    // Display prompt. 
    cout << "Enter number of terms to divide: "; 
    cin >> numTerms; 
    
    // Validate that numTerms isn't less than or = 0. 
    while (numTerms <= 1)
    {
        cout << "Invalid. Number of terms be at least 2." << endl;
        cout << "Enter number of terms to divide: "; 
        cin >> numTerms; 
    }

    cout << "Enter terms (in order you want to divide them in): ";
    
    // Loop term entry and division of terms. 
    while (counter < numTerms)
    {
        cin >> term;
        
        // Branching for 1st term (remains the same) vs later terms operation. 
        if (counter == 0)
        {
            quocient = term; 
        }
        
        else {
            quocient = quocient / term;
            
            // Branch for divide by zero error. 
            if (term == 0)
            {
               cout << "Error. Tried to divide by zero." << endl;
            }
        }
        
        counter++; 
    }
    
    // Display quocient. 
    cout << "Quocient: "; 
    return quocient;
}

void exit_or_continue (int & exitNum)
{
    int menuNum; // User selected number from menu (welcome menu). 
    double term; // Number(s) used in operation(s).
    int numTerms; // Number of terms used in operation(s).
    // Display prompt. 
    cout << "Enter 0 to exit calculator, 1 to calculate a new operation: "; 
    cin >> exitNum;  
    
    // Loop to validate input. 
    while (exitNum < 0 || exitNum > 1)
    {
        cout << "Invalid input. Please enter number on the menu." << endl;
        cout << "Enter 0 to exit calculator, 1 to calculate a new operation: "; 
        cin >> exitNum; 
    }
    
    // Branching based off of menu options. 
    if (exitNum == 0)
    {
        cout << "Thank you for using the basic calculator! Goodbye!" << endl;
    }
    
    else if (exitNum == 1)
    {
    
        // Call function to get menuNum; 
        select_operation(menuNum); 
    
        // Branching based on menuNum. 
        // For addition. 
        if (menuNum == 1) 
        {
            // Display sum.  
            cout << add(term, numTerms) << endl; 
            exit_or_continue(exitNum);
        }
    
        // For subtraction. 
        else if (menuNum == 2)
        {
            // Display difference. 
            cout << subtract(term, numTerms) << endl;
            exit_or_continue(exitNum);
        }
    
        // For multiplication. 
        else if (menuNum == 3)
        {
            // Display product. 
            cout << multiply(term, numTerms) << endl; 
            exit_or_continue(exitNum);
        }
    
        // For division. 
        else if (menuNum == 4)
        {
            // Display quocient. 
            cout << divide(term, numTerms) << endl;
            exit_or_continue(exitNum);
        }
    }
}