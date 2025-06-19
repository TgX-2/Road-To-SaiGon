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
int n, q;

int seg[maxn << 2], lazy[maxn << 2];
void down(int id) {
	int c = lazy[id];
	if (c != 0) {
		seg[id << 1] = c;
		seg[id << 1 | 1] = c;
		lazy[id << 1] = c;
		lazy[id << 1 | 1] = c;
	}
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int c) {
	if (v < l or r < u) return;
	if (u <= l and r <= v) {
		seg[id] = c;
		lazy[id] = c;
		return;
	}

	down(id);

	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, c);
	update(id << 1 | 1, mid + 1, r, u, v, c);

	seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

int get(int id, int l, int r, int pos) {
	if (pos < l or r < pos) return -1;
	if (l == r) return seg[id];
	down(id);
	int mid = (l + r) >> 1;
	return max(get(id << 1, l, mid, pos), get(id << 1 | 1, mid + 1, r, pos));
}

void process() {
    cin >> n >> q;
    FOR(i, 1, q) {
    	int l, r, c; cin >> l >> r >> c;
    	update(1, 1, n, l, r, c);
    }

    FOR(i, 1, n) cout << get(1, 1, n, i) ___ ;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("color.inp", "r")) {
        freopen("color.inp", "r", stdin);
        freopen("color.out", "w", stdout);
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