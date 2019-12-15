#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int di[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

int main(void){

  int h,w;

  cin>>h;
  cin>>w;

  char paper[h][w];

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> paper[i][j];
    }
  }

  int all=1;
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(paper[i][j] != '.'){
	all=0;
	break;
      }
    }
    if(all==0) break;
  }

  if(all==1){
    cout << "Yes" << endl;
    return 0;
  }

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      //cout << paper[i][j] << endl;
      if(paper[i][j] == '#'){

	if(j+1 < w){
	  if(paper[i][j+1] != '.') continue;
	}
	if(i-1 >= 0){
	  if(paper[i-1][j] != '.') continue;
	}
	if(j-1 >= 0){
	  if(paper[i][j-1] != '.') continue;
	}
	if(i+1 < h){
	  if(paper[i+1][j] != '.') continue;
	  else{
	    cout << "No" << endl;
	    return 0;
	  }	  
	}
	else{
	  cout << "No" << endl;
	  return 0;
	}
	
      }
    }
  }

  cout << "Yes" << endl;
  
  return 0;
}

