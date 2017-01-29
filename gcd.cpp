#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b)
{
    return (a%b)?gcd(b,a%b):b;
}
int main ()
{
    ll x,y,g;
    while(cin>>x>>y)
    {
        g=gcd(x,y);
        cout<<g<<endl;
    }
}
