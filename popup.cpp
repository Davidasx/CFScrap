#ifdef _MSC_VER
#include<__msvc_all_public_headers.hpp>
#pragma comment(lib,"winmm.lib")
#else
#include<bits/stdc++.h>
#endif
#include<windows.h>
using namespace std;
HWND handle;
void sound(){
	PlaySound("dingdong.wav",NULL,SND_FILENAME|SND_ASYNC);
}
bool have_sound=true;//set to false if you don't want a ding-dong with a popup
int main(int argc,char** argv){
	string text=argv[1];
	string lable=argv[2];
	if(have_sound) sound();
	MessageBox(handle,text.data(),lable.data(),1);
	return 0;
}

