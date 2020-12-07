//나는야 포켓몬 마스터 이다솜
//https://www.acmicpc.net/problem/1620

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> pokedex1; // 이름에 맞는 번호 저장
string pokedex2[100001]; //번호에 맞는 이름 저장

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, i;
	cin >> n >> m;

	for (i = 1; i <= n; i++) {
		string name;
		cin >> name;
		pokedex1[name] = i;
		pokedex2[i] = name;
	}

	string p;
	for (i = 0; i < m; i++) {
		cin >> p;
		if (isdigit(p[0])) { // 번호일 때
			cout << pokedex2[stoi(p)] << "\n";
		}
		else { // 이름일때
			cout << pokedex1[p] << "\n";
		}

	}
	return 0;
}