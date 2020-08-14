

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

	cin >> n >> m;
	vector<vector<int>>v;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v.pb({x, y, z});
	}

	int dist[n + 1] = {0};
	for (int i = 2; i <= n; i++)
		dist[i] = -1 * 1000000000005;

	int f = 0;
	int res;
	for (int j = 1; j < n; j++)
	{
		for (auto i : v)
		{
			int from = i[0], to = i[1], cost = i[2];
			if (dist[from] != -1000000000005 && dist[to] < dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
				if (j == n)
					f = 1;
			}
		}
		if (j == n - 1)
			res = dist[n];
	}
	if (n > 1 && dist[n] > dist[n - 1])
		cout << -1 << endl;
	else
		cout << res << endl;
	return 0;

}


