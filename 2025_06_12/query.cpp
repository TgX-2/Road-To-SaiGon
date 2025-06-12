/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using namespace std;

#ifdef TGX
#include "D:\egoist\debug.h"
#else 
#define debug(...)
#endif

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

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
/*-----------------------------*/

const int maxn = 2e5 + 7;
int n;

namespace sub1 {
	int a[1007][1007], b[1007][1007];
	vector<array<int, 3>> pos;

	int get(int x1, int y1, int x2, int y2) {
		return b[x2][y2] - b[x1 - 1][y2] - b[x2][y1 - 1] + b[x1 - 1][y1 - 1];
	}

	void sol() {
		int m = 0;
		FOR(i, 1, n) {
			int x, y, z; cin >> x >> y >> z;
			a[x][y] = z;
			maxi(m, x);
			maxi(m, y);
		}

		FOR(i, 1, m) FOR(j, 1, m) 
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];

		int ans = 0;
		FOR(i, 1, m - 1) FOR(j, i + 1, m)
			maxi(ans, get(i, i, j, j) - (j - i));
		cout << ans;
	}
};


void process() {
    cin >> n;

	sub1::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("query.inp", "r")) {
        freopen("query.inp", "r", stdin);
        freopen("query.out", "w", stdout);
    }
    process();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/