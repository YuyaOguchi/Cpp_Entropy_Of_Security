//
//
//Yuya Oguchi
//COEN146 Lab5
//5/10/2016
//
// Code found on the cisco website 
//
//
//when running, add -lm for compiling with log function
//
//eg: randomCalculator.c -o calculator -lm
//
//run with ./calculator filename
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]){

// Used the code from Cisco information technology at 
// blogs.cisco.com/security/on_information_entropy

int i;
int c =0;
int k =0;
int fd=0;
unsigned int fa[255] = {0};
unsigned char buf [255];
double prob;
double entropy;
int ALPHABETSIZE =256;

printf("\n\nCalculating entropy\n");
/* read a brick of data */\
fd = open(argv[1],O_RDONLY);
while ((i = read(fd, buf, sizeof (buf))))
{
    if (i == -1)
    {
        fprintf(stderr, "Can't read %s (%s)\n", argv[1], strerror(errno));
        close(fd);
        break;
    }
 
    for (k = 0; k < i; k++)
    {
        /*
            For each brick of data we siphon from the file, record
            the number of instances of each observed value into
            the frequency array.
          */
          fa[buf[k]]++;
          c++;
    }
}
close(fd);
 
printf("read all char correctly\n");
for (k = 0; k < ALPHABETSIZE; k++)
{
    /* ignore empty slots */
    if (fa[k])
    {
       /* convert frequency array entry -> probability distribution */
       prob = (double)fa[k] / (double)c;
       /* the famous Shannon Entropy formula */
       entropy += prob * log2(1/prob);
    }
}

printf("%f\n\n\n",entropy);

 

return 0;
}
