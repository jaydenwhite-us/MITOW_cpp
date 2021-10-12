#include <iostream>
using namespace std;

/*
Question:	What happens if we declare the same name twice within a block, 
			giving it two different meanings?
*/
/*//Remove comment marker from this line to uncomment code
int main() {
	int arg1;
	arg1 = -1;
	int x, y, z;
	char myDouble = '5';
	char arg1 = 'A';
	cout << arg1 << "\n";
	return 0;
}
*/
/*
Answer:		Compiler Errors	C2371 -> redefinition error
							C2088 -> operator illeagal for class error
*/

/*
Question:	What happens if we declare an identifier in a block, and then
			redeclare that same identifier in a block nested within that block?
*/
/*//Remove comment marker from this line to uncomment code
int main() {
	int arg1;
	arg1 = -1;
	{
		char arg1 = 'A';
		cout << arg1 << "\n";
	}
	return 0;
	}
/*
	Answer:	The program runs and arg1 from the nearest scope is printed.
*/


/*
Question:	Suppose an identifier has two different declarations,
			one in an outer block and one in a nested inner block. If
			the name is accessed within the inner block, which
			declaration is used?
*/
/*//Remove comment marker from this line to uncomment code
int main() {
	int arg1;
	arg1 = -1;
	{
	char arg1 = 'A';
	cout << arg1 << "\n";
	}
	return 0;
}
/*
Answer:	The inner block declaration is used.
*/

/*
Question:	Suppose an identifier has two different declarations,
			one in an outer block and one in a nested inner block. If
			the name is accessed within the outer block, but after the 
			inner block which declaration is used?
*/
/*//Remove comment marker from this line to uncomment code
int main() {
	int arg1;
	arg1 = -1;
	{
	char arg1 = 'A';
	
	}
	cout << arg1 << "\n";
	return 0;
}

/*
Answer:	The outer block declaration is used.
*/

/*Question:	Below is a program that will not compile. Why not? By moving
			which line can we get the code to compile?
*/
/*//Remove comment marker from this line to uncomment code
using namespace std;

int main()
{
	cout << "Hello, World!\n";
	return 0;
}

#include <iostream>

/*
Answer:	Line 9 to before Line 1
*/
