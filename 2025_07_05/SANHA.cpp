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

const int maxn = 1e5 + 7;
int n, q, a[maxn];

namespace sub1 {

	int solve(int l, int r) {
	    if (l > r) return 0;
	    int mmin = a[l];

	    vector<int> pos;
		FOR(i, l, r) {
	        if (a[i] < mmin) {
	            mmin = a[i];
	            pos.clear();
	            pos.pb(i);
	        } else if (a[i] == mmin) {
	            pos.pb(i);
	        }
	    }

	    int ans = 1;

	    ans += solve(l, pos[0] - 1);
	    FOR(i, 1, len(pos) - 1)
	        ans += solve(pos[i - 1] + 1, pos[i] - 1);
	    ans += solve(pos.back() + 1, r);

	    return ans;
	}

	void sol() {
	    while (q--) {
	        int l, r; cin >> l >> r;
	        cout << solve(l, r) << '\n';
	    }
	}
};

unordered_map<int, vector<int>> valpos;
int st[maxn][20];

void build(int n) {
	FOR(i, 1, n) st[i][0] = a[i];

	for(int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int get(int l, int r) {	
	int k = __lg(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

namespace subful {
	unordered_map<int, int> mm;

	int solve(int l, int r) {
	    if (l > r) return 0;

	    int key = l * maxn + r;
	    if (mm.count(key)) return mm[key];

	    int mmin = get(l, r);
	    vector<int> &positions = valpos[mmin];

	    int u = lower_bound(positions.begin(), positions.end(), l) - positions.begin();
	    int v = upper_bound(positions.begin(), positions.end(), r) - positions.begin() - 1;
	    if (u > v) return mm[key] = r - l + 1;

	    int ans = 1;
	    ans += solve(l, positions[u] - 1);
		FOR(i, u + 1, v) 
	        ans += solve(positions[i - 1] + 1, positions[i] - 1);
	    ans += solve(positions[v] + 1, r);

	    return mm[key] = min(ans, r - l + 1);
	}

	void sol() {
		build(n);
		unordered_map<int, int> mm;
	    while (q--) {
	        int l, r;
	        cin >> l >> r;
	        cout << solve(l, r) << '\n';
	    }
	}
};

void process() {
    cin >> n >> q;
    FOR(i, 1, n) {
    	cin >> a[i];
        valpos[a[i]].push_back(i);
	}

	subful::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("SANHA.inp", "r")) {
        freopen("SANHA.inp", "r", stdin);
        freopen("SANHA.out", "w", stdout);
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