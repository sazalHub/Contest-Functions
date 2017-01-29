#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    return (a%b)?gcd(b,a%b):b;
}

void Divbygcd(ll& a,ll& b)
{
    ll g=gcd(a,b);
    ///cout<<g<<endl;
    a/=g;
    b/=g;
}

ll nCk(ll n,ll k)
{
    ll numerator=1,denominator=1,tomul,todiv,i;
    if (k>n/2)
        k=n-k;
    for (i=k;i;i--)
    {
        tomul=n-k+i;
        todiv=i;
        Divbygcd(tomul,todiv);
        Divbygcd(numerator,todiv);
        Divbygcd(tomul,denominator);
        numerator*=tomul;
        denominator*=todiv;
        ///cout<<numerator<<' '<<denominator<<endl;
    }
    return numerator/denominator;
}

int main()
{
    ll N,K;
    while(cin>>N>>K)
    {
        cout<<nCk(N,K)<<endl;
    }
    return 0;
}
