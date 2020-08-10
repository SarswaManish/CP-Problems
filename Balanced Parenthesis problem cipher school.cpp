

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
const int N = 10005;

//Balanced Pair Parenthesis
//its an classical stack problem

int32_t main()
{
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{

		string s;
		cin >> s;

		//if string balanced print("YES") else print("NO")

		stack<int>st;
		//stack to check the last opening parenthesis we are only going to put opening paranthesis definer inside the stack.

		//we are using stack as int for simplicity purpose
		//we are going to define '('=1 , '{'=2, '['=3,

		//let traverse the string  from left to right

		bool flag = true; //its working as a checker if any invalid condition occur we will mark it as false

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push(1);
			else if (s[i] == '{')
				st.push(2);
			else if (s[i] == '[')
				st.push(3);
			else if (!st.empty())
			{
				if ((s[i] == ')' && st.top() == 1) || (s[i] == '}' && st.top() == 2) || (s[i] == ']' && st.top() == 3))
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (!st.empty()) // this is for these type of test cases  {{()}
			flag = false;

		cout << (flag ? "YES" : "NO") << endl;
	}

	return 0;

}

