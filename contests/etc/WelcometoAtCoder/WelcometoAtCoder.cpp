#include<iostream>
#include<string>

using namespace std;

int main(void){
	
	int a,b,c;
	string s;

	cin >> a;
	cin >> b;
	cin >> c;
	cin.ignore();
	getline(cin,s);
	cout << a+b+c << " " << s << endl;

	return 0;
	
}
