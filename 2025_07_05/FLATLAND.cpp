/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>

#define FOR(i, a, b)       for (int i = (a), _b = (b); i <= _b; i += 1)
#define FORD(i, a, b)      for (int i = (a), _b = (b); i >= _b; i -= 1)

#define fi                 first
#define se                 second
#define pb                 push_back
#define len(x)             (int)((x).size())
#define all(x)             (x).begin(), (x).end()

#define _                  << " " <<
#define __                 << "\n"
#define ___                << " "

#define ______________TgX______________ main()
#define int                long long
#define intmax             1e9
#define intmin            -1e9
#define llongmax           1e18
#define llongmin          -1e18
#define memo(a, val)       memset((a), (val), sizeof((a)))

using   namespace std;
typedef long long          ll;
typedef pair<int, int>     pii;

template<typename T1, typename T2> 
bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> 
bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
    
/*-----------------------------*/

const int maxn = 1007;
int n, m;
int a[maxn][maxn];

namespace sub1 {
	bool check(int x1, int y1, int x2, int y2) {
		int tar = a[x1][y1];
		FOR(i, x1, x2) FOR(j, y1, y2) {
			if (a[i][j] != tar) return 0;
		}
		return 1;
	}

	void sol() {
		int ans = 1;
		FOR(x1, 1, n) FOR(x2, x1, n) 
			FOR(y1, 1, m) FOR(y2, y1, m) 
				if (check(x1, y1, x2, y2)) {
					maxi(ans, 2 * (abs(x2 - x1) + abs(y2 - y1) + 2));
				}
		cout << ans;
	}
}

int st_max[11][11][maxn][maxn];
int st_min[11][11][maxn][maxn];

void build() {
	FOR(i, 1, n) FOR(j, 1, m)
           st_max[0][0][i][j] = st_min[0][0][i][j] = a[i][j];

    for (int k1 = 0; (1 << k1) <= n; ++k1)
        for (int k2 = 0; (1 << k2) <= m; ++k2) {
            if (k1 == 0 and k2 == 0) continue;

            for (int i = 1; i + (1 << k1) - 1 <= n; ++i)
                for (int j = 1; j + (1 << k2) - 1 <= m; ++j) {
                    if (k1 == 0) {
                        st_max[k1][k2][i][j] = max(
                            st_max[k1][k2 - 1][i][j],
                            st_max[k1][k2 - 1][i][j + (1 << (k2 - 1))]
                        );
                        st_min[k1][k2][i][j] = min(
                            st_min[k1][k2 - 1][i][j],
                            st_min[k1][k2 - 1][i][j + (1 << (k2 - 1))]
                        );
                    } else {
                        st_max[k1][k2][i][j] = max(
                            st_max[k1 - 1][k2][i][j],
                            st_max[k1 - 1][k2][i + (1 << (k1 - 1))][j]
                        );
                        st_min[k1][k2][i][j] = min(
                            st_min[k1 - 1][k2][i][j],
                            st_min[k1 - 1][k2][i + (1 << (k1 - 1))][j]
                        );
                    }
                }
        }
}

int query_max(int x1, int y1, int x2, int y2) {
    int kx = __lg(x2 - x1 + 1);
    int ky = __lg(y2 - y1 + 1);
    int m1 = st_max[kx][ky][x1][y1];
    int m2 = st_max[kx][ky][x2 - (1 << kx) + 1][y1];
    int m3 = st_max[kx][ky][x1][y2 - (1 << ky) + 1];
    int m4 = st_max[kx][ky][x2 - (1 << kx) + 1][y2 - (1 << ky) + 1];
    return max({m1, m2, m3, m4});
}

int query_min(int x1, int y1, int x2, int y2) {
    int kx = __lg(x2 - x1 + 1);
    int ky = __lg(y2 - y1 + 1);
    int m1 = st_min[kx][ky][x1][y1];
    int m2 = st_min[kx][ky][x2 - (1 << kx) + 1][y1];
    int m3 = st_min[kx][ky][x1][y2 - (1 << ky) + 1];
    int m4 = st_min[kx][ky][x2 - (1 << kx) + 1][y2 - (1 << ky) + 1];
    return min({m1, m2, m3, m4});
}


namespace subful {
	void sol() {
		build();

		int ans = 1;

		FOR(x1, 1, n) FOR(y1, 1, m) {
			if (2 * ((n - x1 + 1) + (m - y1 + 1)) <= ans) break;

			FOR(x2, x1, n) if (a[x1][y1] == a[x2][y1]) {
				int y2 = y1;
				int l = y1, r = m;
				while(l <= r) {
					int mid = (l + r) >> 1;
					if (query_max(x1, y1, x2, mid) == query_min(x1, y1, x2, mid)) {
						y2 = mid;
						l = mid + 1;
					} else r = mid - 1;
				}

				maxi(ans, 2 * (abs(x2 - x1) + abs(y2 - y1) + 2));
			} else break;
		}

		cout << ans;
	}
};

void process() {
	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

	subful::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("FLATLAND.inp", "r")) {
        freopen("FLATLAND.inp", "r", stdin);
        freopen("FLATLAND.out", "w", stdout);
    }
    process();
    cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << " ms.\n";
}


/*==============================+
|INPUT                          |
--------------------------------|
6 8
0 0 1 0 0 0 0 0
1 0 1 0 1 1 1 1
1 0 1 0 1 1 1 1
1 0 1 0 1 1 1 1
1 0 1 0 1 1 1 1
1 1 1 1 1 1 1 1

18

5 5
1 2 3 2 1
2 1 3 2 1
3 1 3 3 1
4 4 2 3 1
4 4 5 5 5

10
================================+
|OUTPUT                         |
--------------------------------|

===============================*/