#include<bits/stdc++.h>
#define ll long long unsigned
using namespace std;

ll Multiply(ll a,ll b,ll mod)
{
    ll ret;
    if(b == 0 )return 0;
    if(b%2 == 0)
    {
        ll temp = Multiply(a,b/2,mod);
        ret = (temp%mod+temp%mod)%mod;
    }
    else
    {
        ll temp = Multiply(a,b/2,mod);
        ret = (a%mod+temp%mod+temp%mod)%mod;
    }
    return ret;
}

ll power(ll base,ll pwr,ll mod)
{
    ll ret;
    if(pwr == 0 )return 1;
    if(pwr%2 == 0)
    {
        ll temp = power(base,pwr/2,mod);
        ret =  Multiply(temp,temp,mod);
    }
    else
    {
        ll temp = power(base,pwr/2,mod);
        ret = Multiply(base,Multiply(temp,temp,mod),mod);
    }
    return ret;
}

int main ()
{
    ll cases,caseno=0,A,B,C,ans;
    scanf("%llu",&cases);
    while(cases--)
    {
        scanf("%llu%llu%llu",&A,&B,&C);
        ///ans = bigMultiply(A,B,C);
        ans = power(A,B,C);
        printf("Case %llu: %llu\n",++caseno,ans%C);
    }
    return 0;
}
