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
	int sum = 0, minimum=100000,mem2;
	for (int i = 0; i < Array.size(); i++) {
		if (Array[i].second == '-') {
			int sum1 = 0;//��ȣ�� ������ ���� ��
			int minus = -Array[i].first;//ù��° ���� ���� �� 
			if (i + 1 != Array.size()) {
				for (int j = i + 1; j < Array.size(); j++) {//��ȣ�� ���� ���� ��
					int sum2 = minus;//�ι�° ������ �ϳ��� �÷����鼭 ��ȣ�� ��� ���� ��
					for (int z = i + 1; z <= j; z++) {
						if (Array[z].second == '-') sum2 += Array[z].first;
						else sum2 += -Array[z].first;
					}
					if (minimum > sum2) {
						minimum = sum2;
						mem2 = j;//�ּҰ��� ���� index�� ����.
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