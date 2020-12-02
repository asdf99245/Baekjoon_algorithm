//모든 순열
//https://www.acmicpc.net/problem/10974

/*
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
bool check[8];
int num[8] = { 1,2,3,4,5,6,7,8 };

void DFS(int cnt,int n) {
	if (cnt == n) { // 순열 길이일때 출력
		for (int i = 0; i < v.size(); i++) { 
			printf("%d ", v[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] == true) continue; //앞에 나온 수일 경우
		v.push_back(num[i]); 
		check[i] = true;
		DFS(cnt + 1, n); //백트래킹 방법 이용
		v.pop_back();
		check[i] = false;
	}
	
}
int main() {
	int n;
	scanf("%d", &n);

	DFS(0, n);
	return 0;
}*/