/*
用递归和递推判断回文字符串
第一个和最后一个字符相等，减去两边剩下依然是回文
减到剩下一个或者刚好没有
*/
#include <iostream>
#include <cstring>
using namespace std;
//递归实现
/*int BackString(char *str,int first,int end,int length){
    if(length==1||length==0){
       cout<<"是回文字符串"<<endl;
       return 1;
    }
    else if(str[first]!=str[end]){
       cout<<"不是回文字符串"<<endl;
       return 0;
    }
    else{
        return BackString(str,first+1,end-1,length-2);
    }
}
int main(){
    char str[]="aaabaaa";
    int  length = strlen(str);
    cout<<BackString(str,0,length-1,length)<<endl;
    return 0;
}*/

//递推实现
bool BackString(char *str){
    int i;
    int length = strlen(str);
    if(length%2==1){
        for(i=0;i<=(length-1)/2;++i){
            if(str[i]==str[length-1-i]){
            }
            else{
                return false;
            }
        }
    }
    else{
        for(i=0;i<=(length-1)/2;++i){
            if(str[i]==str[length-1-i]){
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    char str[]="ccbcc";
    if(BackString(str)==true){
        cout<<"是回文字符串"<<endl;
    }
    else{
        cout<<"不是回文字符串"<<endl;
    }
    return 0;
}
//时间复杂度o(n^2)
//根据字符串的长度/2  再进行前后判断是