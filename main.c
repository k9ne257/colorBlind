#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* hexToRGB(char* hex);
int hexToDecimalConverter(char hex);


int main(int argc,char* argv[]){
	printf("please enter enter your HEX color\n");
	char hexcode [20] ;
	scanf("%s", hexcode);
	//printf("%s\n", hexcode);
	printf("%s\n", hexToRGB(hexcode));
	return 0;
}


char* hexToRGB(char* hex){
	//hex format #112233 
	char* rgb = malloc(30);
	strcpy(rgb,"rgb("); 
	for(int i = 0; i < 3; i++){
		
		//uppercase chars nee to be converted to loscase ones
		int paar =(hexToDecimalConverter(hex[i*2+1]) * 16) 
			+ hexToDecimalConverter(hex[i*2+2]);
		char temp[8];
		sprintf(temp , "%d,",paar);
		strcat(rgb,temp);
	}
	
	rgb[strlen(rgb)-1] = ')';
	
	
	//rgb format RGB(120,220,225)
	return rgb;
}


int hexToDecimalConverter(char hex){
	if(hex < 'a'){
		return hex - '0';
	}
	else{
		
		return 10 + (hex - 'a');
	}


}
