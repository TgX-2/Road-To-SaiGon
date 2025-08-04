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

set<int> decomp(int x) {
	set<int> ans;
	for(int i = 2; i * i <= x; i++) {
		while(x % i == 0) {
			ans.insert(i);
			x /= i;
		}
	}
	if (x != 1) ans.insert(x);
	return ans;
}

int cnt[maxn];

vector<bool> check(maxn, 1);
int pos[maxn], val[maxn], idx = 0;
void sieve() {
	check[0] = check[1] = 0;
	for(int i = 2; i <= 100000; i++) {
		if (check[i] == 1) {
			val[i] = ++idx;
			for(int j = i * i; j <= 100000; j += i) check[j] = 0;
		}
	}
}

int ll[maxn], rr[maxn];

void process() {
	cin >> n;
	sieve();
	FOR(i, 1, n) {
		int x; cin >> x;
		set<int> v = decomp(x);
		// cout << x _ v __ ;
		for(const int &valu : v) 
			cnt[val[valu]]++;
	}
	FOR(i, 1, 100000) cnt[i] += cnt[i - 1];

	int pre = 0;
	FOR(i, 1, 100000) {
		if (val[i] != 0) pre = val[i];
		rr[i] = pre;
	}

	pre = 0;
	FORD(i, 100000, 1) {
		if (val[i] != 0) pre = val[i];
		ll[i] = pre;
	}

	int q; cin >> q;
	while(q--) {
		int l, r; cin >> l >> r;
		r = min(r, 100000LL);
		l = ll[l]; r = rr[r];
		cout << cnt[r] - cnt[l - 1] __ ;
	}

	// FOR(i, 1, 15) cout << val[i] ___ ; cout __ ;
	// FOR(i, 1, 15) cout << cnt[i] ___ ;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("prime.inp", "r")) {
        freopen("prime.inp", "r", stdin);
        freopen("prime.out", "w", stdout);
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