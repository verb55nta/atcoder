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
#define mod 1000000007LL

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

ll func(ll n){

  ll ans=1;
  rep(i,n){
    ans*=4;
    ans%=mod;
  }
  return ans;
}

int main(void){

  ll n;
  cin>>n;

  ll obj[101];
  ll n_obj[101];
  obj[0]=1;
  n_obj[0]=0;
  obj[1]=4;
  n_obj[1]=0;
  obj[2]=16;
  n_obj[2]=0;
  obj[3]=61;
  n_obj[3]=3;
  obj[4]=230;
  n_obj[4]=26;
  

  if(n==3){
    cout << 61 << endl;
    return 0;
  }
  else if(n==4){
    cout << 230 << endl;
    return 0;
  }

  for(ll i=5;i<=100;i++){
    
    n_obj[i]= ( obj[i-3]*3 + obj[i-4]*2 + n_obj[i-1]*4 )%mod ;
    obj[i] = (func(i) - n_obj[i] +mod)%mod;

  }
  //cout << func(5) << endl;
  cout << obj[n] << endl;

  return 0;

}
