
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;
void merge(int *a, int s, int e)
{
	int temp[100];

	int l = s;
	int m = (s + e) / 2;
	int j = m + 1, k = e;
	while (s <= m && j <= e)
	{
		if (a[s] > a[j])
			temp[l++] = a[j++];
		else
			temp[l++] = a[s++];
	}
	while (s <= m)
	{
		temp[l++] = a[s++];
	}
	while (j <= e)
		temp[l++] = a[j++];

	for (int i = 0; i < l; i++)
	{
		a[i] = temp[i];
		//cout << temp[i] << " ";
	}
	//cout << endl;
}
void mergesort(int *a, int start, int end)
{
	if (start >= end)
		return;
	int mid = (start + end) / 2;
	mergesort(a, start, mid);
	mergesort(a, mid + 1, end);

	merge(a, start, end);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//int n = sizeof(a) / sizeof(int);
	mergesort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
