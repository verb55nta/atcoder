#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
template <class Abel>
struct BIT
{
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0; // to be set

    /* [1, n] */
    BIT(ll n) { init(n); }
    void init(ll n)
    {
        for (ll iter = 0; iter < 2; ++iter)
            dat[iter].assign(n + 1, UNITY_SUM);
    }

    /* a, b are 1-indexed, [a, b) */
    inline void sub_add(ll p, ll a, Abel x)
    {
        for (ll i = a; i < (ll)dat[p].size(); i += i & -i)
            dat[p][i] = dat[p][i] + x;
    }
    inline void add(ll a, ll b, Abel x)
    {
        sub_add(0, a, x * -(a - 1));
        sub_add(1, a, x);
        sub_add(0, b, x * (b - 1));
        sub_add(1, b, x * (-1));
    }

    /* a is 1-indexed, [a, b) */
    inline Abel sub_sum(ll p, ll a)
    {
        Abel res = UNITY_SUM;
        for (ll i = a; i > 0; i -= i & -i)
            res = res + dat[p][i];
        return res;
    }
    inline Abel sum(ll a, ll b)
    {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }

    /* debug */
    void prll()
    {
        for (ll i = 1; i < (ll)dat[0].size(); ++i)
            cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};
