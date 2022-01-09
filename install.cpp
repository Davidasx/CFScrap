#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int main(){
	cout<<"Welcome to CFScrap install prompt!"<<endl;
	cout<<"Please make sure you have G++ installed. Press any key to start."<<endl;
	getch();
	string a,b,c,s;
	int val;
	a="string codeforces=\"https://codeforces.com\";";
	b="vector<string> handles={";
	c="bool have_sound=true;";
	system("cls");
	cout<<"Are you using Chinese mainland network?[Y/N]"<<endl;
	val=getch();
	if(val=='y'||val=='Y') a="string codeforces=\"https://codeforc.es\";";
	system("cls");
	cout<<"How many Codeforces handles are you watching?"<<endl;
	cin>>val;
	cout<<"Input "<<val<<" Codeforces IDs, one per line:"<<endl;
	getline(cin,s);
	for(int i=1;i<=val;i++){
		getline(cin,s);
		b+="\"";
		b+=s;
		b+="\"";
		if(i!=val) b+=",";
	}
	b+="};";
	cout<<b<<endl;
	system("cls");
	cout<<"Would you like to hear a sound before each notification?[Y/N]"<<endl;
	val=getch();
	if(val=='n'||val=='N') c="bool have_sound=false;";
	ifstream fin1("cfscrap.cpp");
	ofstream fout1("cfscrap_new.cpp");
	for(int i=1;;i++){
		if(!getline(fin1,s)) break;
		if(i==4) fout1<<a<<endl;
		else if(i==5) fout1<<b<<endl;
		else fout1<<s<<endl;
	}
	fout1.close();
	fin1.close();
	ifstream fin2("popup.cpp");
	ofstream fout2("popup_new.cpp");
	for(int i=1;;i++){
		if(!getline(fin2,s)) break;
		if(i==4) fout2<<c<<endl;
		else fout2<<s<<endl;
	}
	fout2.close();
	fin2.close();
	cout<<"Compiling CFScrap......"<<endl;
	int tot=0;
	tot+=system("g++ popup_new.cpp -o popup -lwinmm");
	tot+=system("g++ cfscrap_new.cpp -o cfscrap");
	if(tot){
		cout<<"Compile failed. It's PROBABLY your compiler's problem."<<endl;
		cout<<"It's suggested that you install latest TDM-GCC compiler at "<<endl;
		system("pause");
		return 1;
	}
	cout<<"Successfully installed!"<<endl;
	system("pause");
	return 0;
}

