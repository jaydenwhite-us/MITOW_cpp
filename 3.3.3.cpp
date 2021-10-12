void printMessage(const char*);
void trialDivision(int*);
const int requestAnInteger();
void resetStream();
int primalityCheck(int* n);
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
	int subject = requestAnInteger();
	set<int>primes;
	int i = 2;
	while (primes.size() < subject && subject > 0) {
		int sentinel = primalityCheck(&i);
		if (sentinel > 1) primes.insert(sentinel), cout << "Prime # " << primes.size() << ": "<< sentinel <<'\n';
		if (i >= 3) i += 2;
		else i++;
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

int primalityCheck(int* n) {
	double one = 1.0;
	if (fmod(sqrt(*n),one) == 0) return 1;
	if (*n == 2) return *n;
	else if (*n >= 3) {
		for (int i = 3; i < sqrt(*n); i += 2) {
			if (*n % i == 0) return 1;
		}
	}
	else if(*n <= 1){
		return *n;
	}
	return *n;
}

void trialDivision(int* n) {
	set<int> primes;
	//set<int>::iterator itr = primes.begin();
	//Remove two's until odd.
	if (*n % 2 == 0){
		primes.insert(2);
		while (*n % 2 == 0) {
			*n = *n / 2;
			cout << *n << "||" <<  2 << '\n';
		}
	}
	 //Remove each prime up starting at 3
	for (int i = 3; i <= sqrt(*n); i = i + 2) {
			if (*n % i == 0) primes.insert(i);
			while (*n % i == 0) {
				*n = *n / i;
				cout << *n << "||" << i << '\n';
			}
	}
	//
	if (*n > 2) primes.insert(*n);
	for (set<int>::iterator itr = primes.begin(); itr != primes.end(); itr++) {
		cout << *itr << "\n";
	}
	
}

void resetStream() {
	cin.clear(), cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Else clear flags, ignore buffer, while loop repeats
}
void printMessage(const char* message) {
	cout << message;
}