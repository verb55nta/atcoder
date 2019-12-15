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

ll num[10]={0,2,5,5,4,5,6,3,7,6};
vector<ll> sum(10001,-100000);

int main(void){

  ll n,m;
  cin>>n>>m;
  vector<ll> a(m);

  rep(i,m){
    cin>>a[i];
  }

  ll _min=8;

  sort(all(a),greater<int>());

  rep(i,a.size()){

    if( _min > num[a[i]] ) {
      _min=num[a[i]];
    }

  }

  sum[_min]=1;
  sum[0]=0;

  //cout << _min << endl;

  for(ll i=_min+1;i<n+1;i++){

    ll _max=0;
    rep(j,a.size()){
      if(i-num[a[j]]<0) continue;
      _max = max(_max,sum[i - num[a[j]] ]+1);

    }
    //cout << _max << endl;
    sum[i]=_max;

  }
  //cout << sum[n] << endl;
  ll rest=n;
  while(rest>0){
    rep(i,a.size()){
      if( rest-num[a[i]]>=0 && sum[rest - num[a[i]]] + 1 == sum[rest] ){
        rest=rest - num[a[i]];
        //cout << "rest:" << rest << endl;
        //cout << a[i] << endl;
        cout << a[i] ;
        break;
      }
    }
  }
  cout << endl;

  return 0;
}
