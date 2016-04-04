// Main function for Owned Pointers

#include "StringBuffer.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	StringBuffer* obj = new StringBuffer();
	//Appending
	obj->append('a');
	obj->append('b'); 
	obj->append('c'); 
	obj->append('d'); 
	obj->append('e');
	cout << "Owned Pointer Implementation " << std::endl;
	// Check Length Function
	cout << "Object 1 Length =" << obj->length() << std::endl;
	// Check CharAt Function
	std::cout << "Object 1 charAt 0 = " << obj->charAt(0) << std::endl;

	getchar();
	return 0;
}

