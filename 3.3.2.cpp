double takeTheMean(double*, const int);
const int requestAnInteger();
const double requestADouble();
void printMessage(const char* message);
void resetStream();
void sort(double*, const int);

#include <iostream>

using namespace std;

int main() {
	const int length = requestAnInteger();
	double* ry = new double[length] {0};
	for (int i = 0; i < length; ) {
		ry[i] = requestADouble();
		cout << ++i << " of " << length << '\n';
	}
	sort(ry, length);
	double mean = takeTheMean(ry, length);
	double range = ry[length - 1] - ry[0];
	double max = ry[length - 1];
	double min = ry[0];

	cout.sync_with_stdio(true);

	cout << "\n|Mean: " << mean << "\n";
	cout << "\n|Max: " << max << "\n";
	cout << "\n|Min: " << min << "\n";
	cout << "\n|Range: " << range << "\n";
	system("pause");
	
	const char rtn = '\n';
	const char exit_check= '\n';
	
}

void sort(double* array, const int length) {
	for (int i = 0; i < length; i++) {
		if (i == length - 1) return;
		if (array[i + 1] < array[i]) {
			const double t = array[i + 1];
			array[i + 1] = array[i];
			array[i] = t;
		}
	}
}
double takeTheMean(double* array, const int length) {
	double sum = 0;
	for (int i = 0; i < length; i++) sum += array[i];
	double mean = sum/length;
	return mean;
}

const int requestAnInteger() {
	int x = 0;
	const char* ListLengthRequest = "|Please specify # of integers \n";
	const char* Rejected = "|Input not an integer\n";
	cin.clear();
	while(cin.good()){ //Check cin state is good.
		printMessage(ListLengthRequest), cin >> x; //Print message. Call cin which flushes cout in printMessage. Write to x.
		if (cin) break; // check cin did not enter a failed state or bad state. If not break. 
		printMessage(Rejected);
		resetStream();
	}
	return x;
}

const double requestADouble() {
	double x = 0;
	const char* ListLengthRequest = "|Please specify a double: \n";
	const char* Rejected = "|Input not a number\n";
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
	cin.clear(), cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Else clear flags, ignore buffer, while loop repeats
}
void printMessage(const char* message) {
	cout << message;
	//return cout.good();
}