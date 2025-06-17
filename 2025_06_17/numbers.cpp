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

const int maxn = 1e6 + 7;
const int mod  = 1e9 + 7;
int n, a[maxn], cnt[(1 << 21)];
int pw[maxn];

void process() {
    cin >> n;
    FOR(i, 1, n) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }


    pw[0] = 1;
    FOR(i, 1, n) pw[i] = pw[i - 1] * 2 % mod;

    FOR(i, 0, 20) {
    	FOR(mask, 0, (1 << 20) - 1) 
    		if ((mask & (1 << i)) != 0) cnt[mask ^ (1 << i)] += cnt[mask];
    }

    int ans = 0;
    FOR(mask, 0, (1 << 20) - 1) {
    	if (__builtin_popcount(mask) % 2 == 0) ans = (ans + pw[cnt[mask]]) % mod;
    	else ans = (ans - pw[cnt[mask]] + mod) % mod;
    }
    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("numbers.inp", "r")) {
        freopen("numbers.inp", "r", stdin);
        freopen("numbers.out", "w", stdout);
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