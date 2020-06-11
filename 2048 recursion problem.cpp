
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
void recursion(int n)
{
	//base case
	if (n == 0)
		return;
	recursion(n / 10);
	int x = n % 10;
	if (x == 1)
		cout << "one ";
	if (x == 2)
		cout << "two ";
	if (x == 3)
		cout << "three ";
	if (x == 4)
		cout << "four ";
	if (x == 5)
		cout << "five ";
	if (x == 6)
		cout << "six ";
	if (x == 7)
		cout << "seven ";
	if (x == 8)
		cout << "eight ";
	if (x == 9)
		cout << "nine ";
	if (x == 0)
		cout << "zero ";

}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	recursion(n);
	return 0;
}
