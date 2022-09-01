#include <iostream>
#include <cmath> // For calculations. 
using namespace std;
/* Computes the requested volume of a 3d shape based on user input*/

// Function prototypes:
// Displays shape menu and reads in the user input for the requested shape.
void user_entry(const string & prompt, int & shapeNum); 
// 1st parameter is user entry for requested shape. 

// Calculates volume of a cylinder. 
double vol_cylinder(double r, double h);
// 1st parameter is radius, 2nd is height. 

// Calculates volume of a sphere. 
double vol_sphere(double r); 
// 1st parameter is radius. 

// Calculates volume of triangular prism. 
double vol_triprism(double b, double h, double l); 
// 1st parameter is base, 2nd is height, 3rd is length. 

// Calculates volume of a cone. 
double vol_cone(double r, double h); 
// 1st parameter is radius, 2nd is height. 

// Calculates volume of a cube. 
double vol_cube(double l); 
// 1st parameter is length. 

// Calculates volume of rectangular prism.
double vol_rectprism(double l, double w, double h); 
// 1st parameter is length, 2nd is width, 3rd is height. 

// Calculates volume of a pyramid. 
double vol_pyramid(double l, double w, double h); 
// 1st parameter is length, 2nd is width, 3rd is height. 

// Sees if program wants to exit or continue. 
void exit_or_continue(const string & prompt, int & exitNum); 
// 1st parameter is user prompt, 2nd is exit or continue number. 

int main()
{
    int shapeNum; // User entry for shape selection. 
    int exitNum; // User entry for exit or continue. 
    double l; // Variable for length. 
    double w; // Variable for width. 
    double h; // Variable for height. 
    double r; // Variable for radius. 
    double b; // Variable for base. 
    
    // Call function to display menu. 
    user_entry("Welcome to 3D volume calculator!", shapeNum); 
    
    // Create branching for menu selection. 
    // Cylinder branch:
    if(shapeNum == 1)
    {
        // User prompt. 
        cout << "Enter radius and height: "; 
        cout << r << h; 
        
        //While loop to make sure input is valid. 
        while(r <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl; 
            cout << "Enter radius and height: "; 
            cin >> r >> h; 
        }
        
        cout << endl; 
        
        // Display result. 
        cout << "Volume of cylinder is " << vol_cylinder(r, h) / M_PI << "π ("; 
        cout << vol_cylinder(r, h) << ") cubic units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum);
    }
    
    // Sphere branch. 
    else if(shapeNum == 2)
    {
        // User prompt. 
        cout << "Enter radius: "; 
        cin >> r; 
        
        // While loop to make sure input is valid. 
        while(r <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter radius: "; 
            cin >> r; 
        }
        
        cout << endl; 
        
        // Display result. 
        cout << "Volume of sphere is " << pow(r,3) << " * (4/3)π ("; 
        cout << vol_sphere(r) << ") cubic units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
    }
    
    // Triangular prism branch. 
    else if(shapeNum == 3)
    {
        cout << "Enter base, height, and length: "; 
        cin >> b >> h >> l; 
        
        // While loop to validate input. 
        while(b <= 0 || h <= 0 || l <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter base, height, and length: "; 
            cin >> b >> h >> l; 
        }
        
        cout << endl; 
        
        // Display result. 
        cout << "Volume of triangular prism is " << vol_triprism(b, h, l); 
        cout << " square units."; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum);
        
    }
    
    // Cone branch. 
    else if (shapeNum == 4)
    {
        cout << "Enter radius and height: "; 
        cin >> r >> h; 
        
        // While loop to validate input. 
        while(r <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter radius and height: "; 
            cin >> r >> h; 
        }
        
        cout << endl; 
        
        // Displays result. 
        cout << "Volume of cone is " << r * h;
        cout << " / 3 * π (" << vol_cone(r, h) << ") cubic units." << endl;
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
         
        
    }
    
    // Cube branch. 
    else if (shapeNum == 5)
    {
        cout << "Enter length: ";
        cin >> l; 
        
        // While loop to validate input. 
        while(l <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter length: "; 
            cin >> l; 
        }
        
        cout << endl;
        
        // Display result. 
        cout << "Volume of cube is " << vol_cube(l) << " cubic units." << endl;
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape", exitNum); 
    }
    
    // Rectangular prism branch. 
    else if (shapeNum == 6)
    {
        cout << "Enter length, width, and height: ";
        cin >> l >> w >> h;
        
        // While loop to validate input. 
        while (l <= 0 || w <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter length, width, and height: "; 
            cin >> l >> w >> h; 
        }
        
        cout << endl;
        
        // Display result. 
        cout << "Volume of rectangular prism is " << vol_rectprism(l, w, h); 
        cout << " cubic units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
    }
    
    // Pyramid branch. 
    else if (shapeNum == 7)
    {
        cout << "Enter length, width, and height: "; 
        cin >> l >> w >> h; 
        
        // While loop to validate input. 
        while(l <= 0 || w <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter length, width, and height: "; 
            cin >> l >> w >> h; 
        }
        
        cout << endl;
        
        // Display result. 
        cout << "Volume of pyramid is " << vol_pyramid(l, w, h); 
        cout << " square units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
    }

    return 0;
}

// Function definitions:
void user_entry(const string & prompt, int & shapeNum) 
{
    // User prompt.
    cout << prompt; 
    cout << "Shapes available: " << endl; 
    cout << "Enter 1 for cylinder: " << endl;
    cout << "Enter 2 for sphere: " << endl; 
    cout << "Enter 3 for triangular prism: " << endl;
    cout << "Enter 4 for cone: " << endl;
    cout << "Enter 5 for cube: " << endl;
    cout << "Enter 6 for rectangular prism: " << endl;
    cout << "Enter 7 for pyramid: " << endl; 
    cout << "Enter shape from menu: "; 
    cin >> shapeNum; 
    
    // While loop to validate input is within range of values. 
    while(shapeNum <= 0 || shapeNum > 7)
    {
         cout << "Invalid entry. Enter number from menu: " << endl; 
         cin >> shapeNum; 
        
    }
}

double vol_cylinder(double r, double h)
{
    return (pow(r,2)*M_PI*h); 
}
double vol_sphere(double r) 
{
    return (4/3)*M_PI*pow(r,3); 
}
double vol_triprism(double b, double h, double l)
{
    return (b*h*l) / 2; 
}
double vol_cone(double r, double h)
{
    return (pow(r, 2)*h) / 3;
}
double vol_cube(double l)
{
    return pow(l, 3); 
}
double vol_rectprism(double l, double w, double h) 
{
    return l*w*h; 
}
double vol_pyramid(double l, double w, double h)
{
    return (l*w*h) / 3; 
}

void exit_or_continue(const string & prompt, int & exitNum)
{
    int shapeNum; // User entry for menu selectiom. 
    double l; // Variable for length. 
    double w; // Variable for width. 
    double h; // Variable for height. 
    double r; // Variable for radius. 
    double b; // Variable for base. 
    
    // Display prompt. 
    cout << prompt; 
    cin >> exitNum; 
    
    // While loop to validate input. 
    while(exitNum <= -1 || exitNum >= 2)
    {
        cout << "Enter 0 to exit program, 1 to find volume of another shape: ";
        cin >> exitNum;
    }
    
    if(exitNum == 0)
    {
        cout << "Thank you for using this program! Goodbye!" << endl; 
    }
    
    else {
    
    // Call function to display menu. 
    user_entry("Welcome to 3D volume calculator!", shapeNum); 
    
    // Create branching for menu selection. 
    // Cylinder branch:
    if(shapeNum == 1)
    {
        // User prompt. 
        cout << "Enter radius and height: "; 
        cin >> r >> h;  
        
        //While loop to make sure input is valid. 
        while(r <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl; 
            cout << "Enter radius and height: "; 
            cin >> r >> h; 
        }
        
        cout << endl; 
        
        // Display result. 
        cout << "Volume of cylinder is " << vol_cylinder(r, h) / M_PI << "π ("; 
        cout << vol_cylinder(r, h) << ") cubic units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum);
    }
    
    // Sphere branch. 
    else if(shapeNum == 2)
    {
        // User prompt. 
        cout << "Enter radius: "; 
        cin >> r; 
        
        // While loop to make sure input is valid. 
        while(r <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter radius: "; 
            cin >> r; 
        }
        
        cout << endl; 
        
        // Display result. 
        cout << "Volume of sphere is " << pow(r,3) << " * (4/3)π ("; 
        cout << vol_sphere(r) << ") cubic units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum);
    }
    
    // Triangular prism branch. 
    else if(shapeNum == 3)
    {
        cout << "Enter base, height, and length: "; 
        cin >> b >> h >> l; 
        
        // While loop to validate input. 
        while(b <= 0 || h <= 0 || l <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter base, height, and length: "; 
            cin >> b >> h >> l; 
        }
        
        cout << endl; 
        
        // Display result. 
        cout << "Volume of triangular prism is " << vol_triprism(b, h, l); 
        cout << " square units.";
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
        
    }
    
    // Cone branch. 
    else if (shapeNum == 4)
    {
        cout << "Enter radius and height: "; 
        cin >> r >> h; 
        
        // While loop to validate input. 
        while(r <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter radius and height: "; 
            cin >> r >> h; 
        }
        
        cout << endl; 
        
        // Displays result. 
        cout << "Volume of cone is " << r * h;
        cout << " / 3 * π (" << vol_cone(r, h) << ") cubic units." << endl;
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
        
    }
    
    // Cube branch. 
    else if (shapeNum == 5)
    {
        cout << "Enter length: ";
        cin >> l; 
        
        // While loop to validate input. 
        while(l <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter length: "; 
            cin >> l; 
        }
        
        cout << endl;
        
        // Display result. 
        cout << "Volume of cube is " << vol_cube(l) << " cubic units." << endl;
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum);
    }
    
    // Rectangular prism branch. 
    else if (shapeNum == 6)
    {
        cout << "Enter length, width, and height: ";
        cin >> l >> w >> h;
        
        // While loop to validate input. 
        while (l <= 0 || w <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter length, width, and height: "; 
            cin >> l >> w >> h; 
        }
        
        cout << endl;
        
        // Display result. 
        cout << "Volume of rectangular prism is " << vol_rectprism(l, w, h); 
        cout << " cubic units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
    }
    
    // Pyramid branch. 
    else if (shapeNum == 7)
    {
        cout << "Enter length, width, and height: "; 
        cin >> l >> w >> h; 
        
        // While loop to validate input. 
        while(l <= 0 || w <= 0 || h <= 0)
        {
            cout << "Must enter positive, non-zero number(s)" << endl;
            cout << "Enter length, width, and height: "; 
            cin >> l >> w >> h; 
        }
        
        cout << endl;
        
        // Display result. 
        cout << "Volume of pyramid is " << vol_pyramid(l, w, h); 
        cout << " square units." << endl; 
        exit_or_continue("Enter 0 to exit program, 1 to find volume of another shape: ", exitNum); 
    }
    }
}