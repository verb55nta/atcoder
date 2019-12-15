#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

int comb(int n,int r);

int main(void){

  int n;
  cin >> n;

  vector<int> a(n);

  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  
  sort(a.begin(),a.end());

  for(int i=0;i<n;i++){
    //cout << a[i] << endl;
  }
  //cout << endl;
  
  if(n==2) cout << a[1] << " " << a[0] << endl;
  else{

    int before=a[0];
    for(int i=1;i<n;i++){
      if(a[i] < a[n-1]/2){
	before=a[i];
      }
      else{
	if( abs(a[n-1]/2 - before) < abs(a[n-1]/2 - a[i]) ){
	  cout << a[n-1] << " " << before << endl;
	}
	else{
	  cout << a[n-1] << " " << a[i] << endl;	  
	}
	break;
      }
    }
    
  }
  
  return 0;
}

int comb(int n,int r){

  int value=1;

  
}
