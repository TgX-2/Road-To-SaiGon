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

const int maxn = 2007;
const int mod  = 1e9 + 7;
int n;
pair<int, int> pos[maxn];

// vector<int> g[maxn];
// struct Matrix {
//     int n, m;
//     vector <vector <int> > x;

//     vector<int> & operator[] (int i) { return x[i]; }
//     const vector<int> & operator[] (int i) const { return x[i]; }

//     Matrix(int r, int c) : x(r, vector <int> (c)), n(r), m(c) { }
//     Matrix(const vector<vector<int>> &x) : x(x), n(x.size()), m(x[0].size()) { }

//     Matrix operator+ (const Matrix &b) {
//         Matrix ans(m, n);
//         for(int i = 0; i < m; i++) 
//             for(int j = 0; j < n; j++)
//                 (ans[i][j] = x[i][j] + b[i][j]) %= mod;
//         return ans;
//     }

//     Matrix operator* (const Matrix &b) {
//         Matrix& a = *this;
//         assert(a.m == b.n);
//         Matrix c(a.n, b.m);
//         for (int i = 0; i < a.n; ++i)
//             for (int j = 0; j < b.m; ++j)
//                 for (int k = 0; k < a.m; ++k)
//                     (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
//         return c;
//     }

//     Matrix operator^ (int exp) {
//         assert(n == m);
//         Matrix base = *this;
//         Matrix ans(n, n);
//         for(int i=0; i<n; i++) ans[i][i] = 1;
//         for (; exp > 0; exp >>= 1, base = base * base)
//             if (exp & 1) ans = ans * base;
//         return ans;
//     }
// };

// ostream& operator<< (ostream &out, const Matrix &d) {
//     for (auto a : d.x) {
//         for (auto b : a) out << b << ' ';
//         out << '\n';
//     }
//     return out;
// }

int dp[maxn];

class FenwickTree {
private:
    int n;
    vector<int> bit;

    int query(int pos) {
        int ans = 0;
        for(; pos >= 1; pos -= (pos & -pos)) (ans += bit[pos]) %= mod;
        return ans;
    }

    void change(int pos, int val) {
        for(; pos <= n; pos += (pos & -pos)) (bit[pos] += val) %= mod;
    }

public:
    FenwickTree(int _n) {
        n = _n;
        bit.assign(n + 7, 0);
    }

    void update(int pos, int val) { change(pos, val); }
    void update(int l, int r, int val) {
        change(l, val);
        change(r + 1, -val);
    }
    int get(int l) { return query(l); }
    int get(int l, int r) { return (query(r) - query(l - 1) + mod) % mod; }
};

void process() {
    cin >> n;

    vector<int> val;
    FOR(i, 1, n) {
    	cin >> pos[i].fi;
    }

    FOR(i, 1, n) {
    	cin >> pos[i].se;
    	val.pb(pos[i].se);
    }

    sort(all(val));
    val.erase(unique(all(val)), val.end());

    sort(pos + 1, pos + 1 + n);
    FOR(i, 1, n) {
    	pos[i].se = lower_bound(all(val), pos[i].se) - val.begin() + 1;
    	// cout << pos[i] __ ;
    }

    int m = len(val);

    FOR(i, 1, n) dp[i] = 1;
    FOR(k, 1, n) {
    	FenwickTree fen(m);
    	int ans = 0;
    	FOR(i, 1, n) (ans += dp[i]) %= mod;
    	cout << ans ___ ;

    	FOR(i, 1, n) {
    		fen.update(pos[i].se, dp[i]);
    		if (pos[i].se + 1 > m) dp[i] = 0;
    		else dp[i] = fen.get(pos[i].se + 1, m);	
    	}

    	// FOR(i, 1, n) cout << dp[i] ___ ;
    	// cout __ ;
    }


    // Matrix aa(n, n);
    // FOR(i, 1, n) FOR(j, 1, n) {
    // 	if (pos[j].fi > pos[i].fi and pos[j].se < pos[i].se) {
    // 		// cout << i _ j __ ;
    // 		aa[j - 1][i - 1] = 1;
    // 	}
    // }

    // Matrix ans = aa ^ 0;


    // FOR(k, 0, n - 1) {
    // 	int cnt = 0;
    // 	FOR(i, 0, n - 1) FOR(j, 0, n - 1) (cnt += ans[i][j]) %= mod;
    // 	cout << cnt ___ ;
    // 	if (cnt == 0) {
    // 		FOR(j, k + 1, n - 1) cout << 0 ___ ;
    // 		return;
    // 	}
    // 	ans = ans * aa;
    // }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("duyenhai.inp", "r")) {
        freopen("duyenhai.inp", "r", stdin);
        freopen("duyenhai.out", "w", stdout);
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