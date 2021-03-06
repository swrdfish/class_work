#include <stdio.h>
#include <stdlib.h>

// struct state{
// 	char * name;
// 	int id;
// 	int isStart;
// 	int isFinal;	
// };

int main(int argc, char const *argv[])
{
	int nstates, nchars, ntransitions, iii, jjj;
	char *buff;
	
	printf("%s\n", "Enter the no of states: ");
	scanf("%d", &nstates);
	char *states[nstates];
	char *startState;
	char *finalStates[nstates];

	iii = 0;
	printf("%s\n", "Enter the states separated by space: ");
	while(iii < nstates){
		buff = (char *)calloc(100, 1);
		scanf("%s", buff);
		states[iii++] = buff;
	}

	printf("%s\n", "Enter the no of input alphabets: ");
	scanf("%d", &nchars);
	char chars[nchars];

	iii = 0;
	printf("%s\n", "Enter the input alphabets separated by space: ");
	while(iii < nchars){
		chars[iii] = getchar();
		if (chars[iii] != ' ' && chars[iii] != '\n' && chars[iii] != '\t'){
			iii++;
		}
	}

	ntransitions = nstates*nchars;
	char *transitions[ntransitions];
	iii = 0;
	while(iii < ntransitions){
		printf("Enter transition for [%s]->[%c]: \n", states[iii/nchars], chars[iii%nchars]);
		buff = (char *)calloc(100, 1);
		scanf("%s", buff);
		transitions[iii++] = buff;
	}

	printf("%s\n", "Enter the start state: ");
	buff = (char *)calloc(100, 1);
	scanf("%s", buff);
	startState = buff;

	int nfinal = 0;
	printf("%s\n", "No of final states?");
	scanf("%d", &nfinal);
	printf("%s\n", "Enter the final states separated by space");
	for(iii = 0; iii<nfinal; iii++){
		buff = (char *)calloc(100, 1);
		scanf("%s", buff);
		finalStates[iii] = buff;
	}

	/* print the table */
	jjj = iii = 0;
	printf("st/sym\t");
	while(jjj < nchars){
		printf("%c\t", chars[jjj++]);
	}
	printf("\n");
	while(iii < nstates){
		printf("%s\t", states[iii]);
		jjj = 0;
		while(jjj < nchars){
			printf("%s\t", transitions[nchars*iii + jjj]);
			jjj++;
		}
		printf("\n");
		iii++;
	}
	printf("%s: %s\n","start state", startState);
	printf("%s\n", "final states:");
	for(iii=0; iii<nfinal; iii++){
		printf("%s ", finalStates[iii]);
	}
	puts("");
	return 0;
}