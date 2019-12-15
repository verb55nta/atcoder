#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> hist[N];

  for(int i=0;i<N;i++){
    cin >> A[i];
    hist[i]=0;
  }

  int last_c = 0;
  int last_A = 0;
  hist[0]=1;

  for(int i=0;i<N;i++){
    if( A[i] > last_A ){
      last_A = A[i];

      continue;
    }
    else{
      if(hist[last_c] == 1){
        last_c++;
        hist[last_c] = A[i];
      }
      else{
        hist[last_c] = A[i];
      }

    }
  }

  cout << last_c << endl;
  return 0;
}
