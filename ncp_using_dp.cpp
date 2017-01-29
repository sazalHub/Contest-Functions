#include<bits/stdc++.h>
using namespace std;
#define si(n) scanf("%d",&n)
int ncr_dp[100][100];

int ncr(int n,int r)
{
    if (r==1) return n;
    if (n==r) return 1;
    if (ncr_dp[n][r]!=-1) return ncr_dp[n][r];
    else
    {
        ncr_dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
        return ncr_dp[n][r];
    }
}

int main ()
{
    int n,i,r,j;

    for (i=0;i<100;i++)
        for (j=0;j<100;j++)
            ncr_dp[i][j]=-1;

    ncr_dp[1][2]=0;
    ncr_dp[2][2]=1;
    while(si(n))
    {
        cout<<ncr(50,2)<<endl;
        ///for (i=1;i<=20;i++)
            ///cout<<ncr_dp[i][2]<<endl;
    }
}
