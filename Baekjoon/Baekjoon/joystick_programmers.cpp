//https://programmers.co.kr/learn/courses/30/lessons/42860
//조이스틱 (프로그래머스)
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
        complete[curr] = true; //알파벳 확인 후 체크
        int up = name[curr] - 'A'; // 다음 알파벳 이동
        int down = 26 - up; //이전 알파벳 이동

        answer += up < down ? up : down; //둘중 작은것 더해줌

        if (check(name)) break; // 모든 알파벳에 대하여 조작 성공시 루프 탈출

        int l = curr, r = curr;

        int lCnt = 0, rCnt = 0;

        while (1) { //왼쪽 이동으로 제일 가까운 위치 찾음
            lCnt++;
            l--;
            if (l < 0) l = name.length() - 1; //음수로 갈시 마지막 위치로

            if (!complete[l] && name[l] != 'A') break; //'A'와 완성이된 알파벳은 무시

            complete[l] = true; //'A'에 대해서 방문 표시
        }

        while (1) { //오른쪽 이동으로 제일 가까운 위치 찾음
            rCnt++;
            r++;
            if (r > name.length() - 1) r = 0;
            if (!complete[r] && name[r] != 'A') break;

            complete[r] = true;
        }

        // 더 짧은 방향으로 이동
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