
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
int a[1001][1001];
int tr=0;
int sol[1001][1001];
void print(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<sol[i][j]<<" ";
        cout<<endl;
    }
}
int ratinamaze(int i,int j,int n,int m)
{

    if(i==n-1 && j==m-1)
    {
        tr++;
        sol[i][j]=1;
        if(tr==1)
         {   print(n,m);
		 
		 }
		 return 1;
    }
    if(i>n || j>m)
        return 0;
    if(a[i][j]==-1)
        return 0;
    sol[i][j]=1;
	if(j+1<=m && !sol[i][j+1])
	{
     int right=ratinamaze(i,j+1,n,m);
	 if(right)
	 return true;
	}
	if(i+1<=n && !sol[i+1][j])
	{
     int left=ratinamaze(i+1,j,n,m);
	 if(left)
	 return true;
	}
    sol[i][j]=0;
   return false;

}
    int32_t main()
    {
        std::ios::sync_with_stdio(false);
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                sol[i][j]=0;
        }
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;j++)
            {
                char c=s[j];

                if(c=='O')
                    a[i][j]=0;
                else
                    a[i][j]=-1;
            }
        }
        ratinamaze(0,0,n,m);

        if(tr==0)
            cout<<-1<<endl;
        return 0;
    }
