#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char str1[10];
	int k = 0;
	gets(str1);
	//printf("%s",str1);
	char out[10000];
	for(int i= 0;i < strlen(str1);i++){
		out[k] = str1[i];
		k++;
		int j = i+1,count = 1;
		while(j < strlen(str1) && str1[i] == str1[j]){
			count++;
			j++;
		}
		out[k] = count+'0';
		k++;
		i = j-1;
	}
	/*
	for(int m = 0;m < k;m++){
		printf("%c",out[m]);
	}*/
	printf("%s",out);
}

