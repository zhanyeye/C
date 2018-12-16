C++

引用

+ 类型名 & 引用名 = 某变量名
+ 某个变量的引用，等价于这个变量，相当于该变量的一个别名

```c++
int n = 4;
int & r = n;//r引用了n, r的类型是 int &
```



引用作为函数的返回值

```c++
int n = 4;
int & Setvalue(){return n;}
int main()
{
    Setvalue() = 40;
    cout << n;
    return 0;
}//输出：40

```

常引用

+ 定义引用时，前面加const关键字，即为"常引用"

```c++
int n;
const int & r = n;
```

r的类型 ```const int &```

不能通过常引用去修改其引用的内容

```c++
int n = 100;
const int & r = n;
r = 200;//编译错
n = 300;//没问题
```

 ```const T &``` 和``` T &```是不同的类型

+ `T &`类型的引用或`T`类型的变量可以用来初始化`const T &` 类型的引用

+ `const T`类型的常变量和`const T &`类型的引用则不能用来初始化`T &`类型的引用，除非进行强制类型转换

 