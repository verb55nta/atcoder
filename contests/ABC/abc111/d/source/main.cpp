#include<iostream>
#include<string>
#include<algorithm>


#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int n;
  cin >> n;
  vector<long long int> x(n);
  vector<long long int> y(n);

  vector<long long int> u(n);
  vector<long long int> v(n);

  unsigned int o_e;

  for(int i=0;i<n;i++){
    cin >> x[i];
    cin >> y[i];
    u[i] = x[i]+y[i];
    v[i] = x[i]-y[i];
    //cout << u[i] << " " << v[i] << endl;
    //cout << abs(u[i])%2 << endl;
    if(i==0){
      o_e = abs(u[i])%2;
      //cout << o_e << endl;
    }
    else{
      if(o_e != abs(u[i])%2){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  //cout << o_e << endl;



  if(o_e == 0){
    cout << 33 << endl;
    cout << 1 << " ";
  }
  else{
    cout << 32 << endl;
  }
  for(int j=0;j<32;j++){
      cout << ((long long int)1 << j) << " ";
    }
    cout << endl;

  for(int i=0;i<n;i++){
    long long int r_u = (u[i]-(1-o_e)+(long long int)((long long int)1<<32) - (long long int)1)/(long long int)2;
    long long int r_v = (v[i]-(1-o_e)+(long long int)((long long int)1<<32) - (long long int)1)/(long long int)2;
    long long int uu=0;
    long long int vv=0;
    long long int xx=0;
    long long int yy=0;
    if(o_e == 0){
      cout << 'R';
      uu++;
      vv++;
      xx++;
    }
    for(int j=0;j<32;j++){
      //cout << ((r_u >> j) &1);

      long long int signal=((r_u >> j) &(long long int)1) + (long long int)2*((r_v >> j) &(long long int)1);
      switch(signal){
        case 0:
          cout << 'L';
          uu-=((long long int)1<<j);
          vv-=((long long int)1<<j);
          xx-=((long long int)1<<j);
          break;
        case 1:
          cout << 'U';
          uu+=((long long int)1<<j);
          vv-=((long long int)1<<j);
          yy+=((long long int)1<<j);
          break;
        case 2:
          cout << 'D';
          uu-=((long long int)1<<j);
          vv+=((long long int)1<<j);
          yy-=((long long int)1<<j);
          break;
        case 3:
          cout << 'R';
          uu+=((long long int)1<<j);
          vv+=((long long int)1<<j);
          xx+=((long long int)1<<j);
          break;
        default:
          abort();
          break;
      }
    }
    cout << endl;
    //cout << (uu+vv)/2 << " " << (uu-vv)/2 << endl;
    //cout << xx << " " << yy << endl;
    //cout << endl;
  }
    //cout << endl;



  return 0;
}
