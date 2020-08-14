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
 
	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
 
		v[x].pb(mp(y, cost));
 
	}
 
	//dijkstra
 
	priority_queue<pii, vector<pii>, greater<pii> >pq;
	pq.push(mp(0, 1));
	int dist[n + 1] ;
	for (int i = 0; i <= n; i++)
		dist[i] = inf;
	dist[1] = 0;
	int cnt = 0;
	while (!pq.empty())
	{
		int weight = pq.top().f;
		int nod = pq.top().s;
 
		pq.pop();
 
		if (weight > dist[nod])
			continue;
		for (auto i : v[nod])
		{
			if (dist[i.f] > weight + i.s)
			{
				dist[i.f] = weight + i.s;
				pq.push(mp(dist[i.f], i.f));
			}
		}
 
	}
 
	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";
 
 
 
	return 0;
 
}
