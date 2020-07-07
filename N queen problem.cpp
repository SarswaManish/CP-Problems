#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
int board[15][15];

bool issafe(int row,int col)
{

    int i=row-1,j=col-1;
  while(i>=0 && j>=0)
  {
      if(board[i][j]==1)
        return false;
        i--;
        j--;

  }

  for(int k=0;k<n;k++)
  {
      if(board[row][k])
        return false;
  }
  int x=row+1,y=col-1;
  while(x<n && y>=0)
  {
      if(board[x][y])
        return false;
      x++;
      y--;
  }

  return true;
}
bool solve(int col)
{

    if(col>=n)
      {
         ans++;
         return false;
      }

    for(int i=0;i<n;i++)
    {
        if(issafe(i,col))
        {
          board[i][col]=1;



        if(solve(col+1))
            return true;
        board[i][col]=0;
        }

    }
    return false;
}

int main()
{

	cin>>n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
		}
	}

	solve(0);

	cout<<ans<<endl;
	return 0;
}
