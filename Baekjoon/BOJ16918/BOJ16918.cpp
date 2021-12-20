// º½¹ö¸Ç
// https://www.acmicpc.net/problem/16918

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int R, C, N;
string board[201];
queue<pair<int, int>> bomb;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };

void fillBomb() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '.') board[i][j] = 'O';
        }
    }
}

void solve(int cnt) {
    if (cnt == N) {
        return;
    }

    fillBomb(); // ºóÄ­À» ÆøÅºÀ¸·Î Ã¤¿î´Ù
    cnt++; // 1ÃÊ Áö³²
    if (cnt == N) return;

    // ¸ðµç ÆøÅºÀÌ Æø¹ßÇÏ°í ³­ µÚÀÇ °ÝÀÚÆÇÀ» ¾ò´Â´Ù.
    while (!bomb.empty()) {
        int y = bomb.front().first;
        int x = bomb.front().second;
        bomb.pop();
        // ÇöÀçÄ­°ú ÀÎÁ¢ÇÑ ³×Ä­¿¡ ¿µÇâ
        for (int i = 0; i < 5; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < R && 0 <= nx && nx < C && board[ny][nx] == 'O') {
                board[ny][nx] = '.';
            }
        }
    }
    cnt++; // 1ÃÊ Áö³²
    if (cnt == N) return;

    // ÆøÅºÀÇ À§Ä¡ ÀúÀå
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'O') bomb.push({ i,j });
        }
    }
    solve(cnt);
}

int main() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'O') bomb.push({ i,j });
        }
    }
    solve(1);

    for (int i = 0; i < R; i++) {
        cout << board[i] << '\n';
    }

    return 0;
 }