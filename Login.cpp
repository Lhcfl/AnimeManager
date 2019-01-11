#include<bits/stdc++.h>
#include<conio.h>
#include<direct.h>
#include<windows.h>
using namespace std;
struct USER{
	string name;
	string pswd;
}USER_NOW;
string dir;
map<string,USER> name2user;
bool Logined=false;
void load(string s=""){
    cout<<s;
    cout<<"\n-------------\n";
}
void getPassword(string &s,int MAXLEN=16){
    char p;
    char a[500];
    int i=0;
    while(1){
        p=getch();
        switch(p){
            case 8:
                if(i!=0){
                    --i;
                    printf("\b \b");
                }
                continue;
            case -32:
                getch();
                continue;
            case 32:
                continue;
            case 13:
                a[i]=0;
                s=a;
                putchar('\n');
                return;
            default:
                if(i<MAXLEN && i<499){
                    putchar('*');
                    a[i++]=p;
                }
        }
    }
}
void getUsername(string &s,int MAXLEN=32){
    char p;
    char a[500];
    int i=0;
    while(1){
        p=getch();
        switch(p){
            case 8:
                if(i!=0){
                    --i;
                    printf("\b \b");
                }
                continue;
            case -32:
                getch();
                continue;
            case 32:
                continue;
            case 13:
                a[i]=0;
                s=a;
                putchar('\n');
                return;
            default:
                if(i<MAXLEN && i<499){
                    putchar(p);
                    a[i++]=p;
                }
        }
    }
}
void getdir(){
	char tmp_dir[200];  
    GetCurrentDirectory(200,tmp_dir);
    dir=tmp_dir;
}
int main(){
	string username,password;
	cout<<"Username:";
	getUsername(username);
	return 0;
}
