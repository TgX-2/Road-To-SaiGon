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
int n, m, a[maxn];
vector<int> pos, neg;

void process() {
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
		if (a[i] < 0) neg.pb(-a[i]);
		else pos.pb(a[i]);
	}

	sort(all(neg), greater<int>());
	sort(all(pos), greater<int>());

	int ans = 0;
	int i = 0;
	while(i < len(neg)) {
		if (i >= len(neg)) break;
		ans += neg[i] * 2;
		i += m;
	}

	i = 0;
	while(i < len(pos)) {
		if (i >= len(pos)) break;
		ans += pos[i] * 2;
		i += m;
	}

	cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("delivery.inp", "r")) {
        freopen("delivery.inp", "r", stdin);
        freopen("delivery.out", "w", stdout);
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