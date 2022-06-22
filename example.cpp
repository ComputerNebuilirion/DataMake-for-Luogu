//Work In Progress
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
