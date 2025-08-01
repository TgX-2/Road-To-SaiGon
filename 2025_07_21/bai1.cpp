#include <bits/stdc++.h>

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define rf if(fopen(name".inp", "r")) {freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);}
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

#define name "bai1"

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if(a > b) a = b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if(a < b) a = b; else return 0; return 1;}

const int mod = 1e9+7;
const int inf = 1e9+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 2e5+6;
const int LOG = 31 - __builtin_clz(N);

ll n, m;

void inp(){
    cin >> n >> m;
}

ll even(ll u, ll v){
    ll ans = 0;
    if ((u & 1) == (v & 1)){
        ans = ((u - 1) * m + 1) / 2;
        ans += (v + 1) / 2;
    }
    else{
        ans = (n * m + 1) / 2;
        ans += (u - 1) * m / 2;
        ans += (v + 1) / 2;
    }
    return ans;
}

ll odd(ll u, ll v){
    ll ans = (m / 2) * (u - 1), ad = m / 2 * n;
    ans += (v + 1) / 2;
    return ans + (v & 1 ? 0 : ad);
}

ll solve(int u, int v){
    if(m & 1) cout << even(u, v) << ' ';
    else cout << odd(u, v) << ' ';
}

void proc(){
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        solve(u, v);
    }
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