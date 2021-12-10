// ���� �켱���� ť 
// https://www.acmicpc.net/problem/7662

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

queue<pair<char, int>> oper;

void solve() {
	multiset<int> ms; 

	while (!oper.empty()) {
		char t = oper.front().first;
		int num = oper.front().second;
		oper.pop();

		if (t == 'I') { // num ����
			ms.insert(num);
		}
		else {
			if (ms.empty()) continue;  // ����ִٸ� �����Ѵ�
			if (num == 1) { // �ִ�(multiset�� ��) ���� 
				ms.erase(--ms.end()); 
			}
			else { // �ּҰ�(multiset�� ó��) ����
				ms.erase(ms.begin());
			}
		}
	}

	if (ms.empty()) puts("EMPTY");
	else {
		cout << *(--ms.end()) << " " << *ms.begin() << '\n';
	}
}

int main() {
	int T;
	cin >> T;
	while (T > 0) {
		int k, n;
		char o;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> o >> n;
			oper.push({ o,n });
		}
		solve();
		T--;
	}
	return 0;
}