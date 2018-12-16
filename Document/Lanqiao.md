 入门训练 Fibonacci数列  
```

时间限制：1.0s   内存限制：256.0MB
       
问题描述
Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。
当n比较大时，Fn也非常大，现在我们想知道，Fn除以10007的余数是多少。
输入格式
输入包含一个整数n。
输出格式
输出一行，包含一个整数，表示Fn除以10007的余数。 
说明：在本题中，答案是要求Fn除以10007的余数，因此我们只要能算出这个余数即可，而不需要先计算出Fn的准确值，再将计算的结果除以10007取余数，直接计算余数往往比先算出原数再取余简单。
样例输入
10
样例输出
55
样例输入
22
样例输出
7704
数据规模与约定
1 <= n <= 1,000,000。
```

代码：

```c++
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	arr[0] = 1; //f(1)=1
	arr[1] = 1; //f(2)=1
	if(n==1)
		cout<<arr[0];
	else if(n==2)
		cout<<arr[1];
	else
	{
		int i;
		for(i=2; i<n; i++)
		{
			//取余运算规律： (a + b) % p = (a % p + b % p) % p 
			arr[i] = (arr[i-1]+arr[i-2])%10007;
		}
		cout<<arr[i-1];
	}
	
	delete []arr;

	return 0;
}
```

