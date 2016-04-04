
#include "StringBuffer.h"
#include <iostream>

StringBuffer::StringBuffer() 
{
	str_ = nullptr; 
}

StringBuffer::~StringBuffer()
{
	if (str_->_refcount == 1)
	{
		delete[] str_->string_buf;
		delete str_->_reflink;
		delete str_;
	}
	else
	{
		str_->_refcount--;
		StringBuffer* add = this;
		if (str_->_reflink->_address == this)
		{
			reflink* temp = str_->_reflink;
			str_->_reflink = str_->_reflink->next;
			delete temp;
		}

		else {

			reflink* ptr = str_->_reflink;
			reflink* prev = NULL;

			while (ptr)
			{
				if (ptr->_address == this)
				{
					prev->next = ptr->next;
					delete ptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
	}

}
StringBuffer::StringBuffer(const StringBuffer& obj) {

	
	str_->strlen = obj.length();
	str_->string_buf = new char[str_->strlen];
	for (int i = 0; i<str_->strlen; i++)
	{
		str_->string_buf[i] = obj.charAt(i);
	}
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;
	if (str_->_reflink == NULL)
	{
		str_->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = str_->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

StringBuffer::StringBuffer(char* ptr, int length)
{
	str_ = new stringB;
	str_->string_buf = new char[length];
	str_->strlen = length;
	for (int i = 0; i < length - 1; i++)
	{
		str_->string_buf[i] = ptr[i];
	}
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;

	if (str_->_reflink == NULL)
	{
		str_->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = str_->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

char StringBuffer::charAt(int index) const
{
	if (index <str_->strlen)
	{
		return *(str_->string_buf + index);
	}
	else {

		throw"\n\n\t##Array Index Out Of Bounds.\n\n";
	}
}


int StringBuffer::length() const {
	// -> returns the length of the buffer
	return str_->strlen;
}

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	str_ = new stringB;
	str_->string_buf = new char[length];
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;
	if (str_->_reflink == NULL)
	{
		str_->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = str_->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
}

void StringBuffer::append(char c)
{
	// -> appendingcharacter at end of string

	if (str_->_refcount>1)
	{
		stringB* str1 = new stringB;
		str1->strlen = str_->strlen + 1;
		str1->string_buf = new char[str1->strlen];
		for (int i = 0; i < str_->strlen; i++)
		{
			str1->string_buf[i] = str_->string_buf[i];
		}
		str1->string_buf[str_->strlen] = c;
		str_->_refcount--;
		if (str_->_reflink->_address == this)
		{
			reflink* str1 = str_->_reflink;
			str_->_reflink = str_->_reflink->next;
			delete str1;
		}
		else {
			reflink* ptr = str_->_reflink;
			reflink* prev = NULL;
			while (ptr)
			{
				if (ptr->_address == this)
				{
					prev->next = ptr->next;
					delete ptr;
					break;
				}
				prev = ptr;
				ptr = ptr->next;
			}

		}
		str_ = str1;
		reflink* rlinking = new reflink;
		rlinking->_address = this;
		rlinking->next = NULL;
		if (str_->_reflink == NULL)
		{
			str_->_reflink = rlinking;
		}
		else
		{
			reflink* ptr = str_->_reflink;
			reflink*  prev = NULL;
			while (ptr)
			{
				prev = ptr;
				ptr = ptr->next;
			}
			prev->next = rlinking;
		}

	}
	else
	{

		char* str1 = str_->string_buf;
		str_->strlen++;
		str_->string_buf = new char[str_->strlen];
		for (int i = 0; i < str_->strlen - 1; i++)
		{
			str_->string_buf[i] = str1[i];
		}
		str_->string_buf[str_->strlen - 1] = c;
		delete[] str1;

	}


}
reflink* StringBuffer::get_link() {
	return str_->_reflink;

}

StringBuffer& StringBuffer::operator = (const StringBuffer& obj)
{
	str_ = obj.str_;
	str_->_refcount++;
	reflink* rlinking = new reflink;
	rlinking->_address = this;
	rlinking->next = NULL;
	if (str_->_reflink == NULL)
	{
		str_->_reflink = rlinking;
	}
	else
	{
		reflink* ptr = str_->_reflink;
		reflink*  prev = NULL;
		while (ptr)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = rlinking;
	}
	return *this;
}

stringB::stringB() 
{
	string_buf = nullptr;
	strlen = 0;
	_refcount = 1;
	_reflink = NULL;
}


