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
const int block_size = 316;
int n, q, a[maxn];

struct query {
	int l, r, idx;
 	bool operator < (const query &other) const {
 		int block_a = l / block_size;
 		int block_b = other.l / block_size;
 		if (block_a != block_b) return block_a < block_b;
 		return ((block_a & 1) ? (r < other.r) : (r > other.r));
 	}
} qq[maxn];

int ansa = 0, ansb = 0, ansc = 0;
void add(int idx) {
	int col = a[idx];	
	if (col == 1) ansa++;
	else if (col == 2) ansb++;
	else if (col == 3) ansc++;
}

void del(int idx) {
	int col = a[idx];
	if (col == 1) ansa--;
	else if (col == 2) ansb--;
	else if (col == 3) ansc--;
}

array<int, 3> ans[maxn];

void process() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, q) {
    	int l ,r; cin >> l >> r;
    	qq[i] = {l, r, i};
    }
    sort(qq + 1, qq + 1 + q);

    int l = 1, r = -1;
    FOR(i, 1, q) {
    	int ll = qq[i].l, rr = qq[i].r, idx = qq[i].idx;
    	while(l > ll) add(--l);
    	while(r < rr) add(++r);
    	while(l < ll) del(l++);
    	while(r > rr) del(r--);	

    	ans[idx] = {ansa, ansb, ansc};
    }

    FOR(i, 1, q) cout << ans[i][0] _ ans[i][1] _ ans[i][2] __ ;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("mangosteen.inp", "r")) {
        freopen("mangosteen.inp", "r", stdin);
        freopen("mangosteen.out", "w", stdout);
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