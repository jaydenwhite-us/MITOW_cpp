/*Modify the code from 3.4.1 so that if the condition fails, 
nothing is printed.Use an if and a continue command
(instead of the ternary operator) to accomplish this.*/
#include <iostream>
const int requestAnInteger();
void resetStream();
void printMessage(const char*);
using namespace std;

int main() {
	while (1) {
		const int x = requestAnInteger();
		if(!(x >= 0 && x % 5 == 0)) continue;
		else cout << 5 << '\n';
	}
}
const int requestAnInteger() {
	int x = 0;
	const char* ListLengthRequest = "|Please specify an integer \n";
	const char* Rejected = "|Input not an integer\n";
	cin.clear();
	while (cin.good()) { //Check cin state is good.
		printMessage(ListLengthRequest), cin >> x; //Print message. Call cin which flushes cout in printMessage. Write to x.
		if (cin) break; // check cin did not enter a failed state or bad state. If not break. 
		printMessage(Rejected);
		resetStream();
	}
	return x;
}

void resetStream() {
	cin.clear(), cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear flags, ignore buffer
}
void printMessage(const char* message) {
	cout << message;
}