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

  ll n,k;
  cin>>n>>k;

  string s;
  cin>>s;

  char c_past='2';

  vector<ll> num[3];
  ll tmp=0;
  for(char c:s){
    if(c_past != c){
      num[c_past-'0'].pb(tmp);
      tmp=1;
    }
    else{
      tmp++;
    }
    c_past=c;
  }
  num[c_past-'0'].pb(tmp);
  
  ll sum=0;
  

  if( k >= num[0].size() ){
    sum=0;
    for(auto x:num[0]) sum+=x;
    for(auto x:num[1]) sum+=x;
    cout << sum << endl;
    return 0;
  }

  if( num[0].size()==0 ){
    sum=0;
    for(auto x:num[1]) sum+=x;
    cout << sum << endl;
    return 0;
  }

  ll ahead_1=0;
  if(s[0]=='1'){
    sum+=num[1][0];
    ahead_1=1;
  }
  ll tail_1=0;
  if(s[n-1]=='1'){
    tail_1=1;
  }

  vector<pair<ll,ll>> nums;

  if(ahead_1){
    rep(i,num[0].size()) nums.pb(make_pair(num[1][i],num[0][i]));
    if(num[1].size() > num[0].size() ) nums.pb(make_pair(num[1][ num[1].size()-1 ],0));
  }
  else{
    nums.pb( make_pair(0,num[0][0]) );
    rep(i,num[0].size()-1) nums.pb(make_pair(num[1][i],num[0][i+1]));
    if(num[1].size() == num[0].size() ) nums.pb(make_pair(num[1][ num[1].size()-1 ],0));
    
  }

  //for(auto x:nums) cout << x.first << "," << x.second << endl;

  sum=nums[0].first;
  

  rep(i,k){
    sum+=nums[i].second;
    sum+=nums[i+1].first;
  }

  ll ans=sum;

  for(ll i=k;i<nums.size()-1;i++){
    sum-=nums[i-k].second;
    sum-=nums[i-k].first;
    sum+=nums[i].second;
    sum+=nums[i+1].first;
    ans=max(ans,sum);
  }
  tmp=nums.size()-1;
  sum-=nums[tmp-k].second;
  sum-=nums[tmp-k].first;
  sum+=nums[tmp].second;
  ans=max(ans,sum);

  cout << ans << endl;

  return 0;

}
