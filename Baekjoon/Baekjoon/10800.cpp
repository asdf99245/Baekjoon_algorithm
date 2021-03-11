//�÷���
//https://www.acmicpc.net/problem/10800
//******���� Ʋ��****** 
//���߿� �ٽ� Ǯ������� ����

/*#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//index, color, size ����
typedef struct ball {
	int num;
	int color;
	int sz;
}ball;

vector<ball> balls;
int color_sum[200001]; //color�� ������
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

	//size���� �������� ����
	sort(balls.begin(), balls.end(),comp1);

	int sum = 0;
	j = 0;

	for (i = 0; i < n; i++) {
		int sz = balls[i].sz;
		int col = balls[i].color;
		int index = balls[i].num;
		
		//���� �� ũ�⺸�� �����͵鸸
		while (balls[j].sz < sz) {
			sum += balls[j].sz; //������
			color_sum[balls[j].color] += balls[j].sz; // color�� ������
			j++;
		}
		int res = sum - color_sum[col]; //���� ���� �������� ����

		ans.push_back({ index,res });
	}
	sort(ans.begin(), ans.end(), comp2); //index �������� ����

	for (i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i].second);
	
	return 0;
}*/