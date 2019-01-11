#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<windows.h>
using namespace std;
void getdir(string &dir){
	char tmp_dir[200];  
    GetCurrentDirectory(200,tmp_dir);
    dir=tmp_dir;
}
void mkfile(const char* path,string s=""){
	ofstream fout(path);
	fout<<s;
	return;
}
int main(int argc, char const *argv[])
{
	if(argc!=4){cout<<"error!\n";system("pause");return 0;}
	string dir;
	getdir(dir);
	string name=argv[1];
	string lable=argv[2];
	string password=argv[3];
	if(password=="NULL"){
		password="";
	}
	
	_mkdir((dir+"\\usr\\"+name).c_str());
	mkfile((dir+"\\usr\\"+name+"\\LISTNAMES").c_str());
	mkfile((dir+"\\usr\\"+name+"\\_USER").c_str(),name+"\n"+lable+"\n"+password);

	ofstream fout((dir+"\\data\\NAMELIST").c_str(),ios::app);
	fout<<name<<endl;
	fout.close();

	ifstream fin((dir+"\\data\\AUTOMAKE").c_str());
	string stemp;
	while(fin>>stemp){
		system(("mklist.exe "+name+" "+stemp).c_str());
	}
	fin.close();

	return 0;
}