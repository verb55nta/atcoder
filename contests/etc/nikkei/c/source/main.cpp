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


int main(void){

  ll n;
  cin>>n;
  vector<ll>a(n);
  vector<ll>b(n);
  vector<ll>c(n);

  rep(i,n){
    cin>>a[i];
    cin>>b[i];
    c[i] = a[i]+b[i];
  }

  std::vector<size_t> indices(c.size());
  std::iota(indices.begin(), indices.end(), 0);
  std::sort(indices.begin(), indices.end(), [&c](size_t i1, size_t i2) {
        return c[i1] > c[i2];
    });
  ll a_sum=0;
  ll b_sum=0;
  //for (auto v : c) std::cout << v << " ";
  //for (auto v : indices) std::cout << v << " ";
  rep(i,n){
    if(i%2 == 0){
      a_sum+=a[indices[i]];
    }
    else{
      b_sum+=b[indices[i]];
    }
  }
  cout << a_sum - b_sum << endl;

  return 0;
}
