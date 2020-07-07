#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
bitset<30>co,d1,d2;

void solve(int col)
{

    if(col==n)
      {
         ans++;
	    return;
      }

    for(int i=0;i<n;i++)
    {
       if(!co[i] && !d1[col-i+n-1] && !d2[col+i])
	   {
		   co[i]=d1[col-i+n-1]=d2[col+i]=1;
		   solve(col+1);
		   co[i]=d1[col-i+n-1]=d2[col+i]=0;

	   }

    }

}

int main()
{

	cin>>n;


	solve(0);

	cout<<ans<<endl;
	return 0;
}
