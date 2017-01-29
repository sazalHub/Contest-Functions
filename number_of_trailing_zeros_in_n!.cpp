#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int count_fac(int factor, int num)
{
    int count_fac = 0;
    while (num / factor == num / float(factor))
    {
        num = num / factor;
        count_fac ++;
    }
    return count_fac;
}

int num_zeros(int num)
{
    int count_fac_2 = 0;
    int count_fac_5 = 0;
    for (int x=1; x<=num; x++)
    {
        count_fac_5 += count_fac(5, x);
        count_fac_2 += count_fac(2, x);
    }

    return min(count_fac_2, count_fac_5);
}

uint64_t fac(int num)
{
    if (num > 1)
        return num * fac(num - 1);
    return num;
}

int main()
{
    for (int num=1; num<=20; num++)
        cout << "Fac(" << num << ") = "
        << fac(num) << " has " << num_zeros(num)
             << " trailing zeros" << endl;

    vector<int> large_nums = {1000, 1000000, 1000000000};
    for (int large_num: large_nums)
        cout << "Fac(" <<
        large_num << ") has " << num_zeros(large_num)
             << " trailing zeros" << endl;
}
