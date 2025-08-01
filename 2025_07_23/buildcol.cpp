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
int n, x, a[maxn];

int wat[maxn], l[maxn], r[maxn];
bool check(int tar) {
	FOR(i, 1, n) wat[i] = max(a[i], tar);
	
	FOR(i, 0, n + 1) l[i] = r[i] = 0;
	FOR(i, 1, n) l[i] = max(l[i - 1], wat[i]);
	FORD(i, n, 1) r[i] = max(r[i + 1], wat[i]);

    int sum = 0;
    FOR(i, 1, n) {
    	if (l[i] == 0 or r[i] == 0) continue;
    	if (wat[i] <= min(l[i], r[i])) sum += min(l[i], r[i]) - wat[i];
    }
    return (sum >= x);
}

void process() {
    cin >> n >> x;

    int l = 0, r = 0;
    FOR(i, 1, n) {
    	cin >> a[i];
    	maxi(r, a[i]);
    }

    int ans = -1;
    while(l <= r) {
    	int mid = (l + r) >> 1;
    	if (check(mid)) {
    		ans = mid;
    		l = mid + 1;
    	} else r = mid - 1;
    }

    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("buildcol.inp", "r")) {
        freopen("buildcol.inp", "r", stdin);
        freopen("buildcol.out", "w", stdout);
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