#include<bits/stdc++.h>
using namespace std;

#ifdef TGX
#include "D:\egoist\debug.h"
#else 
#define debug(...)
#endif

#define int long long

// vector<int> decomp(int x) {
// 	vector<int> ans;
// 	for(int i = 1; i * i <= x; i++) {
// 		if (x % i == 0) {
// 			ans.push_back(i);
// 			if (i != x / i) ans.push_back(x / i);
// 		}
// 	}
// 	return ans;
// }

const int maxval = 1e7 + 7;
vector<int> snt;
vector<bool> check(maxval, 1);
void sieve() {
	check[0] = check[1] = 0;
	for(int i = 2; i * i <= 7000000; i++) {
		if (check[i] == 1) {
			for(int j = i * i; j <= 7000000; j += i) check[j] = 0;
		}
	}
	snt.push_back(2);
	for(int i = 3; i <= 7000000; i += 2) if (check[i] == 1) snt.push_back(i);
}


// int cnt[maxval];
void process() {
	sieve();
	int n; cin >> n;

	int ans = 0;

	// case1 
	int idx = 0;
	while(1) {
		int val = snt[idx];
		if (val * val * val > n) break;
		ans++;
		idx++;
	}

	// for(int i = 0; i <= 10; i++) cout << snt[i] ___ ; cout __ ;
	int l = 0, r = 0;
	while(1) {
		if (2 * snt[r + 1] > n) break;
		r++;
	}

	while(1) {
		while(r > 0 and snt[l] * snt[r] > n) r--;
		if (l > r) break;
		ans += (r - l);
		l++;
	}

	// cout << l _ r __ ;

	cout << ans;
	// int ans = 0;
	// for(int i = 1; i <= 100000; i++) {
	// 	vector<int> val = decomp(i);
	// 	if ((int)(val.size()) == 4 and val[3] % val[2] == 0) {
	// 		cout << i << " : " << val __ ;
	// 	}
	// }
}

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("temp.inp", "r")) {
		freopen("temp.inp", "r", stdin);
		freopen("temp.out", "w", stdout);
	} else {
		freopen("fourdiv.inp", "r", stdin);
		freopen("fourdiv.out", "w", stdout);
	}
	process();
	cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << " ms.\n";
}

/*
6 : { 1, 6, 2, 3 } 
8 : { 1, 8, 2, 4 } 
10 : { 1, 10, 2, 5 } 
14 : { 1, 14, 2, 7 } 
15 : { 1, 15, 3, 5 } 
21 : { 1, 21, 3, 7 } 
22 : { 1, 22, 2, 11 } 
26 : { 1, 26, 2, 13 } 
27 : { 1, 27, 3, 9 } 
33 : { 1, 33, 3, 11 } 
34 : { 1, 34, 2, 17 } 
35 : { 1, 35, 5, 7 } 
38 : { 1, 38, 2, 19 } 
39 : { 1, 39, 3, 13 } 
46 : { 1, 46, 2, 23 } 
51 : { 1, 51, 3, 17 } 
55 : { 1, 55, 5, 11 } 
57 : { 1, 57, 3, 19 } 
58 : { 1, 58, 2, 29 } 
62 : { 1, 62, 2, 31 } 
65 : { 1, 65, 5, 13 } 
69 : { 1, 69, 3, 23 } 
74 : { 1, 74, 2, 37 } 
77 : { 1, 77, 7, 11 } 
82 : { 1, 82, 2, 41 } 
85 : { 1, 85, 5, 17 } 
86 : { 1, 86, 2, 43 } 
87 : { 1, 87, 3, 29 } 
91 : { 1, 91, 7, 13 } 
93 : { 1, 93, 3, 31 } 
94 : { 1, 94, 2, 47 } 
95 : { 1, 95, 5, 19 } 
*/