#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  int N,M,X;
  int A[100];
  int cost[100];

  for(int i=0;i<100;i++){
    cost[i]=0;
  }

  cin >> N;
  cin >> M;
  cin >> X;  

  for(int i=0;i<M;i++){
    cin >> A[i];
    cost[A[i]]=1;
  }

  

  int c1=0;
  int c2=0;  

  for(int i=0;i<X;i++){
    c1+=cost[i];
  }

  for(int i=X;i<100;i++){
    c2+=cost[i];
  }  

  cout << min(c1,c2) << endl;
  
  return 0;
}
