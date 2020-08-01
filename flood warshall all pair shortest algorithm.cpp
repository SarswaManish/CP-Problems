
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


int dx[] = { -1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};


struct abc
{
	int l, r, col;
};


int super_parent(int x, int a[])
{
	return (a[x] == x ? x : a[x] = super_parent(a[x], a));
}


void unite(int x, int y, int a[])
{

	x = super_parent(x, a);
	y = super_parent(y, a);

	if (x != y)
	{
		a[x] = a[y] = max(a[x], a[y]);
	}
}

bool comp(abc a, abc b)
{
	return a.col < b.col;
}



int32_t main()
{
	std::ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif


	int n, m;
	cin >> n >> m;
	int dist[n + 1][n + 1];


	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dist[i][j] = 10000006;
		}

	}




	vector<pii>v[n + 1];

	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back(mp(y, cost));
		//v[y].push_back(mp(x, cost));
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto j : v[i])
		{
			int nod = j.f;
			int we = j.s;
			dist[i][nod] = we;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dist[i][j] << " ";

		}
		cout << endl;
	}


	return 0;
}
