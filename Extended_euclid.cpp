#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x=0,y=0,d;
void ExtendedEuclid(ll a,ll b)
{
    ///cout<<endl<<"a = "<<a<<" b = "<<b<<endl;
    if (b==0)
    {
        x=1;
        y=0;
        d=a;
        return;
    }
    ExtendedEuclid(b,a%b);
    ///cout<<endl<<"x = "<<x<<" y = "<<y<<endl;
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

int main ()
{
    ExtendedEuclid(5,10);
    cout<<"In Main = ";
    cout<<x<<' '<<y<<endl;
}
