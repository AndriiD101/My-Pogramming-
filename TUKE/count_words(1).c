#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
FILE *x = fopen(argv[1], "r");
char fir = 0;
char sec[] = "ananas";
char thir[] = "ANANAS";
char four[2] = {'0', '0'};
int where = 0;
int f =0;
int a =0;
if (x == NULL)
{
printf("nespravne");

}
else{

do{
if(fir == sec[where] || fir == thir[where]) {
where++;
}
else
{
where = 0 + f;
}

if (where >a+ 5)
{
four[0]++;
if('9'< four[0]) {
four[1]++;
four[0] = '0';
}
where = f;
}

}
while((fir = fgetc(x)) !=EOF);
fclose(x);

x = fopen(argv[1], "w");
if('0'<four[1]) fputc(four[1], x);
fputc(four[0], x);
fclose(x);
}
return 0;
}
