#include <bits/stdc++.h>
using namespace std;

void output(int Array[],char mark){
	for(int i = 1; i <= 13; i++){
		if(Array[i] == 0) printf("%c %d\n",mark,i);
	}
}

int main(){
	char mark[2];
	int n,S[14],H[14],C[14],D[14],tmp;
	for(int i = 0; i < 14; i++) S[i] = H[i] = C[i] = D[i] = 0;
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%s %d",mark,&tmp);
		switch(mark[0]){
		case 'S':
			S[tmp] = 1;
			break;
		case 'H':
			H[tmp] = 1;
			break;
		case 'C':
			C[tmp] = 1;
			break;
		case 'D':
			D[tmp] = 1;
			break;
		}
	}
	output(S,'S');
	output(H,'H');
	output(C,'C');
	output(D,'D');
}