#include "StringBuffer.h" // Including the header file 
#include <iostream>

// Constructor
StringBuffer::StringBuffer() 
{
	// Set String Buffer to Null
	str = nullptr; 
}
// Destructor
StringBuffer::~StringBuffer() 
{
	// Check ref_count
	if (str->_refcount == 1)
	{
		delete[] str->strbuf;
		delete str;
	}
	else
	{
		str->_refcount--;
	}
}
// to get String
strinB* StringBuffer::getstr() 
{
	return str;
}
StringBuffer::StringBuffer(const StringBuffer& obj) {

	// Shallow Copy
	str->_length = obj.length();
	str->strbuf = new char[str->_length];
	for (int i = 0; i<str->_length; i++)
	{
		str->strbuf[i] = obj.charAt(i);
	}
}

StringBuffer::StringBuffer(char* ptr, int length)
{
	
	str = new strinB;
	str->strbuf = new char[length];
	str->_length = length;
	for (int i = 0; i < length - 1; i++)
	{
		str->strbuf[i] = ptr[i];
	}
}// Construct converting char to Smart String

char StringBuffer::charAt(int index) const
{
	// Check, the length given is less than the str length
	if (index < str->_length) 
	{
		return *(str->strbuf + index);
	}
	else {

		throw"\n\n\t##Array Index Out Of Bounds.\n\n";
	}

}
// Length of Str
int StringBuffer::length() const 
{
	return str->_length;
}

void StringBuffer::reserve(int length)
{
	// -> allocates memory according to character length size
	str = new strinB;
	str->strbuf = new char[length];
}

void StringBuffer::append(char c)
{
	// -> append character at the end of string
	if (str->_refcount>1)
	{
		strinB* str1 = new strinB;
		str1->_length = str->_length + 1;
		str1->strbuf = new char[str1->_length];
		for (int i = 0; i < str->_length; i++)
		{
			str1->strbuf[i] = str->strbuf[i];
		}
		str1->strbuf[str->_length] = c;
		str->_refcount--;
		str = str1;

	}
	else
	{

		char* str1 = str->strbuf;
		str->_length++;
		str->strbuf = new char[str->_length];
		for (int i = 0; i < str->_length - 1; i++)
		{
			str->strbuf[i] = str1[i];
		}
		str->strbuf[str->_length - 1] = c;
		delete[] str1;

	}


}
// Constructor
strinB::strinB()
{
	strbuf = nullptr;
	_length = 0;
	_refcount = 1;
}
// Operator Overloading
StringBuffer& StringBuffer::operator = (const StringBuffer& obj)
{
	
	str = obj.str;
	str->_refcount++;
	return *this;
}



