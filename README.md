# DataMake-for-Luogu
适用于洛谷题目数据包制作

# 为什么开发？

在洛谷的讨论区中，总是有很多新晋出题人在询问如何制作数据包。

他们也许没有看懂洛谷在题目数据点配置的所有要求，导致上传数据包因为不符合洛谷要求而被退回。

而这正是这个项目开发的目的所在。

# 如何使用？

data.h使用C++编写。所以，在此之前，您应该先配置好C/C++环境与编辑器，然后再开始阅读。

## 一、安装

（1）手动下载

1.下载data.h头文件，将其放在电脑环境变量对应的MingW的include中，使之能被编译器识别（具体方法请自行bdfs）；

2.引用这个头文件，如果编译通过，说明安装正确。
```
#include "data.h"
```

（2）自动下载

1.下载install.exe程序，点开运行；

2.输入自己编辑器对应的MingW\bin的路径，如：

```
C:\Users\stu-36\Desktop\DataMake-for-Luogu-main\MinGW32\bin
```

需要注意的是由于系统权限，install.exe暂时无法将data.h安装在windows的program files等系统文件夹里面。

## 二、编写

该项目所用结构体名字为```DMake```.

首先给出该结构体的定义：

```
const int maxn = 1e3 + 10;
struct DMake{
	struct Import{
		string INSOURCE,OUTSOURCE;
	}source[maxn];
   string NAME;
	int count;
	int timelim[maxn],memorylim[maxn],score[maxn],subtaskId[maxn],isPretest[maxn];
};
```

#### 参数介绍
1.```string NAME;```

该参数为该数据包文件夹名称，设置请用$C++String$类，例如：
```package.NAME = ("package");```

2.```int count;```

该参数定义为数据包内数据点个数。

3.```int timelim[maxn];```

该参数描述的是每一个数据点的时间限制。方括号中请填写对应的数据点编号。

4.```int memorylim[maxn];```

该参数描述的是每一个数据点的空间限制。方括号中请填写对应的数据点编号。

5.```int score[maxn];```

该参数描述的是每一个数据点的分数。方括号中请填写对应的数据点编号。

6.```int subtaskId[maxn];```

该参数描述的是每一个数据点的捆绑测试任务编号。方括号中请填写对应的数据点编号。

7.```int isPretest[maxn];```

该参数描述的是该数据点是否是$CF$赛制中的```Pretest```
测试点。方括号中请填写对应的数据点编号。

8.```struct Import;```

```
struct Import{
		string INSOURCE,OUTSOURCE;
	}source[maxn];
```

该参数为导入数据点文件结构体。其中，```INSOURCE```表示为```.in```文件所在路径，
```OUTSOURCE```表示为```.out```文件所在路径。

设置请用C++String类，例如：
```
package.source[1].INSOURCE = ("233.in"),
package.source[1].OUTSOURCE = ("233.out");
```

其中```source```中的数字为数据点编号。

据此给出样例文件，也可以下载附件解压打开```example.cpp```:

```cpp
#include <bits/stdc++.h>
#include "data.h"
int main(){//example
	DMake package;
	package.count = 2;
	package.NAME = ("package");
	package.timelim[1] = 1000,package.memorylim[1] = 25600,package.score[1] = 10,package.subtaskId[1] = 0,package.isPretest[1] = 0,
	package.source[1].INSOURCE = ("233.in"),package.source[1].OUTSOURCE = ("233.out");

	package.timelim[2] = 1000,package.memorylim[2] = 25600,package.score[2] = 10,package.subtaskId[2] = 0,package.isPretest[2] = 0,
	package.source[2].INSOURCE = ("game1.in"),package.source[2].OUTSOURCE = ("game1.out");

	package.genrate(package.NAME.c_str());
	return 0;
}
```
