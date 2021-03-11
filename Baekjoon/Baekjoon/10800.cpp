//컬러볼
//https://www.acmicpc.net/problem/10800
//******많이 틀림****** 
//나중에 다시 풀어봐야할 문제

/*#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//index, color, size 저장
typedef struct ball {
	int num;
	int color;
	int sz;
}ball;

vector<ball> balls;
int color_sum[200001]; //color별 누적값
vector<pair<int, int>> ans;

bool comp1(ball a, ball b){
	return a.sz < b.sz;
}
bool comp2(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main() {
	int n, i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int col, sz;
		scanf("%d %d", &col, &sz);
		balls.push_back({ i,col,sz });
	}

	//size별로 오름차순 정렬
	sort(balls.begin(), balls.end(),comp1);

	int sum = 0;
	j = 0;

	for (i = 0; i < n; i++) {
		int sz = balls[i].sz;
		int col = balls[i].color;
		int index = balls[i].num;
		
		//현재 공 크기보다 작은것들만
		while (balls[j].sz < sz) {
			sum += balls[j].sz; //누적값
			color_sum[balls[j].color] += balls[j].sz; // color별 누적값
			j++;
		}
		int res = sum - color_sum[col]; //같은 색깔 누적값은 빼줌

		ans.push_back({ index,res });
	}
	sort(ans.begin(), ans.end(), comp2); //index 오름차순 정렬

	for (i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i].second);
	
	return 0;
}*/