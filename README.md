# Math Library

## How to use?
1)Upload files "class_matrix.cpp" and "header_matrix.hpp" to the root where the project is assembling.

2)add header_matrix.hpp
    
    #include "header_matrix.hpp"
    
Matrix objects are created like this. Here, the first two numbers are the number of rows and columns,
and the last optional is the primary fill element.

    Matrix M(2, 2, 0); 
    
Various actions with matrices are implemented by operator overloads

    M = M1 + M2;
    M = M1 * M2;
    
Some other functions

    M = M.T(); //transposition
    M.print(); //output to the console using std::cerr
