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

int mmax[maxn][30], mmin[maxn][30];
void build() {
	FOR(i, 1, n) {
		mmax[i][0] = a[i];
		mmin[i][0] = a[i];
	}

	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
			mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
			mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
		}
}

int getmax(int l, int r) {
	int k = __lg(r - l + 1);
	return max(mmax[l][k], mmax[r - (1 << k) + 1][k]);
}

int getmin(int l, int r) {
	int k = __lg(r - l + 1);
	return min(mmin[l][k], mmin[r - (1 << k) + 1][k]);
}

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    build();

    vector<pair<int, int>> ans;
    int l = 1, r = n;
    while(l < r) {
    	bool check1 = 0, check2 = 0;
    	// cout << a[l] << " : " << getmin(l + 1, r) __ ;
    	// cout << a[r] << " : " << getmax(l, r - 1) __ ;
    	if (a[l] <= getmin(l + 1, r)) check1 = 1;
    	if (a[r] >= getmax(l, r - 1)) check2 = 1;

    	if (check1 == 0 and check2 == 0) {
    		// cout << "rev : " << l _ r __ ;
    		ans.pb({l, r});
    		reverse(a + l, a + 1 + r);
    		build();
    		// l++;
    		r--;
    	} else {
    		if (check1) l++;
    		if (check2) r--;
    	}

    	FOR(i, 1, n) cout << a[i] ___ ; cout __ ;
    	// cout << l _ r __ ;
    	// cout << check1 _ check2 __ ;
    	// cout __ ;
    }

    l = 1, r = n;
    while(l < r) {
    	bool check1 = 0, check2 = 0;
    	// cout << a[l] << " : " << getmin(l + 1, r) __ ;
    	// cout << a[r] << " : " << getmax(l, r - 1) __ ;
    	if (a[l] <= getmin(l + 1, r)) check1 = 1;
    	if (a[r] >= getmax(l, r - 1)) check2 = 1;

    	if (check1 == 0 and check2 == 0) {
    		// cout << "rev : " << l _ r __ ;
    		ans.pb({l, r});
    		reverse(a + l, a + 1 + r);
    		build();
    		l++;
    		// r--;
    	} else {
    		if (check1) l++;
    		if (check2) r--;
    	}

    	FOR(i, 1, n) cout << a[i] ___ ; cout __ ;
    	// cout << l _ r __ ;
    	// cout << check1 _ check2 __ ;
    	// cout __ ;
    }

    l = 1, r = n;
    while(l < r) {
    	bool check1 = 0, check2 = 0;
    	if (a[l] <= getmin(l + 1, r)) check1 = 1;
    	if (a[r] >= getmax(l, r - 1)) check2 = 1;

    	if (check1 == 0 and check2 == 0) {
    		ans.pb({l, r});
    		reverse(a + l, a + 1 + r);
    		build();
    		// l++;
    		r--;
    	} else {
    		if (check1) l++;
    		if (check2) r--;
    	}

    	FOR(i, 1, n) cout << a[i] ___ ; cout __ ;
    }

        l = 1, r = n;
    while(l < r) {
    	bool check1 = 0, check2 = 0;
    	if (a[l] <= getmin(l + 1, r)) check1 = 1;
    	if (a[r] >= getmax(l, r - 1)) check2 = 1;

    	if (check1 == 0 and check2 == 0) {
    		ans.pb({l, r});
    		reverse(a + l, a + 1 + r);
    		build();
    	} else {
    		if (check1) l++;
    		if (check2) r--;
    	}

    	// FOR(i, 1, n) cout << a[i] ___ ; cout __ ;
    }


    cout << len(ans) __ ;
    for(const pair<int, int> &val : ans) cout << val.fi _ val.se __ ;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("sx.inp", "r")) {
        freopen("sx.inp", "r", stdin);
        freopen("sx.out", "w", stdout);
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