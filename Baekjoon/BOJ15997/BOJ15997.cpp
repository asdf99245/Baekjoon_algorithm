// ½ÂºÎ ¿¹Ãø
// https://www.acmicpc.net/problem/15997

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct prob {
	double win;
	double draw;
	double lose;
};
map<string, int> mp;
vector<pair<pair<int, int>, prob>> v;
vector<int> score(4,0);
vector<double> ans(4, 0);

void DFS(double p, int cnt) {
	if (cnt == 6) {
		if (p == 0)return;

		vector<pair<int, int>> rank;
		for (int i = 0; i < 4; i++) {
			rank.push_back({ score[i],i });
		}

		sort(rank.begin(), rank.end());

		int s1 = rank[0].first, s2 = rank[1].first, s3 = rank[2].first, s4 = rank[3].first;
		int i1 = rank[0].second, i2 = rank[1].second, i3 = rank[2].second, i4 = rank[3].second;
		if (s2 != s3) {
			ans[i3] += p;
			ans[i4] += p;
		}
		else if (s1 == s2 && s3 == s4) {
			ans[i1] += p / 2;
			ans[i2] += p / 2;
			ans[i3] += p / 2;
			ans[i4] += p / 2;
		}
		else if (s1 == s2) {
			ans[i1] += p / 3;
			ans[i2] += p / 3;
			ans[i3] += p / 3;
			ans[i4] += p;
		}
		else if (s3 == s4) {
			ans[i2] += p * 2 / 3;
			ans[i3] += p * 2 / 3;
			ans[i4] += p * 2 / 3;
		}
		else {
			ans[i2] += p / 2;
			ans[i3] += p / 2;
			ans[i4] += p;
		}
		return;
	}

	int a = v[cnt].first.first;
	int b = v[cnt].first.second;

	score[a] += 3;
	DFS(p * v[cnt].second.win, cnt + 1);
	score[a] -= 3;

	score[a] += 1;
	score[b] += 1;
	DFS(p * v[cnt].second.draw, cnt + 1);
	score[a] -= 1;
	score[b] -= 1;

	score[b] += 3;
	DFS(p * v[cnt].second.lose, cnt + 1);
	score[b] -= 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i;
	for (i = 0; i < 4; i++) {
		string name;
		cin >> name;
		mp[name] = i;
	}

	for (i = 0; i < 6; i++) {
		string a, b;
		double w, d, l;
		cin >> a >> b >> w >> d >> l;
		prob p = { w,d,l };
		v.push_back({ {mp[a],mp[b]},p });
	}

	DFS(1, 0);

	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < 4; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}