#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<windows.h>
using namespace std;
string dir;
string username;
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
int login(){
	ifstream fin("logtmp");
	fin>>username;
	fin.close();
	remove((dir+"\\logtmp").c_str());
	if(username=="")return 0;
	return 1;
}
void printlistnames(){
	ifstream fin((dir+"\\"+username+"\\LISTNAMES").c_str());
	string s;
	cout<<endl;
	while(fin>>s){
		cout<<s<<endl;
	}
}
void printlist(string name){
	ifstream fin((dir+"\\"+username+"\\"+names).c_str());
	cout<<"\nData in "<<name<<endl;
	string s;
	while(fin>>s){
		cout<<s<<endl;
	}
}

int main(int argc, char const *argv[])
{
	if(checkmyself()){//Failed in "check myself"
		cout<<"ERROR.\n----------------------\n";
		system("pause");
		return 0;
	};
	//Login
	if(checkfile("logtmp"))remove((dir+"\\logtmp").c_str());
    //remove logtmp
    if(checkfile("logtmp")){
        cout<<"ERROR!";
		system("pause");
        return 0;
    }
	system("Login.exe");
	if(!login()){
		cout<<"ERROR!";
		system("pause");
        return 0;
	}

	//Login successfully.
	_sleep(1000);
	system("cls");

	cout<<"Welcome,"<<username;
	cout<<"\n----------------------\n";
	cout<<"Your lists:\n"
	printlistnames();

	string command;
	cout<<">"
	while(cin>>command){
		if(command=="?"){
			cout<<
			"?      Show help\n"
			"pu     Push\n"
			"l      Print Lists\n"
			"ln     Print Listnames\n"
			"po     Pop\n"
			"m      Makelist\n"
			"d      Delete list\n"
			;
		}
	}



	system("pause");
	return 0;
}