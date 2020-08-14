

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
const int N = 1000005;
int n, m;
vector<pii>v[N];
int vis[N] = {};


int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int par[N] = {};
vector<int>v1;




int32_t main()
{
	std::ios::sync_with_stdio(false);

	/*#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif*/

	int q;
	cin >> n >> m >> q;

	int dp[501][501];

	//floyed warshall algorithm
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i][j] = inf;

	}

	for (int i = 0; i < n; i++)
		dp[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		x--, y--;

		//important part
		dp[x][y] = min(dp[x][y], cost);
		dp[y][x] = min(dp[y][x], cost);

	}

	/*
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}*/

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (dp[a][b] >= 10000000000000001)
			cout << -1 << endl;
		else
			cout << dp[a][b] << endl;
	}




	return 0;

}


