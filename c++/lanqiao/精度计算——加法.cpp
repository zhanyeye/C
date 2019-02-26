#include <iostream>
#include <cstring>

using namespace std;


void add(char a[], char b[], char ans[])
{
	int len = (strlen(a)>strlen(b)? strlen(a):strlen(b))+2;
	char *c = new char[len];

	int k=0;
	int up=0;	//进位
	int x,y,z;
	for(int i=strlen(a)-1,j=strlen(b)-1; i>=0||j>=0; i--,j--)
	{
		x = i>=0 ? a[i]:'0';
		y = j>=0 ? b[j]:'0';
		z = x-'0'+y-'0'+up;
		if(z>9)	{up=1; z%=10;}
		else	up=0;
		c[k++] = z+'0';
	}
	if(up)	c[k++] = '1';

	int cnt;
	for(cnt=0; cnt<k; cnt++)
		ans[cnt] = c[k-cnt-1];
	ans[cnt] = '\0';
}

void add2(char a[],char b[], char s[]){
	int alen=strlen(a);
	int blen=strlen(b);
	char str1[100];
	char str2[100];
	char ans[100];

	//注意这里是给每个字节初始化为整数0，,而不是字符'0'
	//因为下面计算时字符串中存的值，其实都代表整数
	memset(str1,0,sizeof(str1));	
	memset(str2,0,sizeof(str2));

	for(int i=0; i<alen; i++){
		str1[i]=a[alen-i-1]-'0';	//倒置并存上与0的差值
	}
	for(int i=0; i<blen; i++){	
		str2[i]=b[blen-i-1]-'0';	//倒置并存上与0的差值
	}

	int len = alen>blen ? alen : blen;

	int c=0;	//进位
	for(int i=0; i<len; i++){
		ans[i]=str1[i]+str2[i]+c;
		c=ans[i]/10;
		ans[i] %=10;
	}
	if(c>0){	//如果最高位还有进位
		len++;
		ans[len-1]=c;
	}

	for(int i=0; i<len; i++){	//再倒置，并还原为数字<0-9>
		s[i]=ans[len-1-i]+'0';	
	}
	s[len]='\0';	//加上结束符
}

int main(){
	char a[100];
	char b[100];
	char c[200];
	scanf("%s",a);
	scanf("%s",b);

	add(a,b,c);

	
	printf("%s\n", c);
	return 0;
}