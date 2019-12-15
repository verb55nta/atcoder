#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(void){

  int N;
  cin >> N;

  if(N==3){
    cout << "2 5 63" << endl;
  }
  else if(N==4){
    cout << "2 3 4 9" << endl;
  }
  else if(N>4 && N<8){
    cout << "2 3 4 9 " ;
    for(int i=0;i<N-4;i++){
      cout << 6*(i+1) << " ";
    }
    cout << endl;
  }
  else{
    for(int i=0;i<N/8;i++){
      for(int j=0;j<3;j++){
	cout << 12*(i+1) - 6 - 3 - 1 + j  << " ";
      }
      cout << 12*(i+1) -6<< " ";
      for(int j=0;j<3;j++){
	cout << 12*(i+1) - 3 - 1 + j  << " ";
      }
      cout << 12*(i+1) << " ";      
    }
    int amari=N%8;
    //for(int i=0;i<amari;i++){
    //cout << 12*(N/8) + 6*(i+1) << " ";
    //}
    switch(amari){
    case 0:
      break;
    case 1:
      cout << 12*(N/8) + 6 << " ";
      break;
    case 2:
      cout << 12*(N/8) + 6 << " " << 12*(N/8+1)<< " ";
      break;      
    case 3://to change
      cout << 12*(N/8) + 3 << " ";
      cout << 12*(N/8) + 6 << " ";
      cout << 12*(N/8) + 9 << " ";      
      break;      
    case 4://to change
      cout << 12*(N/8) + 3 << " ";
      cout << 12*(N/8) + 6 << " ";
      cout << 12*(N/8) + 9 << " ";
      cout << 12*(N/8) + 12 << " ";      
      break;      
    case 5://to change
      cout << 12*(N/8) + 2 << " ";
      cout << 12*(N/8) + 3 << " ";
      cout << 12*(N/8) + 4 << " ";      
      cout << 12*(N/8) + 6 << " ";
      cout << 12*(N/8) + 9 << " ";      
      break;      
    case 6:
      for(int j=0;j<3;j++){
	cout << 12*(N/8) +2 + j  << " ";
      }
      for(int j=0;j<3;j++){
	cout << 12*(N/8) +8 + j  << " ";
      }
      break;      
    case 7:
      for(int j=0;j<3;j++){
	cout << 12*(N/8) +2 + j  << " ";
      }
      cout << 12*(N/8) + 6 << " ";
      for(int j=0;j<3;j++){
	cout << 12*(N/8) +8 + j  << " ";
      }
      break;      
    }
    
  }
  
  return 0;
}
