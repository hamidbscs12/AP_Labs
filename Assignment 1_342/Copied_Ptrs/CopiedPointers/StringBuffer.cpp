#include "StringBuffer.h"
#include <iostream>

StringBuffer::StringBuffer() 
{
	string_buf = nullptr;	
	strlen = 0;		
}// Constructor

StringBuffer::~StringBuffer()
{
	delete[] string_buf;
}// Destructor

StringBuffer::StringBuffer(const StringBuffer& obj) {
	strlen = obj.length(); 
	string_buf = new char[strlen];  

	for (int i = 0; i<strlen; i++)
	{
		string_buf[i] = obj.charAt(i); 
	}
}


StringBuffer::StringBuffer(char* ptr, int length)
{
	string_buf = new char[length];
	strlen = length;

	for (int i = 0; i < strlen - 1; i++)
	{
		string_buf[i] = ptr[i];
	}
}

char StringBuffer::charAt(int index) const
{
	if (index < strlen)
	{
		return *(string_buf + index);
	}
	else {

		throw"\n\n\t##Array Index Out Of Bounds.\n\n";
	}
}


int StringBuffer::length() const {
	return strlen;
}// string Length

void StringBuffer::reserve(int length)
{
	
	string_buf = new char[length];
}

void StringBuffer::append(char c) // Append Function
{
	char* temp = string_buf;
	strlen++;
	string_buf = new char[strlen];
	for (int i = 0; i < strlen - 1; i++)
	{
		string_buf[i] = temp[i];
	}
	string_buf[strlen - 1] = c;
	delete[] temp;
}
