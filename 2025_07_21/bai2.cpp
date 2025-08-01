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
int n, k, a[maxn];

bool check(int tar) {
	int cnt = 1, cur = 0;
	FOR(i, 1, n) {
		if (a[i] > tar) return 0;
		if (cur + a[i] > tar) {
			cnt++;
			cur = a[i];
		} else cur += a[i];
		if (cnt > k) return 0;
	}
	return 1;
}	

void process() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    // sort(a + 1, a + 1 + n);	

    int l = 1, r = llongmax;
    int ans = r;
    while(l <= r) {
    	int mid = (l + r) >> 1;
    	if (check(mid)) {
    		ans = mid;
    		r = mid - 1; 
    	} else l = mid + 1;
    }
    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("bai2.inp", "r")) {
        freopen("bai2.inp", "r", stdin);
        freopen("bai2.out", "w", stdout);
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