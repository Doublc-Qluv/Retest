[TOC]
C++基础入门
-----
```
来自黑马程序员
```


# 1.初识
## 1.1 hello

```c++
#include <iostream>

using namespace std;

int main(){
    cout << "Hellow World" << endl;
    return 0;
}

```

## 1.2 note

编译器会忽略注释的内容

- 单行注释：

// `描述信息`

- 多行注释：

/* `描述信息` */

## 1.3 变量

`数据类型 变量名 = 初始值`

```c++

#include <iostream>

using namespace std;

int main(){
    int a = 10;
    cout << "a = " << a << endl;
    return 0;
}

```

## 1.4 常量 

记录不可更改的数据

方法

- #define：`#define 常量名 常量值`
- const：`const 数据类型 常量名 = 常量值`

```c++
#include <iostream>

using namespace std;

#define day 7

int main(){
    //
    cout << "a week has " << day << "days" << endl;

    //const 修饰的变量
    const int month = 12;
    cout << "a year has " << month << "months" << endl;
}
```

## 1.5 关键字

不能把数据名称命名为系统指定的关键字，会导致报错。

## 1.6 标识符命名规则

1. 标识符不可以是关键字
2. 标识符只能由字母、数字、下划线组成
3. 第一个字符不能是数字，可以是字母和下划线


# 2. 数据类型

在创建一个变量或者常量时，必须指定相应的数据类型，否则无法给其分配内存。

## 2.1 整型
整数类型

|数据类型|占用空间|取值范围|
|----|----|----|
|short 短整型|2字节|$-2^{15} ～ 2^{15}-1$|
|int 整型|4字节|$-2^{31} ～ 2^{31}-1$|
|long 长整型|win为4字节，linux32为4字节，linux64为8字节|$-2^{31} ～ 2^{31}-1$|
|long long 长长整型|8字节|$-2^{63} ～ 2^{63}-1$|

## 2.2 sizeof 关键字

[0202sizeof.cpp](./0202sizeof.cpp)
利用sizeof关键字可以统计数据类型所占用的内存大小

`sizeof(数据类型 / 变量)`

```c++

#include <iostream>

using namespace std;

int main(){
    cout << "short size " << sizeof(short) <<endl;
    cout << "int size " << sizeof(int) <<endl;
    cout << "long size " << sizeof(long) <<endl;
    cout << "long long size " << sizeof(long long) <<endl;

    return 0;
}

```

## 2.3 实型（浮点型）

[0203float.cpp](./0203float.cpp)
用于表示小数

- 单精度 float 4字节 7位有效数字
- 双精度 double 8字节 15～16位有效数字

## 2.4 字符型

[0204char.cpp](./0204char.cpp)
用于显示单个字符

```c++
char ch = 'a' ;
```

**要使用单引号，单引号内只有一个字符**

## 2.5 转义字符
用于表示一些不能直接输出的ASCII字符
[0205Escape.cpp](./0205Escape.cpp)
```
\n 换行 
\\ 输出反斜杠
\t 制表符
等
```

## 2.6 字符串型

- c语言风格 `char 变量名[] = "字符串值;"`
- c++语言风格 `string 变量名 = "字符串值`
  - 需要添加头文件 `#include <string>`

[0206string.cpp](./0206string.cpp)


```c++

#include <iostream>
#include <string>//使用string数据类型必须要有的头文件
using namespace std;

int main(){
    //c语言风格
    char str[]= "Hello World";
    cout << "Hello world" << endl;
    cout << str << endl;

    //c++语言风格

    string str2 = "Hello";
    cout << str2 << endl;

    return 0;
}

```

## 2.7 布尔型 bool

布尔型代表真或假的值

- true 为真
- false 为假

[0207bool.cpp](./0207bool.cpp)

```c++
#include <iostream>

using namespace std;

int main(){

    bool flag = true;
    cout << flag << endl;//1
    flag = false;
    cout << flag << endl;//0

    cout << "bool size " << sizeof(bool) << endl;

    return 0;

}
```

## 2.8 数据输入

从键盘获取数据

`cin >> 变量`

[0208in.cpp](./0208in.cpp)


# 3. 运算符

用于执行代码的运算

|运算符类型|作用|
|:----|:----|
|算数运算符|处理四则运算|
|赋值运算符|表达式的值赋值给变量|
|比较运算符|表达式的比较,返回一个真值或假值|
|逻辑运算符|根据表达式的值返回真值或假值|

- 算数,特殊:[0301operate.cpp](./0301operate.cpp)
  - ++i 和 --i :改变自身并改变赋值
  - i++ 和 i-- :改变自身不改变赋值
- 赋值
  - = | += | -= | *= | /= | %=
- 比较
  - == | != | > | < | >= | <= 
  - 返回布尔值
- 逻辑运算
  - !a :非,a真假与实际相反
  - a&&b :与,ab都为真结果为真,否则为假
  - a || b :或,ab有一个为真,结果为真

# 4. 程序流程结构
C++支持最基本的三种程序运行结构:
- 顺序结构:程序按照顺序执行,不发生跳转
- 选择结构:依据条件是否满足,有选择的执行相应功能
- 循环结构:依据条件是否满足,循环多次某段代码

## 4.1 选择结构

### 4.1.1 if
执行满足条件的语句

[0401choose.cpp](./0401choose.cpp)

if语句的三种形式:
- 单行格式if语句
- 多行格式if语句
- 多条件的if语句

判断三个数字的最大值[0401test.cpp](./0401test.cpp)

### 4.1.2 三目运算符

用于简单的判断

`表达式1 ? 表达式2 : 表达式3`

[0402ternaryoperator.cpp](./0402ternaryoperator.cpp)

表达式1为真, 执行表达式2, 并返回表达式2的值.
表达式1为假, 执行表达式3, 并返回表达式3的值.

### 4.1.3 switch
用于执行多条分支语句

[040103switch.cpp](./040103switch..cpp)

```c++
switch (表达式)
{
case 结果1:
    执行语句;
    break;

default:
    执行语句;
    break;
}
```

- switch 语句中的表达式类型只能是整型或者枚举类型
- case 中如果没有break,程序会向下执行
- 与if语句相比,对于多条语句的判断时,switch的结构清晰,执行效率高,缺点是switch不可以判断区间

## 4.2 循环结构
### 4.2.1 while循环
满足循环条件,执行循环
`while(循环条件){循环语句}`

示例[猜数字](./040201while.cpp)

