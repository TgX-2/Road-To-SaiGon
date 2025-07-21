/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using   namespace std;

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

struct custom {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class T1, class T2> using cmap = unordered_map<T1, T2, custom>;

template<typename T1, typename T2> 
bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> 
bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
/*-----------------------------*/

const int maxn = 1e5 + 7;
int n, a[maxn];

namespace sub1 {
	int f(int i) {
		int ans = 0;
		FOR(j, 1, n) {
			ans += abs(i - j) * abs(a[i] - a[j]);
		}
		return ans;
	}
	void sol() {	
		FOR(i, 1, n) cout << f(i) ___ ;
	}
};

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int n): n(n), f(n+1, 0) {}

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) f[i] += delta;
    }

    int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }

    int rangeSum(int i) const {
        return query(i);
    }
};

namespace sub2 {
	vector<int> val;
	int ans[maxn];
	
	void sol() {
		FOR(i, 1, n) val.pb(a[i]);
		sort(all(val));
		val.erase(unique(all(val)), val.end());
		FOR(i, 1, n) a[i] = lower_bound(all(val), a[i]) - val.begin() + 1;

		int m = len(val);
		// cout << m __ ;

		Fenwick fen_cnt(m), fen_aj(m), fen_j(m), fen_jaj(m);

		int total_cnt = 0, total_aj = 0, total_j = 0, total_jaj = 0;

		FOR(i, 1, n) {
			int curval = a[i]; 
	        int orival = val[curval - 1];

	        int val_cnt1  = fen_cnt.query(curval);
	        int val_aj1   = fen_aj.query(curval);
	        int val_j1    = fen_j.query(curval);
	        int val_jaj1  = fen_jaj.query(curval);

	        int val_cnt2  = total_cnt - val_cnt1;
	        int val_aj2   = total_aj  - val_aj1;
	        int val_j2    = total_j   - val_j1;
	        int val_jaj2  = total_jaj - val_jaj1;

	        int case11 = i * orival * val_cnt1 - i * val_aj1 - orival * val_j1 + val_jaj1;
	        int case12 = i * val_aj2 - i * orival * val_cnt2 - val_jaj2 + orival * val_j2;

	        ans[i] += case11 + case12;

	        fen_cnt.update(curval, 1);
	        fen_aj.update(curval, orival);
	        fen_j.update(curval, i);
	        fen_jaj.update(curval, i * orival);

	        // cout << "hah";

			total_cnt += 1;
	        total_aj  += orival;
	        total_j   += i;
	        total_jaj += i * orival;
		}

		fen_cnt = Fenwick(m);
		fen_aj  = Fenwick(m);
		fen_j   = Fenwick(m);
		fen_jaj = Fenwick(m);
		total_cnt = total_j = total_aj = total_jaj = 0;

		FORD(i, n, 1) {
			int curval = a[i]; 
	        int orival = val[curval - 1];

	        int val_cnt1  = fen_cnt.query(curval);
	        int val_aj1   = fen_aj.query(curval);
	        int val_j1    = fen_j.query(curval);
	        int val_jaj1  = fen_jaj.query(curval);

	        int val_cnt2  = total_cnt - val_cnt1;
	        int val_aj2   = total_aj  - val_aj1;
	        int val_j2    = total_j   - val_j1;
	        int val_jaj2  = total_jaj - val_jaj1;

	        int case21 = orival * (val_j1 - i * val_cnt1) - (val_jaj1 - i * val_aj1);
	        int case22 = (val_jaj2 - i * val_aj2) - orival * (val_j2 - i * val_cnt2);

	        ans[i] += case21 + case22;

	        fen_cnt.update(curval, 1);
	        fen_aj.update(curval, orival);
	        fen_j.update(curval, i);
	        fen_jaj.update(curval, i * orival);

	        // cout << "hah";

			total_cnt += 1;
	        total_aj  += orival;
	        total_j   += i;
	        total_jaj += i * orival;
		}

		FOR(i, 1, n) cout << ans[i] ___ ;
	}
}; 

void process() {
	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	sub1::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("seq.inp", "r")) {
        freopen("seq.inp", "r", stdin);
        freopen("seq.ans", "w", stdout);
    }
    process();
    cerr << "Time trau: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/
