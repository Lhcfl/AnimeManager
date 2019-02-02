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
void load(string s=""){
    cout<<s;
    cout<<"\n-------------\n";
}
int checkfile(const char* path){
	FILE* fe=fopen(path,"rb");
	int r=(fgetc(fe)!=EOF);
	fclose(fe);
	return r;
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
            case '\\':
            case '/':
            case '"':
            case ':':
            case '?':
            case '*':
            case '<':
            case '>':
            case '|':
            case 32:
                continue;
            case 13:
                if(i==0)continue;
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
void finish(string username){
    ofstream fout("logtmp");
	fout<<username;
	return;
}
int login(){
    string username,password;
	cout<<"Username:";
	getUsername(username);
    ifstream fin((dir+"\\usr\\"+username+"\\_USER").c_str());
    
    string tmp;
    fin>>tmp;
    if(tmp==""){
        //User has not signed up
        cout<<"You don't seem to be signed up. \n Press any key to sign up, and c to cancel.\n";
        if(getch()=='c'){
            //Cancel
            return -1;
        }else{
            cout<<"Press n to ignore password.";
            if(getch()=='n'){
                system(("mkuser.exe "+username+" 0 NULL").c_str());
                finish(username);
                return 0;
            }else{
                cout<<"Password:";
                string pswd;
                getPassword(pswd);
                cout<<"Press your password again:";
                string pswd2;
                getPassword(pswd2);
                if(pswd2!=pswd){
                    cout<<"Inconsistent passwords!\n";
                    return -1;
                }else{
                    system(("mkuser.exe "+username+" 0 "+pswd).c_str());
                    finish(username);
                    return 0;
                }
            }
        }
    }else{
        //User has signed up
        if(tmp!=username){
            cout<<"Unexpected ERROR!\n";
            return -1;
        }
        fin>>tmp;
        tmp="";
        fin>>tmp;
        fin.close();
        cout<<"Password:";
        string pswd;
        getPassword(pswd);
        if(pswd!=tmp){
            cout<<"Wrong password!\n";
            return -1;
        }else{
            cout<<"Login successfully!\n";
            finish(username);
            return 1;
        }
    }
    return -1;
}
int main(){
    getdir();
START:
    if(checkfile("logtmp"))remove((dir+"\\logtmp").c_str());
    //remove logtmp
    if(checkfile("logtmp")){
        cout<<"ERROR!";
        finish("");
        return 0;
    }
	int r=login();
    if(r==-1)goto START;
	return 0;
}
