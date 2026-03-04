#include <iostream>
#include <vector>
#include <set>
using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;
	set<string> s;
	
	string str = "";
		
	// ex: abced
	for (int i = 0; i < input.size(); i++) {
		for (int j = i; j < input.size(); j++) {
			str += input[j];
			s.insert(str);
		}
		str = "";
	}

	cout << s.size();

	return 0;
}