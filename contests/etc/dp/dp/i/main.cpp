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

ll fb[4]={2,1,1,0};

double next(double p1,double p2,ll ind){
  if(ind==0) return p1*p2;
  else if(ind==1) return (1.0-p1)*p2;
  else if(ind==2) return p1*(1.0-p2);
  //else if(ind==3) return (1.0-p1)*(1.0-p2);
  else return (1.0-p1)*(1.0-p2);

  
}

int main(void){

  ll n;
  cin>>n;
  vector<double> p(n+1);
  vector< vector<double> > q( 3000, vector<double>(3000,0.0) );
  rep1(i,n){
    cin>>p[i];
  }

  q[1][0]=p[1]; // round, num o' front
  q[0][1]=1.0-p[1];
  
  for(ll i=1;i<=n-2;i+=2){

    rep(j,i+1){
      //cout << i-j << "," << j << ":" << endl;
      rep(k,4){
        //cout << i-j + fb[k] << "," << j + fb[3-k] << endl;
        //cout << "q:" << q[i-j][j] << "next:" << next(p[i+1],p[i+2],k) << endl;
        q[i-j + fb[k] ][j + fb[3-k]] += q[i-j][j] * next(p[i+1],p[i+2],k);

      }

    }

  }
  double ans=0.0;
  for(ll i=n; i>n-i ;i--){
    //cout << i << "," << n-i << endl;
    ans+=q[i][n-i];
  }
  
  cout << setprecision(20) << ans << endl;

  return 0;

}
