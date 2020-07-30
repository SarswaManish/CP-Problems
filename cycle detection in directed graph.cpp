
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




void dfs(int u, int vis[], vector<int>v[], vector<int>&ordering)
{

	vis[u] = 1;
	//sort(v[u].begin(), v[u].end());
	for (int i = 0; i < v[u].size(); i++)
	{
		if (!vis[v[u][i]])
			dfs(v[u][i], vis, v, ordering);
	}
	ordering.push_back(u);
	return;

}


int cycle_helper(int vis[], int stack[], vector<int>v[], int u)
{
	vis[u] = 1;
	stack[u] = 1;


	for (int i = 0; i < v[u].size(); i++)
	{
		if (stack[v[u][i]])
			return true;
		else if (!vis[v[u][i]])
		{
			int cycle_mil = cycle_helper(vis, stack, v, v[u][i]);
			if (cycle_mil)
				return true;
		}
	}
	stack[u] = 0;
	return false;
}
int32_t main()
{
	std::ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int>v[n + 1];

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
	}

	int vis[n + 1] = {0};
	int stack[n + 1] = {0};

	cout << cycle_helper(vis, stack, v, 1) << endl;


	return 0;
}
