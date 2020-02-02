#include <iostream>
#include <vector>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long int;

vector<ll> dp;

void init(ll);
ll root(ll);
void unite(ll, ll);
bool same(ll, ll);

int main(void)
{

  return 0;
}

void init(ll n)
{
  dp.resize(n);
  REP(i, n)
  dp[i] = i;
}
ll root(ll x)
{
  if (dp[x] == x)
    return x;
  else
    return dp[x] = root(dp[x]);
}
void unite(ll x, ll y)
{
  auto rx = root(x);
  auto ry = root(y);
  dp[ry] = dp[rx];
  root(y);
}
bool same(ll x, ll y)
{
  return root(x) == root(y);
}