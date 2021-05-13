//�� ����
//https://www.acmicpc.net/problem/2910

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int,pair<int,int>> mp; // pair ù��° = �󵵼� �ι�° = ���� ����
vector<int> v;

bool cmp(int& a, int& b) {
	if (mp[a].first == mp[b].first) // �󵵼��� ���ٸ� ���� ���� ������
		return mp[a].second < mp[b].second;
	return mp[a].first > mp[b].first;
}
int main() {
	int N, C, i;
	scanf("%d %d", &N, &C);
	for (i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
		mp[a].first ++; // �󵵼�
		if (mp[a].second == 0) // ó�� ���Դٸ� ������ ���
			mp[a].second = i;
	}

	sort(v.begin(), v.end(),cmp); // ����

	for(i=0; i<N; i++)
		printf("%d ", v[i]);

	return 0;
}