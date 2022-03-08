// �巡�� �� ����
// https://www.acmicpc.net/problem/16434

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll, pair<ll, ll>>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	ll initAttack;
	cin >> n >> initAttack;

	ll t, a, h;
	for (int i = 0; i < n; i++) {
		cin >> t >> a >> h;
		v.push_back({ t,{a,h} });
	}

	ll low = 0, high = 1e18;
	while (low <= high) { // �̺� Ž�� ����
		ll mid = (low + high) / 2; // �߰���
		ll attack = initAttack; // ����� �ʱ� ���ݷ�
		ll hp = mid; // ����� �ʱ� �����
		for (int i = 0; i < n; i++) {
			t = v[i].first;
			a = v[i].second.first;
			h = v[i].second.second;
			if (t == 1) { // �濡 ���Ͱ� ������
				if (h % attack == 0) hp -= (h / attack - 1) * a; // ��簡 ���� ���̸� ���ʹ� �����Ҽ� ���⶧���� 1�� ����
				else hp -= (h / attack) * a;

				if (hp <= 0) { // ��簡 ������
					break;
				}
			}
			else { // �濡 ������ ������
				attack += a;
				hp = min(hp + h, mid); // �������� �ִ� hp�� �Ѿ�� ����.
			}
		}

		if (hp <= 0) { // ��簡 �׾��ٸ� ü���� mid���� ��������.
			low = mid + 1;
		}
		else { // ��簡 ��Ҵٸ� ü���� mid���� ���纻��.
			high = mid - 1;
		}
	}

	cout << low << '\n';
	return 0;
}