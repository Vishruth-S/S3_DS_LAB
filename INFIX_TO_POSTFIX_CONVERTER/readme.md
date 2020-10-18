# Infix to Postfix Converter

This is a C++ program that takes and Infix expression and converts it into its Postfix form.

A c++ compiler is needed to run this program  
If using gcc compiler, use the following commands  
### To compile  
```
g++ PostfixConverter.cpp -o PostfixConverter
```
### To run
```
PostfixConverter
```
### Rules when entering Infix expression
* Enter the infix expression without any spaces.   
* If any unary `-` or `+`, use `$`. For eg: `a*-b` should be entered as `a*$b`  

The corresponding postfix expression will be displayed.
