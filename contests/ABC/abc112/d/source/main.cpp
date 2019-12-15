#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int n,m;
  cin >>n;
  cin >>m;

  vector<int> dd(0);

  for(int i=1;i*i<=m;i++){
    if(m%i == 0){
      dd.push_back(i);
      dd.push_back(m/i);
    }

  }
  sort(dd.begin(),dd.end());

  int d=1;

  for(int x:dd){
    int res = m - n*x;
    if(res < 0){
      //cout << endl;
      break;
    }
    else if(res == 0){
      d=x;
      //break;
    }
    else{
      //cout << x << ":";
      //cout << res << endl;
      if(res % x == 0) d=x;
    }

  }

  cout << d << endl;

  return 0;
}
