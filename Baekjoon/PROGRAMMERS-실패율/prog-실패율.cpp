// ������
// https://programmers.co.kr/learn/courses/30/lessons/42889

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double fail[501];

bool cmp(int a, int b) {
    if (fail[a] == fail[b]) return a < b; // �������� ���ٸ� ��ȣ ������������
    else return fail[a] > fail[b]; // ������ ������������
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> cnt(N + 1, 0);
    int user_num = stages.size();
    for (int i = 0; i < user_num; i++) {  // ���������� �����ϰ� �ִ� ����� ���� ����Ѵ�
        if (stages[i] < N + 1) {
            cnt[stages[i]]++;
        }
    }

    for (int i = 1; i < cnt.size(); i++) {
        if (cnt[i] != 0) { // ���������� ������ ������ ���� ��� �������� ���Ѵ�
            fail[i] = (double)cnt[i] / user_num;
            user_num -= cnt[i]; // ���� �������������� ���������Ƿ� �������� ����
        }
    }

    for (int i = 1; i <= N; i++) {
        answer.push_back(i);
    }
    sort(answer.begin(), answer.end(), cmp); // �������� ����
    return answer;
}