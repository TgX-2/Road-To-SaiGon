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
int n, a[maxn];

int pre[maxn], f[maxn];
int cnt[10][10];


void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) {
    	f[i] = f[i - 1] + a[i] * pre[i - 1];
    	pre[i] = pre[i - 1] + a[i];
    	f[i] %= 7;
    	pre[i] %= 7;
    }

    cnt[0][0] = 1;
    int ans = 0;
    FOR(i, 1, n) {
    	FOR(j, 0, 6) FOR(k, 0, 6) 
    		if ((f[i] - pre[i] * j + j * j - k) % 7 == 0) ans += cnt[j][k];
    	cnt[pre[i]][f[i]]++;
    }
    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("div7.inp", "r")) {
        freopen("div7.inp", "r", stdin);
        freopen("div7.out", "w", stdout);
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