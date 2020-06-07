
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
//quick sort
int partition(int *a, int s, int e)
{
	int i = s - 1;
	int j = s;
	int p = a[e];
	for (; j <= e - 1;)
	{
		if (a[j] <= p)
		{
			i += 1;
			swap(a[i], a[j]);
		}
		j += 1;
	}
	swap(a[i + 1], a[e]);
	return i + 1;
}
void quicksort(int *a, int s, int e)
{
	if (s >= e)
		return;
	int p = partition(a, s, e);
	quicksort(a, s, p - 1);
	quicksort(a, p + 1, e);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
