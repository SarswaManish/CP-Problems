
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

	using namespace std;


	int dx[] = { -1, 0, 0, 1};
	int dy[] = {0, 1, -1, 0};


	//strongly connected component

	void dfs(int u, int vis[], vector<int>v[], int col)
	{

		vis[u] = col;
		//sort(v[u].begin(), v[u].end());
		for (int i = 0; i < v[u].size(); i++)
		{
			if (vis[v[u][i]] == 0)
				dfs(v[u][i], vis, v, col);
		}
		return;

	}


	void dfs(vector<int>v[], vector<int>&ordering, int u, int vis[])
	{
		vis[u] = 1;
		for (int i = 0; i < v[u].size(); i++)
		{
			if (!vis[v[u][i]])
			{
				dfs(v, ordering, v[u][i], vis);
			}
		}
		ordering.push_back(u);
		return;
	}
	int32_t main()
	{
		std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("inputf.in", "r", stdin);
		freopen("outputf.in", "w", stdout);
	#endif
		int t;
		cin >> t;
		while (t--)
		{
			int n, m;
			cin >> n >> m;
			vector<int>v[n + 1], rev[n + 1];

			for (int i = 0; i < m; i++)
			{
				int x, y;
				cin >> x >> y;
				x++;
				y++;
				v[x].push_back(y);
				rev[y].push_back(x);
			}

			int vis[n + 1] = {0};
			int stack[n + 1] = {0};
			vector<int>ordering;
			int c = 0;
			for (int i = 1; i <= n; i++)
			{
				if (!vis[i])
				{
					dfs(v, ordering, i, vis);
					c++;
				}
			}

			//cout << c << endl;
			reverse(ordering.begin(), ordering.end());

			int cnt = 0;
			for (int i = 1; i <= n; i++)
				vis[i] = 0;


			int col = 1;
			for (int i = 0; i < n; i++)
			{
				if (vis[ordering[i]] == 0)
				{

					dfs(ordering[i], vis, rev, col);
					col++;
				}
			}

			cout << col - 1 << endl;
		}
		return 0;
	}
