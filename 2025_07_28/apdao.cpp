#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define MASK(x) (1ULL << (x))
#define BIT(x, k) ((x) >> (k) & 1)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

template<typename T1, typename T2> bool maximize(T1 &x, const T2 &y){
	if (x < y){
		x = y;
		return 1;
	}
	return 0;
}

template<typename T1, typename T2> bool minimize(T1 &x, const T2 &y){
	if (x > y){
		x = y;
		return 1;
	}
	return 0;
}

#define file "APDAO"

void fastio(){
	freopen(file".INP", "r", stdin);
	freopen(file".OUT", "w", stdout);
}

const int maxn = 5e5 + 9;

struct Power{
	int r, w;
};

int n;
Power a[maxn];

namespace subLow{
	ll cost(int x, int y){
		return a[x].r * a[y].w > a[x].w * a[y].r; 
	}

	bool win(int x, int y, int z){
		return (cost(x, y) && cost(y, z) && cost(z, x));
	}

	bool check(int x, int y, int z){
		int player[3] = {x, y, z};

		bool running = 1;

		while (running){
			if (win(player[0], player[1], player[2]))
				return cout << x << " " << y << " " << z << endl, 1;

			running = next_permutation(player, player + 3);
		}

		return 0;
	}

	void solve(){
		int res = 0;

		for(int i = 1; i <= n - 2; ++i)
			for(int j = i + 1; j <= n - 1; ++j)
				for(int k = j + 1; k <= n; ++k)
					res += check(i, j, k);

		cout << res;
	}
}

void solve(){
	if (n <= 100)
		subLow::solve();
	else
		cout << 0;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	fastio();

	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> a[i].r >> a[i].w;

	solve();	


	cerr << "Time ran : " << TIME << "s\n";
	return 0;
}