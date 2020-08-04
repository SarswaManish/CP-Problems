

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
const int N = 100005;
int timin[N], timout[N], timer = 1;
vector<int>v[N];
set<int>art_p;
vector<pii>bridges;
int lowes_t[N], discove_t[N];
int dx[] = { -1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};


void eulor_1(vector<int>v[], int cur, int par)
{
	cout << cur << " ";
	timin[cur] = timer++;
	for (auto i : v[cur])
	{
		if (i != par)
		{
			eulor_1(v, i, cur);
			cout << cur << " ";
			timout[cur] = timer++ ;


		}
	}

}

void eulor_2(vector<int>v[], int cur, int par)
{
	cout << cur << " ";
	timin[cur] = timer++;
	for (auto i : v[cur])
	{
		if (i != par)
		{
			eulor_2(v, i, cur);
		}
	}
	cout << cur << " ";
	timout[cur] = timer++;
}


void eulor_3(vector<int>v[], int cur, int par)
{
	cout << cur << " ";
	timer++;
	timin[cur] = timer;
	for (auto i : v[cur])
	{
		if (i != par)
		{
			eulor_3(v, i, cur);
		}
	}
	timout[cur] = timer;
}

void dfs(int cur, int par)
{

	discove_t[cur] = lowes_t[cur] = timer++;
	int no_child = 0;
	for (auto i : v[cur])
	{
		if (discove_t[i] == 0)
		{
			dfs(i, cur);
			no_child++;
			lowes_t[cur] = min(lowes_t[cur], lowes_t[i]);
			if (par != 0 && lowes_t[i] >= discove_t[cur])
				art_p.insert(cur);


			if (lowes_t[i] > discove_t[cur])
				bridges.pb(mp(cur, i));

		}
		else if (i != par)
		{
			//backedge

			lowes_t[cur] = min(lowes_t[cur], discove_t[i]);
		}
	}
	if (par == 0 && no_child >= 2)
		art_p.insert(cur);

	return;
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

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}


	dfs(1, 0);
	//dfs(cur,par);

	for (auto i : art_p)
		cout << i << " ";

	cout << endl;
	for (auto i : bridges)
		cout << i.f << " " << i.s << endl;

	return 0;
}
/*input
5 5
1 2
2 3
3 1
3 4
4 5

output
articulation point
3 4

bridges
4 5
3 4*/
