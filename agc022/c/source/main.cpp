#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  int N;
  int a[50];
  int b[50];

  unsigned long long cost[51][51]; //[from][to]

  cin>>N;

  for(int i=0;i<N;i++) cin>>a[i];
  for(int i=0;i<N;i++) cin>>b[i];

  for(int i=0;i<51;i++){
    for(int j=0;j<51;j++){
      cost[i][j]=pow(2,63);
      //cout << cost[i][j] << endl;
    }
  }

  for(int i=0;i<51;i++){
    cost[i][0]=2;    
    cost[i][i]=2;
    for(int j=(i-1)/2;j>0;j--){
      unsigned long long temp_min_cost=pow(2,63);
      for(int k=(i-1)/2;k>j;k--){
	if(temp_min_cost>cost[k][j]+(unsigned long long)pow(2,i-k)) temp_min_cost=cost[k][j]+(unsigned long long)pow(2,i-k);
      }
      cost[i][j]=min(temp_min_cost,(unsigned long long)pow(2,i%j));
    }
  }

  for(int i=0;i<51;i++){
    cout << i << ":";
    for(int j=0;j==0 or j<=i/2;j++){
      cout << cost[i][j] << ",";
    }
    cout << endl;
  }  
  
  return 0;
}
