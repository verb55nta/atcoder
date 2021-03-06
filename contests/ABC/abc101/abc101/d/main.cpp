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

int qp(int a, ll b)
{
  int ans = 1;
  do
  {
    if (b & 1)
      ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
  } while (b >>= 1);
  return ans;
}
int qp(int a, ll b, int mo)
{
  int ans = 1;
  do
  {
    if (b & 1)
      ans = 1ll * ans * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return ans;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

#define FACSIZE 2002

ll invfac[FACSIZE];
ll fac[FACSIZE];

ll mod_pow(ll, ll);
ll mod_add(ll, ll);
ll mod_mul(ll, ll);
ll mod_div(ll, ll);
void make_fact(ll);
void make_invfact(ll);

ll sunuke(ll x)
{
  ll ans = 0LL;
  while (x > 0LL)
  {
    ans += x % 10LL;
    x /= 10LL;
  }
  return ans;
}

ll powInt(ll x)
{
  ll ans = 1;
  for (ll i = 0; i < x; i++)
  {
    ans *= 10;
  }
  return ans;
}

int main(void)
{
  ll k;
  cin >> k;
  //const ll n = 20000000;
  //vector<vector<double>> arr(16, vector<double>(100));
  //vector<>
  map<ll, double, greater<ll>> m;

  for (ll i = 0; i < 14; i++)
  {
    ll base = (ll)powInt(i) - 1LL;
    //cout << base << endl;
    ///*
    for (ll j = 0LL; j < 1000LL; j++)
    {
      ll x = base + j * powInt(i);
      if (x == 0)
        continue;
      //cout << j * powInt(i) << endl;
      //cout << x << endl;
      m[x] = (double)x / sunuke(x);
    }
    //*/
  }

  vector<ll> cand;
  double Min = LLONG_MAX;
  for (auto p : m)
  {
    //cout << p.first << "," << p.second << endl;
    if (Min >= p.second)
    {
      //cout << i << endl;
      cand.push_back(p.first);
      Min = p.second;
    }
  }

  sort(begin(cand), end(cand));

  for (ll i = 0; i < k; i++)
  {
    auto x = cand[i];
    cout << x << endl;
  }

  /*
  double Min = LLONG_MAX;
  for (ll i = n; i > 0; i--)
  {
    if (Min >= arr[i])
    {
      cout << i << endl;
      Min = arr[i];
    }
  }
  //*/

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