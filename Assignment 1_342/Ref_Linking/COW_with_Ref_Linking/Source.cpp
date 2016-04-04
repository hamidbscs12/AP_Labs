// Main function for Copy on write implementation with reference counting

#include "StringBuffer.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	//creating a smart string with const char*
	char* obj = "hello";

	StringBuffer* obj1 = new StringBuffer(obj, 5);
	StringBuffer* obj2 = new StringBuffer();
	//referencing
	*obj2 = *obj1;

	int i = 0; 

	reflink* li = obj1->get_link();
	//  reference check
	while (li) {

		if (li->_address == obj2) {
			i = 1;
			break;
		}
		li = li->next;

	}
	cout << "Copy on Write Implementation wiht Reference Linking " << std::endl;
	// Check Length Function
	cout << "Object 1 Length =" << obj1->length() << std::endl;
	cout << "Object 2 Length =" << obj2->length() << std::endl;
	// Check reference
	if (i ==1)
		cout << "Object 2 is in reference of Object 1"  << std::endl;
	// Checking Append Fucntion
	obj1->append('a'); // 1st character append to obj 1
	obj2->append('h'); // 1st character append to obj 2
	obj2->append('w'); // 2nd character appedn to obj 2
	std::cout << "Object 1 charAt 3 = " << obj1->charAt(3) << std::endl;
	std::cout << "Object 2 charAt 6 = " << obj2->charAt(6) << std::endl;


	getchar();
	return 0;
}

