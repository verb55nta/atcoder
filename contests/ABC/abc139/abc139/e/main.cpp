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
 
 
#define FACSIZE 2002
 
ll invfac[FACSIZE];
ll fac[FACSIZE];
 
ll mod_pow(ll ,ll );
ll mod_add(ll ,ll );
ll mod_mul(ll ,ll );
ll mod_div(ll ,ll );
void make_fact(ll );
void make_invfact(ll );
 
pair<ll,ll> dec( ll x ){
 
  ll a=x/10000;
  ll b=x%10000;
 
  return  make_pair( a,b );
 
}
 
ll enc( ll x, ll y ){
 
  //return p.first * 10000 + p.second;
  return x*10000 + y;
 
}
 
int main(void){
 
  ll n;
  cin>>n;
 
  vector< vector<ll> > A( n,vector<ll>(n-1) );
 
  using pa=pair<ll,ll>;
 
  unordered_map< ll , set<ll> > um_in;
  unordered_map< ll , set<ll> > um_out;
  queue< ll > no_in;
 
  vector< ll > s_list;
 
  ll ans=1;
 
  unordered_map<ll,ll> play;
 
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n-1;j++){
      cin>>A[i][j];
      ll a,b;
      a=min(i+1, A[i][j] );
      b=max(i+1, A[i][j] );
      if( j==0 ){
        continue;        
      } 
 
      else{
        ll a_be,b_be;
        a_be=min(i+1, A[i][j-1] );
        b_be=max(i+1, A[i][j-1] );
        um_in[ enc(a,b) ].insert( enc(a_be,b_be) );
        um_out[ enc(a_be,b_be) ].insert( enc(a,b) );
      }
    }
  }
  for(ll i=1;i<n;i++){
    for(ll j=i+1;j<=n;j++){
      if( um_in.find( enc( i,j ) ) ==end(um_in)) no_in.push( enc(i,j) );
    }
  }
  while( !no_in.empty() ){
    auto q=no_in.front();
    no_in.pop();
    s_list.push_back(q);
    auto x=dec( q );
    if( play.find(x.first) != end(play) || play.find(x.second) != end(play) ){
      play.clear();
      ans++;
    }
 
    play[x.first]++;
    play[x.second]++;
 
 
    while( !um_out[q].empty() ){
      auto uoq=*begin(um_out[q]);
      um_out[q].erase(uoq);
      um_in[ uoq ].erase(q);
 
      if( um_out[q].size()==0 ) um_out.erase(q);
      if( um_in[uoq].size()==0 ) um_in.erase(uoq);
 
      if( um_in.find( uoq ) == end(um_in) ) no_in.push( uoq );
      
    }
 
  }

  if( s_list.size() < n*(n-1)/2 ) cout << -1 <<endl;
  else{

    cout << ans << endl;
  }
 
  return 0;
 
}
 
ll mod_pow(ll x,ll r){
  if(r==0) return 1;
  else if(r==1) return x%mod;
  else if(r%2==0){
    ll t=mod_pow(x,r/2)%mod;
    return t*t %mod;
  } 
  else{
    ll t=mod_pow(x,r/2)%mod;
    ll k= t*t %mod;
    return k*x%mod;
  } 
}
ll mod_add(ll a,ll b){
  return (a+b)%mod;
}
 
ll mod_mul(ll a,ll b){
  return (a*b)%mod;
}
 
ll mod_div(ll a,ll b){
  return mod_mul(a,mod_pow(b,mod-2));
}
 
void make_fact(ll n){
  fac[0]=1;
  rep(i,n){
    fac[i+1]=mod_mul(fac[i],i+1);
  }  
}
 
void make_invfact(ll n){
  invfac[n]= mod_pow( fac[n] ,mod-2);
  for(int i=n-1;i>=0;i--){
    invfac[i]=mod_mul(invfac[i+1],i+1);
  }
 
}