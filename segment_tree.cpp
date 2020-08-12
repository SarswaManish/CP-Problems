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
int n, m;
vector<int>v[N];
int vis[N] = {};
 
 
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
 
void build_tree(int segment[], int s, int e, int index, int a[])
{
 
	if (s == e)
	{
		segment[index] = a[s];
		return;
	}
 
	int mid = (s + e) / 2;
	build_tree(segment, s, mid, 2 * index, a);
	build_tree(segment, mid + 1, e, 2 * index + 1, a);
 
	segment[index] = (segment[2 * index] + segment[2 * index + 1]);
	return;
}
 
 
 
int query(int a[], int s, int e, int l, int r, int index)
{
 
	if (l <= s &&  r >= e )
		return a[index];
 
 
	if (r < s ||  l > e)
		return 0;
 
	int mid = (s + e) / 2;
 
	int left = query(a, s, mid, l, r, 2 * index);
	int right = query(a, mid + 1, e, l, r, 2 * index + 1);
 
	return (left + right);
 
}
 
 
void update(int segment[], int s, int e, int i, int index, int incr)
{
 
 
 
	if (s > i || e < i)
		return;
 
	if (s == e)
	{
		segment[index] = incr;
		return;
	}
 
	int mid = (s) + (e - s) / 2;
 
	update(segment, s, mid, i, 2 * index, incr);
	update(segment, mid + 1, e, i, 2 * index + 1, incr);
 
	segment[index] = (segment[2 * index] + segment[2 * index + 1]);
	return;
}
 
 
int32_t main()
{
	std::ios::sync_with_stdio(false);
 
	/*#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif*/
 
//segment tree problem
	int n;
	cin >> n ;
	int q;
	cin >> q;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
 
	//build
 
	int segment_tree[4 * n + 1] = {};
 
 
	build_tree(segment_tree, 0, n - 1, 1, a);
	/*
		for (int i = 0; i < 4 * n; i++)
			cout << segment_tree[i] << " ";
	*/
 
 
	while (q--)
	{
		int choice;
		cin >> choice;
		int l, r;
		cin >> l >> r;
		l--, r--;
 
		if (choice == 1)
		{
			update(segment_tree, 0, n - 1, l, 1, r + 1);
		}
		else
		{
			int res = query(segment_tree, 0, n - 1, l, r, 1);
			cout << res << endl;
		}
 
		/*for (int i = 0; i < 4 * n; i++)
			cout << segment_tree[i] << " ";
		cout << endl;*/
 
	}
 
	return 0;
 }
