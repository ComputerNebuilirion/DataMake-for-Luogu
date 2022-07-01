//install data.h
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const char name[maxn] = "\\data.h";
void download(){
	printf("#include <bits/stdc++.h>\n");
	printf("#include <windows.h>\n");
	printf("using namespace std;\n");
	printf("#define N 100005\n");
	printf("#define For(i,x,y)for(i=x;i<=(y);i++)\n");
	printf("const int maxn = 1e3;\n");
	printf("char yml[maxn] = \"%c%cconfig.yml\";\n",'\\','\\');
	printf("struct DMake{\n");
	printf("	struct Import{\n");
	printf("		string INSOURCE,OUTSOURCE;\n");
	printf("	}source[maxn];\n");
	printf("	int count;\n");
	printf("	int timelim[maxn],memorylim[maxn],score[maxn],subtaskId[maxn],isPretest[maxn];\n");
	printf("	char pack[maxn],num[maxn],pa[maxn];\n");
	printf("	string NAME,EXE;\n");
	printf("	bool isInit;\n");
	printf("	int index;\n");
	printf("	int MT[624];\n");
	printf("	void msrand(int seed){\n");
	printf("		index = 0;\n");
	printf("		isInit = 1;\n");
	printf("		MT[0] = seed;\n");
	printf("		for(int i=1; i<624; i++){\n");
	printf("			int t = 1812433253 * (MT[i-1] ^ (MT[i-1] >> 30)) + i;\n");
	printf("			MT[i] = t & 0xffffffff;\n");
	printf("		}\n");
	printf("	}\n");
	printf("	void gen(){\n");
	printf("		for(int i=0; i<624; i++){\n");
	printf("			int y = (MT[i] & 0x80000000) + (MT[(i+1) % 624] & 0x7fffffff);\n");
	printf("			MT[i] = MT[(i + 397) % 624] ^ (y >> 1);\n");
	printf("			if (y & 1)\n");
	printf("				MT[i] ^= 2567483615;\n");
	printf("		}\n");
	printf("	}\n");
	printf("	int mrand(){\n");
	printf("		if(!isInit)\n");
	printf("			srand((int)time(NULL));\n");
	printf("		if(index == 0)\n");
	printf("			gen();\n");
	printf("		int y = MT[index];\n");
	printf("		y = y ^ (y >> 11);\n");
	printf("		y = y ^ ((y << 7) & 2636928640);\n");
	printf("		y = y ^ ((y << 15) & 4022730752);\n");
	printf("		y = y ^ (y >> 18);\n");
	printf("		index = (index + 1) % 624;\n");
	printf("		return y;\n");
	printf("	}\n");
	printf("	void import(const char *dest,const char *route){\n");
	printf("		char cpy[maxn] = \"\";\n");
	printf("		memset(cpy,0,sizeof(cpy));\n");
	printf("		strcat(cpy,\"copy \");\n");
	printf("		strcat(cpy,route);\n");
	printf("		strcat(cpy,\" \");\n");
	printf("		strcat(cpy,dest);\n");
	printf("		system(cpy);\n");
	printf("	}\n");
	printf("	void genrate(const char *package){\n");
	printf("		char command[maxn];\n");
	printf("		memset(command,0,sizeof(command));\n");
	printf("		memset(pack,0,sizeof(pack));\n");
	printf("		strcat(pack,NAME.c_str());\n");
	printf("		strcat(command,\"mkdir \");\n");
	printf("		strcat(command,pack);\n");
	printf("		system(command);\n");
	printf("		strcat(pack,yml);\n");
	printf("		remove(pack);\n");
	printf("		for(int i = 1; i <= count; i++){\n");
	printf("			import(NAME.c_str(),source[i].INSOURCE.c_str());\n");
	printf("			import(NAME.c_str(),source[i].OUTSOURCE.c_str());\n");
	printf("		}\n");
	printf("		ymlgenrate();\n");
	printf("	}\n");
	printf("	void ymlgenrate(){\n");
	printf("		freopen(pack,\"w\",stdout);\n");
	printf("		for(int i = 1; i <= count; i++){\n");
	printf("			printf(\"%c%c:\\n\",source[i].INSOURCE.c_str());\n",'%','s');
	printf("			printf(\"  timeLimit:%c%c\\n\",timelim[i]);\n",'%','d');
	printf("			printf(\"  memoryLimit:%c%c\\n\",memorylim[i]);\n",'%','d');
	printf("			printf(\"  score:%c%c\\n\",score[i]);\n",'%','d');
	printf("			if(subtaskId[i])\n");
	printf("				printf(\"  subtaskId:%c%c\\n\",subtaskId[i]);\n",'%','d');
	printf("			if(isPretest[i])\n");
	printf("				printf(\"  isPretest:true\\n\");\n");
	printf("		}\n");
	printf("	}\n");
	printf("};\n");
}
int main(){
	char pathvar[maxn],back[maxn],install_route[maxn] = "";
//	pathvar = getenv("Path");
//	printf("pathvar=%s",pathvar);
	gets(pathvar);
//	scanf("%s",pathvar);
	strcat(install_route,pathvar);
	for(int i = strlen(install_route) - 1; i >= strlen(install_route) - 4; i--){
		if(install_route[i] == '\\')
			for(int j = i; j < strlen(install_route); j++)
				install_route[j] = '\0';
	}
	char command1[maxn] ="";
	strcat(command1,"cd ");
	strcat(install_route,"\\include");
	strcat(command1,install_route);
	printf("%s\n",install_route);
	strcat(install_route,name);
	system(command1);

	printf("%s\n",install_route);
	freopen(install_route,"w",stdout);
	download();
	return 0;
}
