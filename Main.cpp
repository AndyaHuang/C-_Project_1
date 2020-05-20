#include <iostream>
using namespace std;

string alp_list [26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
string Alp_list [26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

string dec(int key, string message) {
	string result;
	string mes_letter;
	int a;
	int compare;
	int compare_two;
	for (int i = 0; i < message.length(); i++) {
		mes_letter = message[i];
		for (int j = 0; j < 26; j++) {
			compare = mes_letter.compare(alp_list[j]);
			if (compare == 0) {
				cout << "lower" << "\n";
				a = j;
				a += key;
				a %= 26;
				result += alp_list[a];
			}
			else if (compare != 0) {
				compare_two = mes_letter.compare(Alp_list[j]);
				if (compare_two == 0) {
					cout << "upper" << "\n";
					a = j;
					a += key;
					a %= 26;
					result += Alp_list[a];
				}
			}
		}
	}
	return result;
}

string enc(int key, string message) {
	string result;
	string mes_letter;
	int a;
	int compare;
	int compare_two;
	for (int i = 0; i < message.length(); i++) {
		mes_letter = message[i];
		for (int j = 0; j < 26; j++) {
			compare = mes_letter.compare(alp_list[j]);
			if (compare == 0) {
				a = j;
				a -= key;
				while (a <= 0) {
					a += 26;
				}
				a %= 26;
				result += alp_list[a];
			}
			else if (compare != 0) {
				a = j;
				a -= key;
				while (a <= 0) {
					a += 26;
				}
				a %= 26;
				result += Alp_list[a];
			}
		}
	}
	return result;
}

void main() {
	int choice;
	string message;
	int key;
	string result;
	cout << "1-Decode, 2-Encode, 3-Exit" << "\n";
	cin >> choice;
	if (1 == choice) {
		cout << "Please write the message" << "\n";
		cin >> message;
		cout << "Please write the key" << "\n";
		cin >> key;
		result = dec(key, message);
		cout << result << "\n";
	}
	else if (2 == choice) {
		cout << "Please write the message" << "\n";
		cin >> message;
		cout << "Please write the key" << "\n";
		cin >> key;
		result = enc(key, message);
		cout << result << "\n";
	}
}