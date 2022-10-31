#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
//1541backjun 
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
	int sum = 0, minimum=100000,mem2;
	for (int i = 0; i < Array.size(); i++) {
		if (Array[i].second == '-') {
			int sum1 = 0;//괄호를 안했을 때의 값
			int minus = -Array[i].first;//첫번째 값은 따로 뺌 
			if (i + 1 != Array.size()) {
				for (int j = i + 1; j < Array.size(); j++) {//괄호를 했을 때의 값
					int sum2 = minus;//두번째 값부터 하나씩 늘려가면서 괄호를 어디에 둘지 비교
					for (int z = i + 1; z <= j; z++) {
						if (Array[z].second == '-') sum2 += Array[z].first;
						else sum2 += -Array[z].first;
					}
					if (minimum > sum2) {
						minimum = sum2;
						mem2 = j;//최소값일 때의 index값 저장.
					}
				}
				for (int j = i + 1; j < mem2; j++) {
					if (Array[j].second == '-') sum1 += -Array[j].first;
					else sum1 += Array[j].first;
				}
				if (sum1 > minimum) {
					sum += minimum;
					i = mem2;
				}
				else sum += -Array[i].first;
			}
			else sum += -Array[i].first;
			minimum = 100000;
		}
		else {
			sum += Array[i].first;
		}
	}
	cout << num + sum;
}
