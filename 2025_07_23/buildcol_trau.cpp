#include <bits/stdc++.h>

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define rf if(fopen(name".inp", "r")) {freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout);}
//#define in ({int x = 0; int c = getchar(), n = 0; for(; !isdigit(c); c = getchar()) n = (c == '-'); for(; isdigit(c); c = getchar()) x = x * 10 + c - '0'; n ? -x : x;})

#define bit(i, mask) (((mask) >> (i)) & 1)
#define on(i, mask) ((mask) | (1LL << (i)))
#define off(i, mask) ((mask) & (~(1LL << (i))))

#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define plx pair<ll, int>
#define vi vector<int>
#define vvi vector<vi>
#define all(a) (a).begin(), (a).end()
#define len(x) ((int)(x).size())
#define pb push_back
#define endl '\n'
#define ub(x, i) upper_bound(all(x), i) - x.begin()
#define lb(x, i) lower_bound(all(x), i) - x.begin()

#define name "buildcol"

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if(a > b) a = b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if(a < b) a = b; else return 0; return 1;}

const int mod = 1e9+7;
const int inf = 1e9+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 1e5+6;
const int LOG = 31 - __builtin_clz(N);

int n, a[N], b[N];
ll mn = oo, m;
int l[N], r[N];

void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mini(mn, a[i]);
    }
}

bool check(ll x){
    for(int i = 1; i <= n; i++){
        b[i] = (a[i] < x ? x : a[i]);
        l[i] = l[i - 1];
        maxi(l[i], b[i]);
    }
    ll ans = 0;
    for(int i = n; i >= 1; i--){
        r[i] = r[i + 1];
        maxi(r[i], b[i]);
        int x = min(l[i], r[i]);
        if(x >= b[i]) ans += x - b[i];
    }
    return ans >= m;
}

void proc(){
    ll l = mn, r = 2e9, res = -1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    rf

    int test = 1;
    //cin >> test;

    while(test--){
        inp();
        proc();
    }

    cerr << "Time elapsed: " << TIME << "s" << endl;
    return 0;
}
