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
  ll min_a=0;
  ll sum_a=0;
  ll min_a_i=-1;
  ll max_a_i=-1;
  ll max_a=0;

  bool non_neg=true;
  bool non_pos=true;

  ll abs_ans=0;

  set<ll> pos_arr;
  set<ll> not_pos_arr;

  rep(i,n){
    cin>>a[i];

    abs_ans+=abs(a[i]);

    if(a[i]>0){
      non_pos=false;
      pos_arr.insert(i);
    }
    else if(a[i]<0){
      non_neg=false;
      not_pos_arr.insert(i);
    }
    else if(a[i]==0){
      not_pos_arr.insert(i);
    }

    if(i==0){
      min_a=a[i];
      min_a_i=i;
      max_a=a[i];
      max_a_i=i;
    }
    //else min_a=min(min_a,a[i]);
    else{
      if(min_a > a[i]){
        min_a=a[i];
        min_a_i=i;
      }
      if(max_a < a[i]){
        max_a=a[i];
        max_a_i=i;
      }
    }
    sum_a+=a[i];
  }
  if(non_neg==true && non_pos==true){
    cout << 0 << endl;
    ll target=min_a;
    rep(i,n-2){
      cout << target << " " << a[i] << endl;
      target-=a[i];
    }
    cout << max_a << " " << target << endl;
    return 0;
  }

  else if(non_neg==true && non_pos==false){
    cout << sum_a - 2LL*min_a << endl;

    //ll ind
    //cout << min_a_i << "," << max_a_i << endl;

    if( min_a_i==max_a_i ){
      ll target=min_a;
      rep(i,n-2){
        cout << target << " " << a[i] << endl;
        target-=a[i];
      }
      cout << max_a << " " << target << endl;
      return 0;
    }

    ll target=min_a;

    rep(i,n){
      if(i==min_a_i || i== max_a_i) continue;
      else{
        cout << target << " " << a[i] << endl;
        target-=a[i];
      }
    }
    cout << max_a << " " << target << endl;

    return 0;
  }

  else if( non_neg==false && non_pos==true ){
    cout << -sum_a + 2LL*max_a << endl;

    if( min_a_i==max_a_i ){
      ll target=min_a;
      rep(i,n-2){
        cout << target << " " << a[i] << endl;
        target-=a[i];
      }
      cout << target << " " << max_a << endl;
      return 0;
    }

    ll target=max_a;

    rep(i,n){
      if(i==min_a_i || i== max_a_i) continue;
      else{
        cout << target << " " << a[i] << endl;
        target-=a[i];
      }
    }
    cout << target << " " << min_a << endl;

    return 0;

  }

  else{
    cout << abs_ans << endl;
    pos_arr.erase(max_a_i);
    ll target=min_a;

    while(pos_arr.size()>0){

      auto i=*begin(pos_arr);
      cout << target << " " << a[i] << endl;
      target-=a[i];
      pos_arr.erase(i);

    }

    cout << max_a << " " << target << endl;
    target=max_a-target;

    for(auto i:not_pos_arr){
      if(i==min_a_i) continue;
      else{
        cout << target << " " << a[i] << endl;
        target-=a[i];
      }
    }

    return 0;

  }
  

  return 0;
}
