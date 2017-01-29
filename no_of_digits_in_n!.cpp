#include<bits/stdc++.h>
using namespace std;
double res=0;
double no_of_digits(int x)
{
    if (x==1)
        return 0;
    else
    {
        res=log10(x)+no_of_digits(x-1);
    }
    return res;
}
int main ()
{
    int n;
    while(cin>>n)
    {
        cout<<floor(no_of_digits(n))+1<<endl;
    }
}
