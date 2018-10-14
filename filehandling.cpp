#include<stdio.h>
#include<stdlib.h>
//#include<bits.stdc++.h>
int main(){
	FILE *fp;
	fp = fopen("testhandle1.txt","w");
	fprintf(fp,"%d %d %d",5,4,3);
	fputs(" weerrrrr",fp);
	
	int n = 0;
	scanf("%d",&n);
	char str3[n];
	int str1,str2;
	int int1;
	
	fclose(fp);
	fp = fopen("testhandle1.txt","r");
	while(n-3 > 0){
		fscanf(fp,"%d %d %d",&str1,&str2,&int1);
		n-=3;
	}
	if(n-1 > 0)
		puts(fgets(str3,n,fp));
	if(n > 0)
		printf("%d %d %d \n",str1,str2,int1);
	
	fclose(fp);
	return 0;
}
