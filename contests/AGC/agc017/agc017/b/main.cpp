#include <iostream>
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for (int i = n - 1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define INF bit(60)
#define pb push_back
#define mod 1000000007

template <class T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
}

using namespace std;
using uif = uint_fast64_t;
using ll = long long int;
using tTree = __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

ll qp(ll a, ll b)
{
  ll ans = 1;
  do
  {
    if (b & 1LL)
      ans = 1LL * ans * a % mod;
    a = 1LL * a * a % mod;
  } while (b >>= 1LL);
  return ans;
}
ll qp(ll a, ll b, ll mo)
{
  ll ans = 1;
  do
  {
    if (b & 1LL)
      ans = 1LL * ans * a % mo;
    a = 1LL * a * a % mo;
  } while (b >>= 1LL);
  return ans;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll, ll);
ll mod_add(ll, ll);
ll mod_mul(ll, ll);
ll mod_div(ll, ll);
ll comb(ll, ll);
void make_fact(ll);
void make_invfact(ll);
void fact_init();

ll powLL(ll x, ll y)
{
  ll ans = 1;
  for (ll i = 0; i < y; i++)
    ans *= x;
  return ans;
}

int main(void)
{
  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  for (ll i = 2; i <= n - 1; i++)
  {
    ll diff = a - b;
    ll lmax = (i - 1LL) * d;
    ll lmin = (i - 1LL) * c;
    ll rmax = (n - i) * -c;
    ll rmin = (n - i) * -d;

    ll ldiffMax = diff - lmin;
    ll ldiffMin = diff - lmax;

    if (ldiffMax >= rmin && ldiffMax <= rmax)
    {
      cout << "YES" << endl;
      return 0;
    }
    if (rmax >= ldiffMin && rmax <= ldiffMax)
    {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}

ll mod_pow(ll x, ll r)
{
  if (r == 0)
    return 1;
  else if (r == 1)
    return x % mod;
  else if (r % 2 == 0)
  {
    ll t = mod_pow(x, r / 2) % mod;
    return mod_mul(t, t);
  }
  else
  {
    ll t = mod_pow(x, r / 2) % mod;
    ll k = mod_mul(t, t);
    return (k % mod) * (x % mod);
  }
}
ll mod_add(ll a, ll b)
{
  return ((a % mod) + (b % mod)) % mod;
}

ll mod_mul(ll a, ll b)
{
  return ((a % mod) * (b % mod)) % mod;
}

ll mod_div(ll a, ll b)
{
  return mod_mul(a, mod_pow(b, mod - 2));
}

void fact_init()
{
  make_fact(FACSIZE - 1);
  make_invfact(FACSIZE);
}

void make_fact(ll n)
{
  fac[0] = 1;
  rep(i, n)
  {
    fac[i + 1] = mod_mul(fac[i], i + 1);
  }
}

void make_invfact(ll n)
{
  invfac[n] = mod_pow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--)
  {
    invfac[i] = mod_mul(invfac[i + 1], i + 1);
  }
}

ll comb(ll n, ll r)
{

  return mod_mul(mod_mul(fac[n], invfac[r]), invfac[n - r]);
}