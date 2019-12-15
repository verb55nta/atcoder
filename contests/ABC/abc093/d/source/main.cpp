#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

int main(void){

  int q;
  cin>>q;
  vector<long long> a(q);
  vector<long long> b(q);

  for(int i=0;i<q;i++){
    cin >> a[i];
    cin >> b[i];    
  }

  for(int i=0;i<q;i++){
    long long  max;
    long long people_num;
    max=a[i]*b[i];
    //cout << "max:" << max << endl;
    people_num=0;
    long long t_a;
    t_a=std::min(a[i],b[i]);
    long long t_b;
    t_b=std::max(a[i],b[i]);
    //cout << "a:" << a[i] << endl;
    //cout << "b:" << b[i] << endl;    
    
    for(long long j=0;j<sqrt(max-1);j++){
      cout << j << endl;
      long long order1,order2;
      order1=j+1;
      order2=(max-1)/order1;

      //cout << "order1:" << order1 << endl;
      //cout << "order2:" << order2 << endl;

      if(order1 > order2) break;
      
      if((long long)(order1*order2) < max){

	if(order1 != t_a and order2 != t_b){
	  if(order1 == order2){
	    people_num++;
	  }
	  else{
	    people_num+=2;
	  }
	}

	else if( order1 == t_a and order1!=order2){
	  people_num++;
	}
	
      }
      
    }

    cout << people_num << endl;
      
  }  
  
  return 0;
}
