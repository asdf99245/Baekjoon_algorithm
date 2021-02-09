//거짓말
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int parent[51];
vector<int> truth;
vector<int> party[51];

int find(int x) {
	if (parent[x] == x) 
		return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[a] = b;
	}
}
int main() {
	int i, j, k, num, member, cnt;

	scanf("%d %d", &N, &M);
	cnt = M;
	for (i = 1; i <= N; i++) parent[i] = i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &member);
		truth.push_back(member); //진실을 알고있는 사람의 번호
	}
	for (i = 1; i <= M; i++) {
		scanf("%d", &num);
		while (num > 0) {
			scanf("%d", &member);
			party[i].push_back(member); // 각 파티멤버들
			num--;
		}
	}

	for (i = 1; i <= M; i++) {
		for (j = 0; j < party[i].size() - 1; j++) {
			merge(party[i][j], party[i][j + 1]); //유니온-파인드 이용해서 같은 파티사람들끼리 merge
		}
	}

	for (i = 1; i <= M; i++) {
		for (j = 0; j < party[i].size() ; j++) {
			for (k = 0; k < truth.size(); k++) {
				//각 파티의 파티원이 만약 진실을 알고있는 사람과 부모가 같다면 그 파티는 진실을 알수 있음
				if (find(truth[k]) == find(party[i][j])) {
					break;
				}
			}
			if (k < truth.size()) break; //반복문을 나가기 위한 조건문
		}
		if (k < truth.size()) cnt--;
	}

	printf("%d", cnt);
	return 0;
}