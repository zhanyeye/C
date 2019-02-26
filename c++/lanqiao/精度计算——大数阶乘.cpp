#include <iostream>
#include <cmath>

using namespace std;

int factorial(int n)
{
	int a[10000];
    int c,w;
    int m=0; //索引，指向最高位
    a[0]=1;
    for(int i=1; i<=n; i++)
    {//分别乘1~n
        c=0;  //进位
        for(int j=0; j<=m; j++)
        {
            a[j]=a[j]*i+c;
            c=a[j]/10000;    //设置为10000进制
            a[j]=a[j]%10000;
        }
        if(c>0)  //最高位还有进位
        {
            m++;    //最高位+1
            a[m]=c;    //将值赋给最高位
        }
    }
    w=m*4+log10(a[m])+1;
    printf("\n%d",a[m]);
    for(int i=m-1; i>=0; i--)
        printf("%4.4d",a[i]);
    return w;
}

int main()
{
    int n;
    cin>>n;
    int w=factorial(n);
    cout<<endl<<w;
    return 0;
}

