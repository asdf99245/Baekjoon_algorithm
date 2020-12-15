//캠핑
//https://www.acmicpc.net/problem/4796

/*#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int L, P, V;
	int cnt = 0;
	while (1) {
		cnt++;
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0) // 반복문 탈출
			break;

		int res = V % P; //연속되는 날
		if (res >= L) // 나머지 날이 사용할수 있는날 보다 크거나 같다면 사용 가능한 날 만큼 가능
			printf("Case %d: %d\n", cnt, (V / P) * L + L);
		else // 나머지 날이 사용할수 있는날 보다 작다면 나머지 날 만큼만 가능
			printf("Case %d: %d\n", cnt, (V / P) * L + res);
	}
	return 0;
}*/