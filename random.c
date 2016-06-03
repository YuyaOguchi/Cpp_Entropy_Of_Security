//
//
//Yuya Oguchi 
//COEN146 Lab5
//5/10/2016
//
//
//
//
// how to run: ./random | head -c # > file

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){

	int i =0;
	FILE *fp;
	//create rand char by srand
	srand(time(NULL));
	//write to given file name 
	fp = fopen("random.txt","w");
	while(1){
		char randomletter = rand()%256;
		fprintf(fp,"%c",randomletter);
		printf("%c",randomletter);
		i++;
	}

	fclose(fp);
	return 0;
}
