#include <iostream>
using namespace std;
void requestNumber(const char*);
int setDefaultx(int*);
int printThankYouAndGreetingXNumberOfTimes(int*);
void printMessage();

int main() {
	int value = 9;
	int* x = &value;
	int num = 9;
	const char* message = "Please input a number ";
	requestNumber(message);
	cin >> (*x);
	if (cin.fail()) setDefaultx(x);
	printThankYouAndGreetingXNumberOfTimes(x);
	return 0;
}


void requestNumber(const char* message) {
	cout << message;
}

int setDefaultx(int* x) {
	const int def = 3;
	*x = def;
	const char* message = "Input was not a number. Set input to default value:";
	cout << message << def << "\n";
	return 0;
}

int printThankYouAndGreetingXNumberOfTimes(int* x) {
	const int sentinel = *x;
	int i = 0;
	cout << "Thank you!\n\n";
	cout << "For Loop:\n";
	for (i = 0; i < sentinel; i++) printMessage();
	cout << "\n";

	cout << "While Loop:\n";
	i = 0;
	while (i++ < sentinel) printMessage();
	cout << "\n";

	cout << "Do/While Loop:\n";
	i = 0;
	do printMessage();
	while (++i < sentinel);
	cout << "\n";

	return 0;
}

void printMessage() { cout << "Hello, World!\n"; }