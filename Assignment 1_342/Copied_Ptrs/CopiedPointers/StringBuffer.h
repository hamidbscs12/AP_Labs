#pragma once
#include <iostream>

class StringBuffer {

public:

	StringBuffer();  				//Constructor
	~StringBuffer(); 				//Destructor

	char charAt(int) const;	
	int length() const;
	void reserve(int); 
	void append(char);     
	StringBuffer(const StringBuffer&);  //Shallow Copying
	StringBuffer(char*, int);		//Converts
private:
	char* string_buf;             //buffer for original string
	int strlen;                // string length

