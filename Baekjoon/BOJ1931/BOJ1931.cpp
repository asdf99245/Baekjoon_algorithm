// ȸ�ǽ� ����
// https://www.acmicpc.net/problem/1931

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(), cmp); // ������ �ð��� ���������� ����

	int cnt = 0;
	int end = 0;
	for (int i = 0; i < n; i++) {
		if (end <= v[i].first) { // ���� ȸ�ǰ� �����ð����� ���� ȸ���� ���۽ð����� ũ�ٸ�
			end = v[i].second; // ȸ�ǰ� �����ð� ����
			cnt++; 
		}
	}

	printf("%d", cnt);
	return 0;
}