#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>

using namespace std;

int main(void){

  int n;
  int v[100000];
  vector<int> a(100001);
  vector<int> b(100001);

  for(int i=0;i<100001;i++){
    a[i]=0;
    b[i]=0;
  }

  cin >> n;
  for(int i=0;i<n;i++){
    cin >>v[i];
  }

  //cout << n << endl;
  for(int i=0;i<n;i++){
    //cout << v[i] << " ";
  }
  //cout << endl;

  for(int i=0;i<n;i+=2){
    a[v[i]]++;
  }
  for(int i=1;i<n;i+=2){
    b[v[i]]++;
  }
  int a_num,b_num;
  if(n%2==0){
    a_num=n/2;
    b_num=n/2;
  }
  else{
    a_num=n/2+1;
    b_num=n/2;
  }
  //cout << a_num << endl;
  //cout << b_num << endl;

  int max_a = *max_element(a.begin(),a.end());
  int max_b = *max_element(b.begin(),b.end());

  //cout << max_a << endl;
  //cout << max_b << endl;


  int max_a_index = distance(a.begin(),max_element(a.begin(),a.end()));
  int max_b_index = distance(b.begin(),max_element(b.begin(),b.end()));


  //cout << max_a_index << endl;
  //cout << max_b_index << endl;
  int max_a_2nd;
  int max_b_2nd;
  int max_a_2nd_i;
  int max_b_2nd_i;

  if(max_a_index==max_b_index){
    //cout << "same number!" << endl;
    a[max_a_index]=0;
    b[max_b_index]=0;
    max_a_2nd = *max_element(a.begin(),a.end());
    max_b_2nd = *max_element(b.begin(),b.end());
    max_a_2nd_i = distance(a.begin(),max_element(a.begin(),a.end()));
    max_b_2nd_i = distance(b.begin(),max_element(b.begin(),b.end()));

    if(max_a_2nd > max_b_2nd){
      max_a=max_a_2nd;
    }
    else{
      max_b=max_b_2nd;
    }

    //cout << max_a << endl;
    //cout << max_b << endl;
  }
  //cout << a_num << endl;
  //cout << b_num << endl;
  cout << (a_num - max_a)+(b_num - max_b) << endl;



  return 0;
}
