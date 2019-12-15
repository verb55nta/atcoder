#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <cstdint>
#include <bits/stdc++.h>
#include <queue>
#include <set>

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

  ll n, q;
  cin >> n >> q;
  vector<ll> s(n);
  vector<ll> t(n);
  vector<ll> x(n);
  rep(i, n) cin >> s[i] >> t[i] >> x[i];
  vector<ll> d(q);
  rep(i, q) cin >> d[i];

  vector<ll> ans(q);

  using pa = pair<ll, ll>;
  priority_queue<pa, vector<pa>, greater<pa>> pq;

  for (ll i = 0; i < n; i++)
  {
    pq.push(make_pair(t[i] - x[i], -n - (i + 1)));
    pq.push(make_pair(s[i] - x[i], -(i + 1)));
  }
  for (ll i = 0; i < q; i++)
  {
    pq.push(make_pair(d[i], i));
  }

  set<ll> se;

  while (!pq.empty())
  {
    auto p = pq.top();
    pq.pop();
    //cout << p.first << "," << p.second << endl;

    if (p.second < -n)
    {
      ll idx = -(p.second + n + 1);
      se.erase(x[idx]);
    }
    else if (p.second < 0)
    {
      ll idx = -(p.second + 1);
      se.insert(x[idx]);
    }
    else
    {
      if (se.empty())
        ans[p.second] = -1;
      else
        ans[p.second] = *begin(se);
    }
  }

  for (auto x : ans)
    cout << x << endl;

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