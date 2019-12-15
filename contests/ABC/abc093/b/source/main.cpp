#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  int a,b,k;

  cin>>a;
  cin>>b;
  cin>>k;

  //cout << b-a+1<<endl;
  //cout << 2*k<<endl;  

  if(b-a+1 < 2*k){
    for(int i=a;i<b+1;i++){
      cout << i << endl;
    }
  }
    else{
      for(int i=0;i<k;i++){
	cout << a+i << endl;
      }
      for(int i=0;i<k;i++){
	cout << b-(k-i)+1 << endl;
      }       
    }
  
    
    return 0;
}
