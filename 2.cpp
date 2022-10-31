#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;

int main() {
	fast;
	string Su;
	vector<pair<int, char>> Array;
	cin >> Su;
	string change;
	int num, mem;
	for (int i = 0; i < Su.size(); i++) {
		if (Su[i] == '+' || Su[i] == '-') {
			mem = i;
			break;
		}
		change += Su[i];
	}
	if (change == Su) {
		cout << stoi(change);
		return 0;
	}
	num = stoi(change);
	change = "";
	int num1;
	char booho;
	for (int i = mem; i < Su.size(); i++) {
		if (Su[i] == '+' || Su[i] == '-') booho = Su[i];
		else {
			change += Su[i];
			if (i + 1 == Su.size() || Su[i + 1] == '+' || Su[i + 1] == '-') {
				num1 = stoi(change);
				Array.push_back(make_pair(num1, booho));
				change = "";
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < Array.size(); i++) {
		if (Array[i].second == '-') {
			sum += -Array[i].first;
			if (i + 1 != Array.size()) {
				int flag = 1;
				for (int j = i + 1; j < Array.size(); j++) {
					if (Array[j].second == '-') {
						i = j-1;
						flag = 0;
						break;
					}
					else sum += -Array[j].first;
				}
				if (flag == 1) i = Array.size() - 1;
			}
		}
		else sum += Array[i].first;
	}
	cout << num + sum;
}
