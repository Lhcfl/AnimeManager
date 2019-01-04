#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<windows.h>
using namespace std;
string dir;
void getdir(){
	char tmp_dir[200];  
    GetCurrentDirectory(200,tmp_dir);
    dir=tmp_dir;
}
void mkfile(const char* path,string s=""){
	ofstream fout(path);
	fout<<s;
	return;
}
int checkfile(const char* path){
	FILE* fe=fopen(path,"rb");
	int r=(fgetc(fe)!=EOF);
	fclose(fe);
	return r;
}
int checkmyself(){
	getdir();
	ifstream fin;
	fin.open("fisrtrun");
	int s;
	if(!checkfile("mklist.exe"))return 1;
	if(fin>>s){
		//如果非第一次使用
		fin.close();
		return 0;
	}else{
		//如果第一次使用
		fin.close();
		_mkdir((dir+"\\data").c_str());
		_mkdir((dir+"\\usr").c_str());
		//自动生成账户Admin
		_mkdir((dir+"\\usr\\Admin").c_str());
		mkfile((dir+"\\usr\\Admin\\LISTNAMES").c_str());
		system("mklist.exe Admin 正在观看");
		system("mklist.exe Admin 已经看完");
		ofstream fout("firstrun");
		fout<<0;
		fout.close();
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	if(checkmyself()){//自检不通过
		cout<<"自检不通过。请重新安装。\n";
		system("pause");
		return 0;
	};
	//登录

	return 0;
}