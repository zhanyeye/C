#include <iostream>
#include <cstring>

using namespace std;


void sub(char a[], char b[], char t[])
{
	int alen = strlen(a);
	int blen = strlen(b);
	t[alen] = '\0';
	int i,j;
	for(i=alen-1,j=blen-1; j>=0; i--,j--)
	{//计算低blen位相减的结果，并存入t[]
		if(a[i]-b[j]>=0)
			t[i] = a[i]-b[j]+'0';
		else
		{//被减数的该位不够时，向前一位借位
			t[i] = 10+a[i]-b[j]+'0';
			a[i-1]--;
		}
	}
	while(a[i]<'0')   //注意这里是字符'0'
	{//向前扫描，若位数小于0，向前一位借位，并存入t[]，位数大于0时停止扫描
	    a[i] += 10;
	    t[i] = a[i];
	    a[--i]--;
	}
	while(i>=0)
	{//将剩余的高高位存入t[]
		t[i] = a[i];
		i--;
	}

	//去除前导0
	int cnt=0;
	while(true)
	{
		if(t[cnt]=='0'&&cnt!=alen-1)
			cnt++;
		else
			break;
	}
	strcpy(t,t+cnt);
}

int main(){
	char a[100];
	char b[100];
	char c[200];
	scanf("%s",a);
	scanf("%s",b);

	sub(a,b,c);

	
	printf("%s\n", c);
	return 0;
}