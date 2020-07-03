
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
string table[]={ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
   vector<string>v;
   void generate(string s,string out,int i,int j)
   {
       if(i>=s.length())
       {
           cout<<out<<endl;
           return;

       }
       int digit=s[i]-'0';
       for(int k=0;k<table[digit].length();k++)
       {
           string ex=out;
           ex+=table[digit][k];

           generate(s,ex,i+1,j+1);
       }
       return;
   }
    int32_t main()
    {
        std::ios::sync_with_stdio(false);
        string s;
        cin>>s;
        generate(s,"",0,0);


        return 0;
    }
