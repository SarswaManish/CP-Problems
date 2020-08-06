

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1e15
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 10005;
//vector<int>v[N];



//sparse_table

int32_t main()
{
	std::ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];


	int p2[n + 1] = {0};
	for (int i = 2; i <= n; i++)
	{
		p2[i] = p2[i / 2] + 1;
	}

	int m = p2[n] + 1;

	vector<vector<int>>v(n + 1, vector<int>(m));


	for (int i = 0; i < n; i++)
	{
		v[i][0] = a[i];
	}



	/*for (int i = 0; i <= n; i++)
		cout << p2[i] << " ";
	*/



	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j + (1 << i) <= n; j++)
		{
			v[j][i] = min(v[j][i - 1], v[j + (1 << (i - 1))][i - 1]);
		}
	}

	int query;
	cin >> query;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}




	while (query--)
	{
		int l, r;
		cin >> l >> r;
		int x = p2[r - l + 1];
		// cout << x << endl;
		// cout << l << " " << x << " " << "......" << r - (1 << x) + 1 << " " << x << endl;

		cout << min(v[l][x], v[r - (1 << x) + 1][x]) << endl;

	}
	return 0;
}

