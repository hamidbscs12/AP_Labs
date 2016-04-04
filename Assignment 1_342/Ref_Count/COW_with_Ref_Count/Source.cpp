#include "StringBuffer.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	//creating a smart string const char*

	char* hello = "hello";
	StringBuffer* obj = new StringBuffer(hello, 5);
	StringBuffer* obj2 = new StringBuffer();

	*obj2 = *obj;
	// Append Fucntion
	obj2->append('h'); // 1st character append to obj 2
	obj2->append('w'); // 2nd character appedn to obj 2
	// Length Function
	cout << "Copy on Write Implementation wiht Reference Counting "<< std::endl;
	cout << "Object 1 Length =" << obj->length() << std::endl;
	cout << "Object 2 Length =" << obj2->length() << std::endl;
	std::cout << "new ss charAt 0 = " << obj->charAt(0) << std::endl;


	getchar();
	return 0;
}

