//외판원 순회
//https://www.acmicpc.net/problem/2098
//*******************중요******************* 많이 틀린 문제

/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int n;
int w[16][16];
int dp[16][1 << 16]; //비트셋으로 visited 표현 효율적임
int INF = 987654321;

int TSP(int curr, int visited) {
	if (visited == ((1 << n) - 1)) { // 전부 방문했을때
		if(w[curr][0] != 0) //시작점으로 갈수 있다면 거리 더함
			return w[curr][0];
		return INF; //없으면 큰수 더함
	}
	
	int ret = dp[curr][visited]; //메모이제이션
	if (ret != -1) //값이 존재하면 출력
		return ret;

	ret = INF;
	for (int i = 1; i < n; i++) {
		if (visited & (1 << i) || w[curr][i] == 0) //비트를 이용하여 visited 확인, 길이 있는지 확인
			continue;

		int visit = visited | (1 << i); //OR비트로 i비트 visit 표시 

		ret = min(ret, w[curr][i] + TSP(i, visit)); //제일 작은 루트를 구해줌
	}

	dp[curr][visited] = ret;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d", TSP(0, 1));
	return 0;
}*/