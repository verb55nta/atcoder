#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int k;
  cin>>k;

  if(k<=500){
    cout << k << endl;
    for(int i=0;i<k;i++){
      for(int j=0;j<k;j++){
        cout << i+1 << " ";
      }
      cout << endl;
    }
  }
  else{
    //cout << "1" << endl;
    if(k%2){
      cout << k/2 << endl;
      for(int i=0;i<k/2;i++){
        for(int j=0;j<k/2;j++){
          cout << i+1 << " ";
        }
        cout << endl;
      }
    }
  }

  return 0;
}
