#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

uint64_t num_all(int n){

  return (uint64_t)(4 * ((uint64_t)1<<n) -3);

}

uint64_t num_pat(int n){

  return (uint64_t)( ((uint64_t)1<<(n+1)) -1 );

}

int main(void){
  int N;
  uint64_t X;
  cin >> N;
  cin >> X;

  uint64_t l=1;
  uint64_t r=num_all(N);
  ////cout<< num_all(31) << endl;;
  //cout<< r << endl;;

  uint64_t cnt=0;

  int layer=N;
  //cout<< X << endl;
  //cout<< layer << endl;
  //cout<< num_pat(1) << endl;

  while(r - l > 0){
    //cout<< layer << endl;
    //cout<< r-l << endl;
    //cout<< r << endl;
    //cout<< l << endl;
    //cout<< X << endl;

    if(X == l){
      break;
    }

    else if(X == r){
      cnt += num_pat(layer);
      break;
    }


    if(layer==1){
      if(X-l < 4){
        cnt+=(X-l);
        break;
      }
      else{
        cnt+=3;
        break;
      }
    }

    if( X < (r+l)/2 ){
      //cout<< "smaller!" << endl;
      r=(r+l)/2 -1;
      l++;
      layer--;
    }
    else if( X > (r+l)/2 ){
      //cout<< "bigger!" << endl;
      l=(r+l)/2 +1;
      r--;
      layer--;
      cnt += num_pat(layer)+1;
    }
    else{
      //cout<< "same!" << endl;
      layer--;
      cnt += num_pat(layer)+1;
      break;
    }

  }


  cout<< cnt << endl;
  return 0;
}
