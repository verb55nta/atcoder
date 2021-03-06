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

ll powLL(ll x, ll y)
{
  ll ans = 1;
  for (ll i = 0; i < y; i++)
    ans *= x;
  return ans;
}

int main(void)
{
  ll n, k;
  cin >> n >> k;
  unordered_map<ll, ll> um[k];
  unordered_map<ll, pair<ll, ll>> um_cnt[k];
  vector<ll> total[k];
  unordered_map<ll, ll> total_cnt[k];
  ll iMax = 0;

  for (ll i = 0; i < k; i++)
  {
    //cout << i << endl;
    for (ll j = 1; j <= sqrt(n); j++)
    {

      if (i == 0)
        um[i][j] = 1;
      else
      {
        /*
        for (ll l = n / iMax - 1; l > j - 1; l--)
        {
          x = mod_add(x, mod_mul(um_cnt[i - 1][l].first, um_cnt[i - 1][l].second));
        }
        */
        um[i][j] = mod_add(total[i - 1][iMax], total_cnt[i - 1][j]);
      }

      iMax = max(iMax, j);
    }
    //cout << iMax << endl;
    total[i].push_back(0);
    for (ll j = 1; j <= sqrt(n); j++)
    {
      ll x = mod_add(total[i].back(), um[i][j]);
      total[i].push_back(x);
    }

    for (ll j = n / iMax - 1; j > 0; j--)
    {
      ll diff = (n / j) - (n / (j + 1));
      if (i == 0)
        um_cnt[i][j] = make_pair(1, diff);
      else
        um_cnt[i][j] = make_pair(total[i - 1][j], diff);
    }
    for (ll j = n / iMax - 1; j > 0; j--)
    {
      if (j == n / iMax - 1)
        total_cnt[i][j] = um_cnt[i][j].first * um_cnt[i][j].second;
      else
        total_cnt[i][j] = total_cnt[i][j + 1] + um_cnt[i][j].first * um_cnt[i][j].second;
      ;
    }
  }

  ll ans = 0;
  ll x = 0;
  for (ll j = n / iMax - 1; j > 0; j--)
  {
    x += mod_mul(um_cnt[k - 1][j].first, um_cnt[k - 1][j].second);
  }
  ans = mod_add(total[k - 1][iMax], x);

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