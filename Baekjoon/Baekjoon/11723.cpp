//����
//https://www.acmicpc.net/problem/11723

/*
#include <iostream>
#include <string>
using namespace std;

int s = 0;

void execute(string comm) { 
	int el;
	if (comm == "add") { // OR�������� ��Ʈ ƴ
		cin >> el;
		s |= (1 << el);
	}
	else if (comm == "remove") { // AND�� NOT �������� ��Ʈ ����
		cin >> el;
		s &= ~(1 << el);
	}
	else if (comm == "check") { //AND�������� ��Ʈ�� �����ִ��� Ȯ��
		cin >> el;
		if ((s & (1 << el))) {
			cout << 1 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	else if (comm == "toggle") { //XOR�������� �������� ���� �������� �ѱ�
		cin >> el;
		s ^= (1 << el);
	}
	else if (comm == "all") //s�� ���� NOT���� �� OR����� ��� 1�� ��
		s |= ~s;
	else if (comm == "empty") //0�� ������
		s = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string comm;
		cin >> comm;
		execute(comm);
	}

	return 0;
}
*/