#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

typedef long long ll;
ll mod=1000000007;
ll gyaku(ll n){
  ll mo=mod-2;
  ll now=n;
  ll ret=1;
  while(mo>0){
    if(mo&1)ret*=now;
    ret%=mod;
    now*=now;
    now%=mod;
    mo/=2;
  }
  return ret;
}
ll nck(ll n,ll k){
  if(2*k>n)k=n-k;
  ll ret=1;
  for(ll i=0;i<k;i++){
    ret*=n-i;
    ret%=mod;
    ret*=gyaku(i+1);
    ret%=mod;
  }
  return ret;
}

int main(void){

  int n,m;
  cin >> n;
  cin >> m;
  /*
  vector<int> p(100001,1);
  p[0]=0;
  p[1]=0;

  for(int i=2;i<100000;i++){
    if(p[i]){
      for(int j=2;i*j<100000;j++){
        p[i*j]=0;
      }
    }
  }

  vector<int> pp(0);

  for(int i=2;i*i<=1000000000;i++){
    if(p[i]){
      //cout << i << " ";
      pp.push_back(i);
    }
  }
  /*
  for(int x:pp){
    cout << x << " ";
  }
  cout << endl;
  */
  /*
  int m_tmp=m;
  vector<int> pf(pp.size(),0);
  for(int i=0;i<pp.size();i++){
    while(m_tmp % pp[i] == 0){
      pf[i]++;
      m_tmp /= pp[i];
    }
  }
  */
  vector<int> pf(0);

  for(int i=2;m>1;i++){
    int sum=0;
    while(m % i == 0){
      sum++;
      m /= i;
    }
    if(sum) pf.push_back(sum);
  }


  long long int ans=1;
  for(int i=0;i<pf.size();i++){
    if(pf[i]){
      //cout << pp[i] << ":" << pf[i] << endl;
      //cout << ncr( pf[i] + n - 1 , n-1 ) << endl;
      ans *= nck( pf[i] + n - 1 , pf[i] );
      ans %= mod;
    }
  }

  cout << ans << endl;

  return 0;
}
