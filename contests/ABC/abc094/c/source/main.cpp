#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

int main(void){

  int N;
  cin >> N;

  vector<int> X(N);
  vector<int> X_origin(N);  
  
  for(int i=0;i<N;i++){
    cin >> X[i];
    X_origin[i]=X[i];
  }

  sort(X.begin(),X.end());
  
  for(int i=0;i<N;i++){
    if(X[N/2-1] >= X_origin[i] ){
      cout << X[N/2 ] << endl;
    }
    else{
      cout << X[N/2 -1] << endl;
    }
  }
  
  return 0;
}
