#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll base,ll pwr)
{
    ll ret,y;
    if (pwr==0) return 1;
    if (pwr%2==0)
    {
        y=power(base,pwr/2);
        ret=y*y;
    }
    else
    {
        y=power(base,pwr/2);
        ret=y*y*base;
    }
    return ret;
}
int main ()
{
    printf("%lld",power(3,3));
    return 0;
}
