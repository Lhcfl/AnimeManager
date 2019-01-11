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
	//check file start
	if(!checkfile("mklist.exe"))return 1;
	//check file end
	if(checkfile("firstrun")){
		//if not first use
		return 0;
	}else{
		//if first use
		_mkdir((dir+"\\usr").c_str());
		//Automatic generation of user Admin
		system("mkuser.exe Admin 1 NULL");
		ofstream fout("firstrun");
		fout<<0;
		fout.close();
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	if(checkmyself()){//Failed in "check myself"
		cout<<"ERROR.\n----------------------\n";
		system("pause");
		return 0;
	};
	//Login

	return 0;
}