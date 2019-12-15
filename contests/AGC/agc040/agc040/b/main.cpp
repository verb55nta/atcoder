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

bool f(const pair<ll,ll> p1,const pair<ll,ll> p2){

  if(p1.first < p2.first) return true;
  else if(p1.first > p2.first) return false;
  else{
    return p1.second > p2.second;
  }
  
}

int main(void){

  ll n;
  cin>>n;
  vector<pair<ll,ll>> vec(n);
  vector<pair<ll,ll>> minmax[2];
  minmax[0].resize(n);
  minmax[1].resize(n);
  ll diff_max=0;
  priority_queue<ll> l;
  priority_queue<ll,vector<ll>,greater<ll>> r;
  rep(i,n){
    cin>>vec[i].first>>vec[i].second;
    l.push( vec[i].first );
    r.push( vec[i].second );
    //diff_max=max(diff_max, vec[i].second-vec[i].first+1 );
  }
  sort(begin(vec),end(vec),f);

  rep(i,n){
    if(i==0){
      minmax[0][i]=vec[i];      
    }
    else{
      minmax[0][i].first=max(minmax[0][i-1].first,vec[i].first);
      minmax[0][i].second=min(minmax[0][i-1].second,vec[i].second);
    }
  }
  rep_r(i,n){
    if(i==n-1){
      minmax[1][i]=vec[i];      
    }
    else{
      minmax[1][i].first=max(minmax[1][i+1].first,vec[i].first);
      minmax[1][i].second=min(minmax[1][i+1].second,vec[i].second);
    }
  }
  /*
  for(auto p:vec) cout << p.first << "," << p.second << endl;
  cerr << endl;
  for(auto p:minmax[0]) cout << p.first << "," << p.second << endl;
  cerr << endl;
  for(auto p:minmax[1]) cout << p.first << "," << p.second << endl;
  //*/
  ll ans=0;
  for(ll i=0;i<n-1;i++){
    ans = max(ans, max(minmax[0][i].second-minmax[0][i].first+1 , 0LL ) + max(minmax[1][i+1].second-minmax[1][i+1].first+1 , 0LL ) );
  }
  for(ll i=0;i<n;i++){
    ll lM,rm;
    if( vec[i].first==l.top() ){
      l.pop();
      lM=vec[i].first;
      l.push(lM);
    }
    else lM=l.top();
    if( vec[i].second==r.top() ){
      r.pop();    
      rm=vec[i].first;;
      l.push(rm);
    }
    else rm=r.top();

    //cout << "vec:" << vec[i].first << "," << vec[i].second << endl;
    //cout << "lr;" << lM << "," << rm << endl;
    
    ans = max(ans, max( vec[i].second-vec[i].first+1 , 0LL ) + max( rm-lM+1 , 0LL ) );
  }

  cout << ans << endl;
  //cout << max(ans,diff_max) << endl;
  /*
  sort(begin(vec),end(vec),f);

  minmax[0].clear();
  minmax[0].resize(n);
  minmax[1].clear();
  minmax[1].resize(n);
  

  rep(i,n){
    if(i==0){
      minmax[0][i]=vec[i];      
    }
    else{
      minmax[0][i].first=max(minmax[0][i-1].first,vec[i].first);
      minmax[0][i].second=min(minmax[0][i-1].second,vec[i].second);
    }
  }
  rep_r(i,n){
    if(i==n-1){
      minmax[1][i]=vec[i];      
    }
    else{
      minmax[1][i].first=max(minmax[1][i+1].first,vec[i].first);
      minmax[1][i].second=min(minmax[1][i+1].second,vec[i].second);
    }
  }
  //ll ans=0;
  for(ll i=0;i<n-1;i++){
    ans = max(ans, max(minmax[0][i].second-minmax[0][i].first+1 , 0LL ) + max(minmax[1][i+1].second-minmax[1][i+1].first+1 , 0LL ) );
    //cerr << ans << endl;
  }
  cout << ans << endl;
  */

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