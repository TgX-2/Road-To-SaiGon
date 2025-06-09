/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using   namespace std;

#ifdef TGX 
#include "debug.h"
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

const int maxn = 4e5 + 7; 
const int mod  = 1e9 + 7;

int fac[maxn], inv[maxn];

int poww(int a, int b) {
    if (b == 0) return 1;
    int x = poww(a, b / 2);
    if (b & 1) return ((x * x) % mod) * a % mod;
    return (x * x) % mod;
}

void process() {
    fac[0] = 1;
    FOR(i, 1, 400000) fac[i] = fac[i - 1] * i % mod;

    inv[400000] = poww(fac[400000], mod - 2);
    FORD(i, 400000, 1) inv[i - 1] = inv[i] * i % mod;

    FOR(n, 1, 10) FOR(k, 1, 10) {
        int x = n + k - 1;
        int ans = fac[x] * inv[n] % mod;
        ans = ans * inv[x - n] % mod;
        cout << ans ___ ;
        cout << " \n"[k == 10];
    }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("jewelry.inp", "r")) {
        freopen("jewelry.inp", "r", stdin);
        freopen("jewelry.out", "w", stdout);
    }
    process();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/