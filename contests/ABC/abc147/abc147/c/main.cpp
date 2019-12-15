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

int main(void)
{
  ll n;
  cin >> n;
  vector<ll> a(n);

  vector<vector<ll>> x(n);
  vector<vector<ll>> y(n);

  rep(i, n)
  {
    cin >> a[i];
    //vector<ll> x(a[i]);
    //vector<ll> y(a[i]);
    //x[i].push_back(a[i]);
    rep(j, a[i])
    {
      ll _x, _y;
      cin >> _x >> _y;
      x[i].push_back(_x - 1);
      y[i].push_back(_y);
    }
  }

  vector<ll> deter(n, -1);

  ll ans = 0;
  ll tmp = 0;

  for (ll i = 0; i < 1LL << n; i++)
  {
    bool thr;
    thr = true;
    tmp = 0;
    //cout << "i:" << i << endl;
    for (ll j = 0; j < n; j++)
      deter[j] = -1;
    for (ll j = 0; j < n; j++)
    {
      if (i & (1LL << j))
      {
        for (ll k = 0; k < x[j].size(); k++)
        {
          ll person = x[j][k];
          ll kindness = ((i & (1LL << person)) ? 1LL : 0LL);
          if (kindness != y[j][k])
          {
            //cout << j << endl;
            //cout << k << endl;
            //cout << person << endl;
            //cout << kindness << endl;
            thr = false;
            break;
          }
        }
        if (!thr)
          break;
      }
    }
    if (!thr)
      continue;
    else
    {

      for (ll j = 0; j < n; j++)
      {
        if (i & 1LL << j)
          tmp++;
      }
      ans = max(ans, tmp);
    }
  }

  cout << ans << endl;

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
    return t * t % mod;
  }
  else
  {
    ll t = mod_pow(x, r / 2) % mod;
    ll k = t * t % mod;
    return k * x % mod;
  }
}
ll mod_add(ll a, ll b)
{
  return (a + b) % mod;
}

ll mod_mul(ll a, ll b)
{
  return (a * b) % mod;
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