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

const int maxn = 1007;
int n, m, h, w;
int a[maxn][maxn], b[maxn][maxn];

// int f(int x, int y, int tar) {
//     int ans = 0;
//     FOR(i, x, x + h - 1) FOR(j, y, y + w - 1)
//         ans += abs(a[i][j] - tar);
    
//     return ans;
// }

bool check(int mid) {
    FOR(i, 1, n) FOR(j, 1, m) 
        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + (a[i][j] <= mid);

    bool is = 0;
    FOR(i, 1, n - h + 1) FOR(j, 1, m - w + 1) {
        int x = b[i + h - 1][j + w - 1] - b[i - 1][j + w - 1] - b[i + h - 1][j - 1] + b[i - 1][j - 1];
        if (x >= (h * w + 1) / 2) return 1;
    }
    return 0;
}

void process() {
    cin >> n >> m >> h >> w;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    int l = 0, r = intmax;
    int ans = intmax;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;

    // int ans = llongmax;
    // FOR(i, 1, n - h + 1) FOR(j, 1, m - w + 1) {
    //     int l = intmin, r = intmax;

    //     FOR(k, 1, 150) {
    //         int mid1 = l + (r - l) / 3;
    //         int mid2 = r - (r - l) / 3;
    //         if (f(i, j, mid1) > f(i, j, mid2)) l = mid1;
    //         else r = mid2;
    //     }

    //     mini(ans, (l + r) >> 1);
    //     // cout << (l + r) / 2 __ ;
    // }
    // cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("minimum.inp", "r")) {
        freopen("minimum.inp", "r", stdin);
        freopen("minimum.out", "w", stdout);
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