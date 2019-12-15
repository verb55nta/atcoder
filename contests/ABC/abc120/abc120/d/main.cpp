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

vector<ll> uf(100001);
vector<ll> uf_t(100001,1);

void init_uf(){
  rep(i,100001) uf[i]=i;
}

ll root(ll x){
  if(uf[x] == x) return x;
  return uf[x] = root(uf[x]);
}

void unite(ll x,ll y){
  ll rx=root(x);
  ll ry=root(y);  
  if(rx==ry) return;
  uf_t[ry]+=uf_t[rx];
  uf_t[rx]=0;
  uf[rx]=ry;
}

bool same(ll x,ll y){
  ll rx=root(x);
  ll ry=root(y);  

  return rx==ry;
}

int main(void){

  ll n,m;
  cin>>n>>m;

  vector<ll> a(m);
  vector<ll> b(m);  

  vector<ll> ans(m+1,0);

  vector<ll> teri(n,1);

  ans[m]=n*(n-1)/2;

  rep(i,m){
    cin>>a[i];
    cin>>b[i];
  }

  init_uf();

  for(ll i=m-1;i>=0;i--){
    ll tmp_ans=ans[i+1];
    ll n1,n2;
    if(same(a[i],b[i])){
      n1=0;
      n2=0;
    }
    else{
      n1=uf_t[root(a[i])];
      n2=uf_t[root(b[i])];    
      unite(a[i],b[i]);
    }
    
    tmp_ans-=n1*n2;

  ans[i]=tmp_ans;

  }

  rep1(i,m){
    cout << ans[i] << endl;
  }

  return 0;

}
