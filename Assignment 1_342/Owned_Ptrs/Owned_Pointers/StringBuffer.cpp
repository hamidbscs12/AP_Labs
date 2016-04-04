#include "StringBuffer.h"
#include <iostream>


StringBuffer::StringBuffer() 
{
	str_buf = nullptr;	
	str_length = 0;		
}// Constructor

StringBuffer::~StringBuffer() 
{
	delete[] str_buf;  
}// Destructor


void StringBuffer::append(char c)
{

	char* temp = str_buf;
	str_length++;
	str_buf = new char[str_length];

	for (int i = 0; i < str_length - 1; i++)
	{
		str_buf[i] = temp[i];
	}
	str_buf[str_length - 1] = c;
	delete[] temp;
}//Append
char StringBuffer::charAt(int index) const
{

	// Check length is less than the string length
	if (index < str_length)
	{
		return *(str_buf + index);
	}
	else {

		throw"\n\n\t##Array Index Out Of Bounds.\n\n";
	}
}

int StringBuffer::length() const 
{

	return str_length;
}//string Length

StringBuffer::StringBuffer(const StringBuffer& obj) {

	str_length = obj.length();
	str_buf = new char[str_length];

	for (int i = 0; i<str_length; i++)
	{
		str_buf[i] = obj.charAt(i);
	}
}// Shallow Copying

StringBuffer::StringBuffer(char* &ptr, int length)
{
	
	str_buf = ptr;
	ptr = NULL;		// Avoid dangling pointer
	str_length = length;

}// Conversion Function

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	str_buf = new char[length];

}

