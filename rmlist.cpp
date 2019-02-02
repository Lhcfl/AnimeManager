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
	if(argc!=3){cout<<"error!\n";return 0;}
	string dir;
	getdir(dir);
	remove((dir+"\\usr\\"+argv[1]+"\\"+argv[2]).c_str());

    ifstream fin;
    ofstream fout;
	stringstream ss;
    fin.open((dir+"\\usr\\"+argv[1]+"\\LISTNAMES").c_str());
	string s;
    while(fin>>s){
        if(s!=argv[2])ss<<s<<endl;
    }
    fin.close();
    fout.open((dir+"\\usr\\"+argv[1]+"\\LISTNAMES").c_str());   
    while(ss>>s){
        fout<<s<<endl;
    }

	return 0;
}