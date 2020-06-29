
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define int long long int
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
int power(int base, int exp)
{
    if (exp == 0)
       return 1;
    else if (exp == 1)
       return base;
    else
    {
       int calc;
       if (exp % 2 == 0)
       {
         calc = power(base, exp/2);
         calc =(calc* calc)%mod;
       }
       else
       {
         calc = (base*power(base, exp-1))%mod;
       }
       return calc%mod;
    }
}
    void go(string s,int open,int close,int n)
    {

        if(close==n)
        {
            cout<<s<<endl;
            return;
        }

        if(open>close)
        {a
            go(s+")",open,close+1,n);
        }
        if(open<n)
        {
            go(s+="(",open+1,close,n);
        }
    }
    int32_t main()
    {
        std::ios::sync_with_stdio(false);
        int n;
        cin>>n;
        go("(",1,0,n);
        return 0;
    }
