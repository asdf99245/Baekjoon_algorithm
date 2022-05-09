// 카카오머니
// https://www.acmicpc.net/problem/15998

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> diff;
ll temp;

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	else if (b == 0) return a;
	if (a >= b) {
		gcd(a % b, b);
	}
	else {
		gcd(a, b % a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, i;
	cin >> n;

	ll res = 0;
	for (i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a < 0 && res + a < 0) {
			if(i == 0) {
				temp = b - a - res;
			}
			else {
				temp = gcd(temp, b - a - res);
			}
		}
		res = b;
	}

	return 0;
}