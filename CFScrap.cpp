#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct JsonParser{
	string json;
	void init(string data){
		json=data;
	}
	JsonParser(string data=""){
		init(data);
	}
	bool havelable(int point,string s){
		if(point+s.size()>json.size())
			return false;
		if(json.substr(point,s.size())==s)
			return true;
		return false;
	}
	int getint(int point){
		int cur=0;
		for(int i=point;i<json.size();i++){
			if(!isdigit(json[i])) break;
			cur=(cur*10)+json[i]-'0';
		}
		return cur;
	}
	string getstring(int point){
		string cur="";
		for(int i=point;i<json.size();i++){
			if(json[i]=='\"') break;
			cur=cur+json[i];
		}
		return cur;
	}
	int getintvar(int point,string s){
		for(int i=point;i<json.size();i++)
			if(havelable(i,s))
				return getint(i+s.size()+2);
		return -1;
	}
	string getstringvar(int point,string s){
		for(int i=point;i<json.size();i++)
			if(havelable(i,s))
				return getstring(i+s.size()+3);
		return "-1";
	}
};
int strtoint(string s){
	int res=0;
	for(int i=0;i<s.size();i++) res=(res*10+s[i]-'0');
	return res;
}
string inttostr(int x){
	string res="";
	while(x){
		res+=(char)(x%10+'0');
		x/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
set<string> parsed;
struct CodeforcesSubmissionAPI{
	JsonParser parser;
	string url;
	int scanner;
	int fetch(string user,int start,int count){
		url="https://codeforces.com/api/user.status?handle="+user+"&from="+inttostr(start)+"&count="+inttostr(count);
		cout<<("curl \""+url+"\" -o apitemp"+user+".txt")<<endl;
		int val=system(("curl \""+url+"\" -o apitemp"+user+".txt").data()); 
		ifstream fin(("apitemp"+user+".txt").data());
		string tmp,js="";
		while(getline(fin,tmp)) js+=tmp;
		fin.close();
		parser.json=js;
		scanner=0;
		system(("del apitemp"+user+".txt").data());
		return val;
	}
	int scangetnextintvar(string s){
		int val=parser.getintvar(scanner,s);
		if(val==-1) return -1;
		string sval=inttostr(val);
		for(int i=scanner;i<parser.json.size();i++)
			if(parser.havelable(i,s)){
				scanner=i+s.size()+2+sval.size();
				return val;
			}
		return -1;
	}
	string scangetnextstringvar(string s){
		string val=parser.getstringvar(scanner,s);
		if(val=="-1") return "-1";
		for(int i=scanner;i<parser.json.size();i++)
			if(parser.havelable(i,s)){
				scanner=i+s.size()+4+val.size();
				return val;
			}
		return "-1";
	}
};
set<int> ss;
void scrap(string user){
	CodeforcesSubmissionAPI api;
	int startt;
	while(1){
		startt=time(NULL);
		if(!api.fetch(user,1,10)) break;
		Sleep(1000);
	}
	while(1){
		string index,verdict,testset,name,programmingLanguage;
		int timeConsumedMillis,memoryConsumedBytes;
		int creationTimeSeconds,contestId,id;
		id=api.scangetnextintvar("id");
		if(id==-1) break;
		contestId=api.scangetnextintvar("contestId");
		creationTimeSeconds=api.scangetnextintvar("creationTimeSeconds");
		contestId=api.scangetnextintvar("contestId");
		index=api.scangetnextstringvar("index");
		name=api.scangetnextstringvar("name");
		contestId=api.scangetnextintvar("contestId");
		programmingLanguage=api.scangetnextstringvar("programmingLanguage");
		verdict=api.scangetnextstringvar("verdict");
		testset=api.scangetnextstringvar("testset");
		timeConsumedMillis=api.scangetnextintvar("timeConsumedMillis");
		memoryConsumedBytes=api.scangetnextintvar("memoryConsumedBytes");
		if(verdict=="TESTING") continue;
		if(creationTimeSeconds<startt-180) continue;
		if(ss.count(id)) continue;
		ss.insert(id);
		if(verdict=="OK"&&testset=="PRETESTS") verdict="PRETESTS PASSED";
		if(verdict=="OK") verdict="ACCEPTED";
		for(int i=0;i<verdict.size();i++)
			if(verdict[i]=='_') verdict[i]=' ';
		for(int i=0;i<verdict.size();i++){
			if(i==0) continue;
			if(verdict[i]==' ') continue;
			if(verdict[i-1]==' ') continue;
			verdict[i]-='A';
			verdict[i]+='a';
		}
		string cmd="popup \"";
		cmd=cmd+inttostr(contestId);
		cmd=cmd+index;
		cmd=cmd+"."+name+":";
		cmd=cmd+verdict;
		cmd=cmd+"("+programmingLanguage+"),";
		cmd=cmd+inttostr(timeConsumedMillis)+"MS,";
		cmd=cmd+inttostr(memoryConsumedBytes/1048576)+"MB\" ";
		cmd=cmd+user;
		system(cmd.data()); 
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	while(1){
		scrap("[YOUR_USERNAME]");
		Sleep(2000);
	}
	return 0;
}

