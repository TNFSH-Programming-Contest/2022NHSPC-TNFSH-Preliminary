#include"testlib.h"
const int mxN = 1e5, V = 5e6;

int main(int argc,char *argv[]){
	registerValidation(argc,argv);

	int n = inf.readInt(1, mxN, "n");
	inf.readEoln();
	int lst = 0;
	for(int i=0;i<2*n;i++){
		if(i)
			inf.readSpace();
		int x = inf.readInt(1, V, "a_i");
	}
	inf.readEoln();
	inf.readEof();
}
