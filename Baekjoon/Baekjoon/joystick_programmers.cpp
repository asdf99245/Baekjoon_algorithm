//https://programmers.co.kr/learn/courses/30/lessons/42860
//���̽�ƽ (���α׷��ӽ�)
/*
#include <string>
#include <vector>
using namespace std;

bool complete[21];

bool check(string s) {
    for (int i = 0; i < s.length(); i++)
        if (!complete[i])
            return false;

    return true;
}

int solution(string name) {
    int answer = 0;
    int curr = 0;

    while (1) {
        complete[curr] = true; //���ĺ� Ȯ�� �� üũ
        int up = name[curr] - 'A'; // ���� ���ĺ� �̵�
        int down = 26 - up; //���� ���ĺ� �̵�

        answer += up < down ? up : down; //���� ������ ������

        if (check(name)) break; // ��� ���ĺ��� ���Ͽ� ���� ������ ���� Ż��

        int l = curr, r = curr;

        int lCnt = 0, rCnt = 0;

        while (1) { //���� �̵����� ���� ����� ��ġ ã��
            lCnt++;
            l--;
            if (l < 0) l = name.length() - 1; //������ ���� ������ ��ġ��

            if (!complete[l] && name[l] != 'A') break; //'A'�� �ϼ��̵� ���ĺ��� ����

            complete[l] = true; //'A'�� ���ؼ� �湮 ǥ��
        }

        while (1) { //������ �̵����� ���� ����� ��ġ ã��
            rCnt++;
            r++;
            if (r > name.length() - 1) r = 0;
            if (!complete[r] && name[r] != 'A') break;

            complete[r] = true;
        }

        // �� ª�� �������� �̵�
        if (lCnt < rCnt) {
            answer += lCnt;
            curr = l;
        }
        else {
            answer += rCnt;
            curr = r;
        }
    }

    return answer;
}
*/