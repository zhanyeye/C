#include <iostream>
#include <cstring>

using namespace std;
void mult(char a[], char b[], char ans[])
{
	int res[200][200]={0};
	int alen = strlen(a);
	int blen = strlen(b);
	char result[200];
	int sum=0;

	for(int i=0; i<alen; i++)
	{
		for(int j=0; j<blen; j++)
		{
			res[i][j]=(a[i]-'0')*(b[j]-'0');
		}
	}

	int k=0;    //结果的位数，从个位开始

	//模拟乘法运算
	for(int i=alen-1; i>=0; i--)  //只求了alen位的低位结果，还有blen-1位没计算
	{
		for(int j=blen-1; j>=0; j--)    
			sum += res[i+(blen-1)-j][j];  //向左下方求和

		result[k]=sum%10;
		k++;    //进一位
		sum = sum/10;
	}
	for(int i=(blen-1)-1; i>=0; i--)  //计算blen-1位高位结果
	{
		for(int j=0; j<=i; j++)
			sum += res[i-j][j];  //向右上方求和
		result[k]=sum%10;
		k++;
		sum = sum/10;
	}
	if(sum!=0) //最高位不是0
	{
		result[k]=sum;
		k++;
	}

	for(int i=0; i<k; i++)  //并将内容回复成数字<0-9>
		result[i] +='0';
	for(int i=0; i<k; i++)
		ans[i] = result[k-i-1];
	ans[k]='\0';
    
	while(true)   //去除结果中的前导0
	{
		if(strlen(ans)!=1 && ans[0]=='0')
			strcpy(ans,ans+1);
		else
			break;
	}
}

int main (){
	char a[100];
	char b[100];
	char c[100];
	scanf("%s",a);
	scanf("%s",b);
	mult(a,b,c);
	printf("%s\n", c);
	return 0;
}