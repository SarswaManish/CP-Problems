
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

bool ansestor(int x, int y)
{
	if (timin[x] <= timin[y] && timout[x] >= timout[y])
		return true;
	return false;
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

	vector<int>v[n + 1];
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int vis[n + 1] = {0};
	//eulor tour 1
	// for (int i = 1; i <= n; i++)
	// {
	// 	if (!vis[i])
	// 	{
	// 		eulor_1(i, vis, v, 1);
	// 	}
	// }


	//eulor tour 1
	//eulor_1(v, 1, 0);
	//eulor tour 2
	//eulor_2(v, 1, 0);

	//eulor tour 3
	eulor_3(v, 1, 0);
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << timin[i] << " " << timout[i] << endl;
	}


	if (ansestor(7, 9))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
