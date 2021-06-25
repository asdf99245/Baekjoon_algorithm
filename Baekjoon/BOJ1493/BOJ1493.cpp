// �ڽ� ä���
// https://www.acmicpc.net/problem/1493

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<pair<int,int>> cube;
int ans = 0;
bool check = true;

void func(int length, int width, int height) {
	if (check == false) return;
	if (length == 0 || width == 0 || height == 0) { 
		return;
	}

	int i;

	for (i = n - 1; i >= 0; i--) { // �׸����ϰ� ���� ū ť����� �־
		if (cube[i].second <= 0) continue; // ť�갡 �� �̻� ������
		int l = cube[i].first;
		if (length < l || width < l || height < l) continue; // ť���� ũ�Ⱑ �ȵ���
		cube[i].second--;
		ans++;
		// ���� ������ ���� ��������
		func(length, width, height - l);
		func(l, width - l, l);
		func(length - l, width, l);
		return;
	}
	
	check = false; // �����ִ� ������ ť��� ä�� �� ������

}

int main() {
	int l, w, h, i;
	scanf("%d %d %d", &l, &w, &h);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cube.push_back({ pow(2,a),b });
	}

	sort(cube.begin(),cube.end());

	func(l, w, h);
	
	if (check == false) printf("-1");
	else printf("%d", ans);

	return 0;
}