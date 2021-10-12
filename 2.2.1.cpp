#include <iostream>
using namespace std;

int main() {
	const char* output = "Hello, World!\n";
	cout << output;
	return output == "Hello, World!" ? 0 : 1 ;
}