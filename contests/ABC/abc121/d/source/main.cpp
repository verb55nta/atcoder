#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<cstdint>
//#include<bits/stdc++.h>
#include<queue>
#include<set>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep_r(i, n) for(int i = n-1; i >= 0; i--)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((ll)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

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

  ll a,b;

  cin>>a>>b;

  //vector<ll> keta(40);
  ll ext[2][40];
  vector<ll> ans(40,0);
  
  ll aa=0;

  for( ll i = 0; b >> i > 0 ; i++){
    //cout << a % (1LL << i+2) << ',' << b % (1LL << i+2) << endl;
    ext[0][i]=a % (1LL << i+1);
    ext[1][i]=(b+1) % (1LL << i+1);
    //cout << ext[0][i] << ',' << ext[1][i] << endl;
    if( i==0 ){
      if(a==0){
        ans[i] = b/2 + b%2;
        ans[i] %= 2;
      }
      else{
        ans[i] = b/2 + b%2 - (a-1)/2 - (a-1)%2;
        ans[i] %= 2;
      }
      
    }
    else{
      //cout << max( ext[0][i]-(1LL << i) , 0LL ) << ',' << max( ext[1][i]-(1LL << i) , 0LL ) << endl;
      ans[i] = max( ext[1][i]-(1LL << i) , 0LL ) - max( ext[0][i]-(1LL << i) , 0LL );
      ans[i] %=2;
      ans[i] = abs(ans[i]);
    }
    //cout << ans[i] << endl;
    aa+= ans[i] << (i);
  }
  //cout << endl;

  cout << aa << endl;
    
  return 0;
}
