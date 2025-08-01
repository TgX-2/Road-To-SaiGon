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
vector<bool> check(maxn, 1);
vector<int> snt;
void sieve() {
	check[0] = check[1] = 0;
	FOR(i, 2, 1000000) {
		if (check[i] == 1) {
			snt.pb(i);
			for(int j = i * i; j <= 1000000; j += i) check[j] = 0;
		}
	}
}

int poww(int a, int b) {
	if (b == 0) return 1;
	int x = poww(a, b / 2);
	if (b & 1) return x * x * a;
	return x * x;
}

void process() {
	sieve();
	int x;
	while(cin >> x) {
		unordered_map<int, int> decom;

		for(const int &val : snt) {
			int cnt = 0, n = x;
			if (val > x) break;
			while(n >= val) {
				n /= val;
				cnt++;
			}
			decom[val] = cnt;
		}

		if (decom.count(2) and decom.count(5)) {
			int mmin = min(decom[2], decom[5]);
			decom[2] -= mmin;
			decom[5] -= mmin;
		}

		int ans = 1;
		for(const pair<int, int> &val : decom) {
			ans = ans * poww(val.fi, val.se);
			ans %= 10;
		}

		cout << ans __ ;
	}
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("tc.inp", "r")) {
        freopen("tc.inp", "r", stdin);
        freopen("tc.out", "w", stdout);
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