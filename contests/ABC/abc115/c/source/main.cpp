#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int N,K;
  cin >> N;
  cin >> K;

  vector<int> h(N);

  for(int i=0;i<N;i++){
    cin >> h[i];
    //cout << h[i] << endl;
  }


  sort(h.begin(),h.end());

  for(int i=0;i<N;i++){
    //cout << h[i] << endl;
  }

  int val=(1 << 30);
  for(int i=K;i<N+1;i++){
    //cout << h[i] << endl;
    if(val > (h[i-1] - h[i-K]) ){
      val = (h[i-1] - h[i-K]);
    }
  }

  cout << val << endl;

  return 0;
}
