
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
//inversion count :- count the pairs where a[i]>a[j] && i<j.
int merge(int *a, int s, int e)
{
	int m = (s + e) / 2;
	int temp[100];
	int i = s;
	int j = m + 1;
	int k = s;
	int c = 0;
	while (i <= m && j <= e)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			c += (m - i + 1);
		}
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= e)
		temp[k++] = a[j++];
	for (int i = s; i <= e; i++)
		a[i] = temp[i];
	return c;

}
int inversion_count(int *a, int s, int e)
{
	if (s >= e)
		return 0;
	int m = (s + e) / 2;
	int x = inversion_count(a, s, m);
	int y = inversion_count(a, m + 1, e);
	int z = merge(a, s, e);
	return z + x + y;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << inversion_count(a, 0, n - 1);


	return 0;
}
