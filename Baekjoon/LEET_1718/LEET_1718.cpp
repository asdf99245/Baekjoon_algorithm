//Construct the lexicographically largest valid sequence
//https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/submissions/

class Solution {
    bool visited[21];
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> v(2 * n - 1, 0); // 1�� �Ѱ� 2~n�� �ΰ����̹Ƿ� �� (2*n -1)��
        memset(visited, false, sizeof(visited));
        dfs(v, 0, n);
        return v;
    }

    bool dfs(vector<int>& v, int ind, int n) {
        if (ind == v.size()) { // �迭�� ��ä������ 
            return true;
        }

        if (v[ind]) { // �̹� �ִ� ���̶�� ���� �ε����� �̵�
            return dfs(v, ind + 1, n);
        }

        for (int i = n; i >= 1; i--) { // �׸����ϰ� ū������ �־
            if (!visited[i]) { // ������� ���� ���̶��
                visited[i] = true;
                if (i == 1) { // 1�� ��� �Ѱ��� ĭ�� ä��� �ȴ�
                    v[ind] = i;
                    if (dfs(v, ind + 1, n)) return true;
                    v[ind] = 0;
                }
                else { // �������� �� ��ĭ
                    if (ind + i >= v.size() || v[ind + i]) { // ind + iĭ�� �迭�� ����� �Ѿ�ų� ���� �̹� �����Ѵٸ�
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