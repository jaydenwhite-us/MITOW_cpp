#include <iostream>
const int requestAnInteger();
void resetStream();
void printMessage(const char*);
using namespace std;

int main() {
	
	while (1) {
		const int x = requestAnInteger();
		cout <<( (x >= 0 && x % 5 == 0) ? 5 : -1);
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