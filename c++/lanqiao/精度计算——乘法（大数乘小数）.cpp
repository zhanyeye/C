#include <iostream>
#include <cstring>
using namespace std;

void mult(char c[],char t[],int m)
{
    int len,add=0;
    char s[100];
    len=strlen(c);
    for(int i=0; i<len; i++)
        s[len-i-1]=c[i]-'0';   //将字符串倒置，并如与0的差值
    for(int i=0; i<len; i++)
    {
        s[i]=s[i]*m+add;
        add=s[i]/10;
        s[i]=s[i]%10;
    }
    if(add>0)
    {
        len++;
        s[len-1]=add;
    }
    for(int i=0; i<len; i++)
        t[i]=s[len-i-1]+'0';
    t[len]='\0';
}

int main()
{
    char str[100];
    char ans[100000];
    int m;
    scanf("%s",str);
    scanf("%d",&m);
    mult(str,ans,m);
    for(int i=0; i<(int)strlen(ans); i++)
        printf("%c",ans[i]);

    
    return 0;
}

