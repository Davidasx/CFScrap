#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
HWND handle;
int main(int argc,char** argv){
	string text=argv[1];
	string lable=argv[2];
	MessageBox(handle,text.data(),lable.data(),1);
	return 0;
}

