//�κм����� ��
//https://www.acmicpc.net/problem/1182

#include <cstdio>
#include <vector>
using namespace std;

vector<int> sequence; 
int cnt = 0;

void DFS(int sum ,int index, int s) {
	if (index == sequence.size()) { // �迭 ������ �������� ��� ����
		return;
	}

	//�� �迭�� ���� ���ѰͰ� ������ �ʾ��� ���� �и�
	for (int i = index; i < sequence.size(); i++) {
		sum += sequence[i];
		if (sum == s) cnt++; //�κм����� s�� ��� count +
		DFS(sum, i + 1, s);
		sum -= sequence[i];
	}
}

int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		int a; 
		scanf("%d", &a);
		sequence.push_back(a);
	}

	DFS(0, 0, s);
	printf("%d", cnt);
	return 0;
}