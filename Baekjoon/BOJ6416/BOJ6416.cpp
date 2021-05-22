//Ʈ���ΰ�?
//https://www.acmicpc.net/problem/6416

#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	int a, b;
	int edge = 0;

	while (1) {
		cin >> a >> b;
		if (a < 0 && b < 0) // ����
			break;
		if (a == 0 && b == 0) {
			if (edge == 0 || edge == st.size() - 1) { // ��尡 0 ���̰ų� ������ ���-1�� �� Ʈ��
				printf("Case %d is a tree.\n", t);
			}
			else {
				printf("Case %d is not a tree.\n", t);
			}
			t++;
			st.clear();
			edge = 0;
		}
		else {
			//set�� ��� ����
			st.insert(a); 
			st.insert(b);
			edge++;
		}
	}
	return 0;
}