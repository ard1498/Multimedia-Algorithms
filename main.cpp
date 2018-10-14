#include<bits/stdc++.h>
#include<dos.h>
#include<cstdio>

using namespace std;

int main(){
	char ch = 'y';
	cout<<"\nenter esc to x";
	while(ch != 'x'){
		cin>>ch;
		sound(10*ch);
		delay(65);
		nosound();
	}
	return 0;
}
