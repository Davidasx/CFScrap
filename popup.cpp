#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
bool have_sound=true;
HWND handle;
void sound(){
	PlaySound("dingdong.wav",NULL,SND_FILENAME|SND_ASYNC);
}
int main(int argc,char** argv){
	string text=argv[1];
	string lable=argv[2];
	if(have_sound) sound();
	MessageBox(handle,text.data(),lable.data(),1);
	return 0;
}

