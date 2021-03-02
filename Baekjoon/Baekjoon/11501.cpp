//주식
//https://www.acmicpc.net/problem/11501
/* 계속하여 실패해서 문제가 무엇인지 찾아보니 return 값이 커서 
int 를 long long 으로 수정하니 맞을수 있었던 문제 */

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long maxProfit(vector<int> &v) {
	long long profit = 0;
	int i;

	long long mx = 0;
	//제일 끝부터 가장 높은 주가를 갱신해옴
	for (i = v.size() - 1; i >= 0; i--) {
		if (v[i] > mx) 
			mx = v[i];
		else //가장 높은 주가보다 낮은 주가 일시 팜
			profit += mx - v[i];
	}
	return profit;
}

int main() {
	int T, n, i, j;
	scanf("%d", &T);
	
	int price;

	for (i = 0; i < T; i++) {
		scanf("%d", &n);
		vector<int> v;
		for (j = 0; j < n; j++) {
			scanf("%d", &price);
			v.push_back(price);
		}
		printf("%lld\n",maxProfit(v));
	}

	return 0;
}