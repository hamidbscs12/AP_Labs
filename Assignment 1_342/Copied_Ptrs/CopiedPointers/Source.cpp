#include "StringBuffer.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	//creating smart string  with const char*

	StringBuffer* obj = new StringBuffer();

	obj->append('a');
	obj->append('b');
	obj->append('c');
	obj->append('d');
	obj->append('e');
	cout << "Copied Pointers" << std::endl;
	cout << "Object 1 Length =" << obj->length() << std::endl;
	std::cout << "Object 1 charAt 0 = " << obj->charAt(0) << std::endl;
	delete obj;
	

	getchar();
	return 0;
}

