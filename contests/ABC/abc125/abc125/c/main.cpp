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



int main(void){

  ll n;
  cin>>n;

  vector<ll> a(n);

  rep(i,n) cin>>a[i];
  ll ans=0;
  //cout << gcd_arr(0,a) << endl;
  vector<ll> l(n+1);
  vector<ll> r(n+1);
  l[0]=0;
  r[n]=0;
  for(ll i=0;i<n;i++){
    if(l[i]==0) l[i+1]=a[i];
    else l[i+1]=gcd(l[i],a[i]);

    if(r[n-i]==0) r[n-1-i]=a[n-1-i];
    else r[n-1-i]=gcd( r[n-i] , a[n-i-1] );
    
  }

  rep(i,n+1){
    //cout << l[i] << "," << r[i] << endl;
  }
  rep(i,n){
    if(l[i]==0){
      ans=max(ans,r[i+1]);
    }
    else if( r[i+1]==0 ){
      ans=max(ans,l[i]);
    }
    else ans=max(ans, (ll)gcd( l[i] , r[i+1] ) );
  }
  cout << ans << endl;
  /*
  ans=r[1];
  for(ll i=2;i<n-1;i++){
    ans=max(ans, (ll)gcd(l[i-2],r[i]) );
  }
  ans=max(ans,l[n-2]);
  
  cout << ans << endl;
  */

  return 0;

}
