# AnimeManager
## 看番管理器

------------

开发完成度50%

|功能|状态|
|---|---|
|登录|已开发|


File directory tree

```cpp
..
.
firstrun    //a sign of firstrun
main.exe    //developing
Login.exe   //if logined, a file called "logtmp" will be created;
push.exe    //push.exe username listname object
pop.exe     //pop.exe username listname object
mklist.exe  //mklist.exe username listname
rmlist.exe  //rmlist.exe username listname
mkuser.exe  //mkuser.exe username label password (password=NULL means no password)
data---NEEDLIST //A list of need
     |-AUTOMAKE //Auto LISTNAMES
     |-NAMELIST //Storage user name
usr---User1---LISTNAMES  //Storage list name
    |       |-List1
    |       |-List2
    |       |-List3
    |       |-_USER
    |       |...
    |...

```

An example of _USER

```cpp
Admin //username
1     //1 means administrator and 0 means normal user
//Here is password.
```

Another example of _USER

```cpp
John //username
0     //1 means administrator and 0 means normal user
John1234//Here is password.
```
