//�ּ� ���д� Ʈ��
//https://www.acmicpc.net/problem/1197
//https://ssungkang.tistory.com/entry/Algorithm-%EC%9C%A0%EB%8B%88%EC%98%A8-%ED%8C%8C%EC%9D%B8%EB%93%9CUnion-Find union -find ����

/*#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
int par[10001];
vector<pair<int, pair<int, int>>> edge;

int find(int x) { // union -find �̿� node x�� ��� ���ԵǾ��ִ��� Ȯ��
	if (x == par[x]) return x;
	return par[x] = find(par[x]);
}
bool Union(int a, int b) {  // ��� a,b�� ��ħ
	a = find(a);
	b = find(b);
	if (a == b) return false;
	else if (a > b) par[a] = b;
	else par[b] = a;

	return true;
}
int main() {
	int i;
	scanf("%d %d", &v, &e);
	for (i = 1; i <= v; i++) par[i] = i; // i����� �θ� ���
	for (i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a,&b,&c);
		edge.push_back({ c,{a,b} });
	}

	sort(edge.begin(), edge.end()); // ª�� ���� ������ ����

	long long sum = 0;
	for (i = 0; i < edge.size(); i++) {
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (Union(a, b)) sum += edge[i].first; // ����Ŭ�� �ƴҽ� ���� �߰�
	}

	printf("%lld", sum);
	return 0;
}*/