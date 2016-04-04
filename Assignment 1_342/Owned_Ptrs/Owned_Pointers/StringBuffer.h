#pragma once
// StringBuffer.h for Owned Pointer
#include <iostream>
class StringBuffer {

public:
	//
	StringBuffer();			//Constructor
	~StringBuffer();        //Destructor
	char charAt(int) const;	
	int length() const;		// length
	void reserve(int);     //mem alloc
	void append(char);      //Appending
	StringBuffer(const StringBuffer&);  //Shallow Copying
	StringBuffer(char*&, int);			//Conversion 



private:
	char* string_buf; 
	int strlen; 
