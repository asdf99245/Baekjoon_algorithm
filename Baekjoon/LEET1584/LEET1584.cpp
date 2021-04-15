//Min Cost to Connect All Points
//https://leetcode.com/problems/min-cost-to-connect-all-points/

typedef pair<int, pair<int, int>> pipii;
class Solution {
private:
    vector<pair<int, pair<int, int>>> edge;
    int parent[1001];
    int find(int x) {
        if (x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }
    bool Union(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        parent[v] = u;
        return true;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int num = points.size(), i, j;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
        for (i = 0; i < num; i++) parent[i] = i;


        // ��尣 ���� �����ؼ� �켱����ť�� ����
        for (i = 0; i < num; i++) {
            for (j = i + 1; j < num; j++) {
                pq.push({ abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) , {i,j} });
            }
        }

        int res = 0;
        int cnt = 0;
        while (!pq.empty() && cnt != num - 1) { // ������ (���� - 1)�� ��ŭ �����Ǿ��ٸ� ��� ����Ǿ����Ƿ� ����
            int d = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            if (Union(u, v)) { // �� ��带 ���� �������� ������
                cnt++;
                res += d; // ���� ���� ����
            }
        }

        return res;
    }
};