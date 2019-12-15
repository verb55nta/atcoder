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
  vector<int> x(n);
  vector<int> y(n);
  vector<long long int> h(n);
  int d=0;
  for(int i=0;i<n;i++){
    cin >> x[i];
    cin >> y[i];
    cin >> h[i];
    if(h[i] >= 1) d=i;
  }

  //auto itr=lower_bound(h.begin(),h.end(),1);
  //auto d=distance(h.begin(),itr);
  //cout << x[d] << "," << y[d] << "," << h[d] << endl;
  int tx,ty;
  long long int h_max;

  auto match=0;

  for(int cx=0;cx<=100 && match==0;cx++){
    for(int cy=0;cy<=100 && match==0;cy++){
      h_max=h[d] + abs(cx-x[d]) + abs(cy-y[d]);
      h_max=max(h_max,0LL);
      //cout << cx << "," << cy << "," << h_max << endl;
      match=1;
      for(int i=0;i<h.size();i++){
        auto tmp=h_max - abs(cx-x[i]) - abs(cy-y[i]);
        if( h[i] != max(tmp , 0LL) ){
          match=0;
          break;
        }
      }
      if(match == 1){
        tx=cx;
        ty=cy;
      }

    }
  }

  cout << tx << " " << ty << " " << h_max << endl;

  return 0;
}
