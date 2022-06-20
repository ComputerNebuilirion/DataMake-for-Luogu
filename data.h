//Work In Progress
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define N 100005
#define For(i,x,y)for(i=x;i<=(y);i++)
const int maxn = 1e3;
char yml[maxn] = "\\config.yml";
struct DMake{
	struct Import{
		string INSOURCE,OUTSOURCE;
	}source[maxn];
	int count;
	int timelim[maxn],memorylim[maxn],score[maxn],subtaskId[maxn],isPretest[maxn];
	char pack[maxn],num[maxn],pa[maxn];
	string NAME,EXE;
	bool isInit;
	int index;
	int MT[624];  //624 * 32 - 31 = 19937
	bool bo[N];
	queue<int>p,q;
	unsigned long long R;
	int deg[N][2],dep[N],fa[N];
	void msrand(int seed){
		index = 0;
		isInit = 1;
		MT[0] = seed;
		for(int i=1; i<624; i++)
		{
			int t = 1812433253 * (MT[i-1] ^ (MT[i-1] >> 30)) + i;
			MT[i] = t & 0xffffffff;   //取最后的32位
		}
	}
	void gen(){
		for(int i=0; i<624; i++){
			// 2^31 = 0x80000000
			// 2^31-1 = 0x7fffffff
			int y = (MT[i] & 0x80000000) + (MT[(i+1) % 624] & 0x7fffffff);
			MT[i] = MT[(i + 397) % 624] ^ (y >> 1);
			if (y & 1)
				MT[i] ^= 2567483615;
		}
	}
	int mrand(){
		if(!isInit)
			srand((int)time(NULL));
		if(index == 0)
			gen();
		int y = MT[index];
		y = y ^ (y >> 11);
		y = y ^ ((y << 7) & 2636928640);
		y = y ^ ((y << 15) & 4022730752);
		y = y ^ (y >> 18);
		index = (index + 1) % 624;
		return y;
	}
	/*	void execute(int t){
	char dest[maxn] = "",no[maxn];
	itoa(t,no,10);
	strcat(dest,EXE.c_str());
	strcat(dest," < ");
	strcat(dest,NAME.c_str());
	strcat(dest,"\\");
	strcat(dest,no);
	strcat(dest,".in");
	strcat(dest," > ");
	strcat(dest,NAME.c_str());
	strcat(dest,"\\");
	strcat(dest,no);
	strcat(dest,".out");
	//		printf("%s\n",dest);
	system(dest);
	return ;
	}*/
	void import(const char *dest,const char *route){
		char cpy[maxn] = "";
		memset(cpy,0,sizeof(cpy));
		strcat(cpy,"copy ");
		strcat(cpy,route);
		strcat(cpy," ");
		strcat(cpy,dest);
		//		printf("%s",cpy);
		system(cpy);
	}
	void genrate(const char *package){
		
		char command[maxn];
		memset(command,0,sizeof(command));
		memset(pack,0,sizeof(pack));
		
		strcat(pack,NAME.c_str());
		strcat(command,"mkdir ");
		strcat(command,pack);
		system(command);
		strcat(pack,yml);
		
		remove(pack);
		for(int i = 1; i <= count; i++){
			import(NAME.c_str(),source[i].INSOURCE.c_str());
			import(NAME.c_str(),source[i].OUTSOURCE.c_str());
			
		}
		ymlgenrate();
		/*		for(int i = 1; i <= count; i++)
		execute(i);*/
		
	}
	void ymlgenrate(){
		freopen(pack,"w",stdout);
		for(int i = 1; i <= count; i++){
			printf("%s:\n",source[i].INSOURCE.c_str());
			printf("  timeLimit:%d\n",timelim[i]);
			printf("  memoryLimit:%d\n",memorylim[i]);
			printf("  score:%d\n",score[i]);
			if(subtaskId[i])
				printf("  subtaskId:%d\n",subtaskId[i]);
			if(isPretest[i])
				printf("  isPretest:true\n");
		}
	}
};
