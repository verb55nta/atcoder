#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

long long count_val( long long x , long long cur ){
  if(cur > x) return 0;
  //cout << cur << endl;
  int p;
  if(cur==0) p=0;
  else p=(int)log10(cur)+1;
  int check[3]={0,0,0};
  long long tmp_cur=cur;
  for(int i=0;i<p;i++){
    if(tmp_cur % 10 == 3) check[0]++;
    else if(tmp_cur % 10 == 5) check[1]++;
    else if(tmp_cur % 10 == 7) check[2]++;
    tmp_cur = tmp_cur/10;
  }
  int t=0;
  if(check[0]*check[1]*check[2]) t=1;
  //cout << p << endl;
  return t+count_val(x,cur+(long long)3*(long long)pow(10,p))+count_val(x,cur+(long long)5*(long long)pow(10,p))+count_val(x,cur+(long long)7*(long long)pow(10,p));

}



int main(void){

  int N;
  cin >> N;

  int cnt=0;

  if(N < 357){
    cout << 0 << endl;
    return 0;
  }
  else{

    cout << count_val(N,0) << endl;

  }

  return 0;
}
