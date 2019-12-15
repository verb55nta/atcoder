#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
#include<bits/stdc++.h>
#include<queue>
#include<set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for(int i = n-1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define INF bit(60)
#define pb push_back
#define mod 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;
using uif=uint_fast64_t;
using ll=long long int;

int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mod;a=1ll*a*a%mod;}while(b>>=1);return ans;}
int qp(int a,ll b,int mo){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<ll> inp(3);
vector<ll> l;
ll len;

ll dfs(ll i, ll a, ll b, ll c){

  if(i==len){
    if(a!=0 && b!=0 && c!=0) return abs(a-inp[0])+abs(b-inp[1])+abs(c-inp[2]);
    else return INF;
  }

  ll non_result=dfs(i+1,a,b,c);
  ll add10;
  add10=10;
  if(a==0) add10=0;
  ll a_result=dfs(i+1,a+l[i],b,c)+add10;
  add10=10;
  if(b==0) add10=0;
  ll b_result=dfs(i+1,a,b+l[i],c)+add10;
  add10=10;
  if(c==0) add10=0;
  ll c_result=dfs(i+1,a,b,c+l[i])+add10;

  ll _min_l=min( {non_result,a_result,b_result,c_result} );

  return _min_l;

}

int main(void){

  ll n,a,b,c;

  cin>>n>>a>>b>>c;


  inp[0]=a;
  inp[1]=b;
  inp[2]=c;

  len=n;

  rep(i,n){
    ll x;
    cin>>x;
    l.pb(x);
  }

  ll _min_l=dfs(0,0,0,0);

  cout << _min_l << endl;

  return 0;

}
