//Construct the lexicographically largest valid sequence
//https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/submissions/

class Solution {
    bool visited[21];
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> v(2 * n - 1, 0); // 1은 한개 2~n은 두개씩이므로 총 (2*n -1)개
        memset(visited, false, sizeof(visited));
        dfs(v, 0, n);
        return v;
    }

    bool dfs(vector<int>& v, int ind, int n) {
        if (ind == v.size()) { // 배열을 다채웠으면 
            return true;
        }

        if (v[ind]) { // 이미 있는 값이라면 다음 인덱스로 이동
            return dfs(v, ind + 1, n);
        }

        for (int i = n; i >= 1; i--) { // 그리디하게 큰값부터 넣어봄
            if (!visited[i]) { // 사용하지 않은 값이라면
                visited[i] = true;
                if (i == 1) { // 1일 경우 한개의 칸만 채우면 된다
                    v[ind] = i;
                    if (dfs(v, ind + 1, n)) return true;
                    v[ind] = 0;
                }
                else { // 나머지는 총 두칸
                    if (ind + i >= v.size() || v[ind + i]) { // ind + i칸이 배열의 사이즈를 넘어가거나 값이 이미 존재한다면
                        visited[i] = false;
                        continue;
                    }
                    v[ind] = v[ind + i] = i;
                    if (dfs(v, ind + 1, n)) return true;
                    v[ind] = v[ind + i] = 0;
                }
                visited[i] = false;
            }
        }

        return false;
    }
};