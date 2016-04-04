#pragma once 
#include <iostream>

class strinB
{
public:
	char* string_buf;  	//buffer string
	int _length;        //String length
	int _refcount;		// reference count
	strinB();			//constructor
};
class StringBuffer {

public:
	StringBuffer();  					//constructor
	~StringBuffer();				 	//destructor
	StringBuffer(const StringBuffer&); //shallow copying constructor
	StringBuffer(char*, int); 	//converts 
	strinB* getstring_();
	char charAt(int) const;   //returns the character
	int length() const;       //returns buffer length
	void reserve(int);        //allocates memory
	void append(char);        //appends a character at the end
	
	StringBuffer& operator = (const StringBuffer&);

private:
	strinB*  string_;
};

