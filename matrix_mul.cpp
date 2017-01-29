#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct matrix{
    ll row,column;
    ll mat[10][10];
};

matrix Mat_Mul(matrix A,matrix B,ll mod)
{
    matrix C;
    C.row = A.row;
    C.column = B.column;

    for(int i=1; i<=C.row; i++){
        for(int j=1; j<=C.column; j++){
            ll sum = 0;
            for(int k=1; k<=A.column; k++){
                sum = sum + A.mat[i][k] * B.mat[k][j];
                sum = (sum%mod+mod)%mod;
            }
            C.mat[i][j] = sum;
        }
    }
    return C;
}

matrix Mat_Expo(matrix Mat,ll power,ll mod)
{
    if (power==1) return Mat;
    else if (power%2==1)
        return Mat_Mul(Mat,Mat_Expo(Mat,power-1,mod),mod);
    matrix ret = Mat_Expo(Mat,power/2,mod);
    return Mat_Mul(ret,ret,mod);
}

int main ()
{
    matrix arr;
    arr.row = 2;
    arr.column = 2;
    for (ll i=1;i<=arr.row;i++)
    {
        for (ll j=1;j<=arr.column;j++)
        {
            arr.mat[i][j] = 2;
        }
    }
    ll n;
    while(cin>>n)
    {
        matrix ans = Mat_Expo(arr,n,10000000007);
        ll r = ans.row;
        ll c = ans.column;
        for (ll i=1;i<=r;i++)
        {
            for (ll j=1;j<=c;j++)
            {
                cout<<ans.mat[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
