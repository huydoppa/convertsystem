#include<stdio.h>
#define MAX 1000
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdint.h>
#include "asprintf.h"
#include <ctype.h>
typedef unsigned char byte;
byte alphabet[]=
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";
void vigenereCipher(char* plainText, char* k){	
	int i;
	char cipher;
	int cipherValue;
	int len = strlen(k);
	for(i=0; i<strlen(plainText); i++){
		
		if(islower(plainText[i]))
		{
			cipherValue = ( (int)plainText[i]-97 + (int)tolower(k[i % len])-97 ) % 26 +97;
			cipher = (char)cipherValue;
		}
		else 
		{
			cipherValue = ( (int)plainText[i]-65 + (int)toupper(k[i % len])-65 ) % 26 +65;
			cipher = (char)cipherValue;
		}
		
		if(isalpha(plainText[i]))
		{
			printf("%c", cipher);
		}
		else 
		{
			printf("%c", plainText[i]);
		}
	}
}	
byte get_number_b64_from_symbol_0_64(byte b)
{
    if(b>=0x41&&b<=0x5a)
        return b-0x41;
    if(b>=0x61&&b<=0x7a)
        return b-0x47;
    if(b>=0x30&&b<=0x39)
        return b+0x4;
    if(b==0x2b)
        return 0x3e;
    if(b==0x2f)
        return 0x3f;
    if(b==0x3d)
        return 0xff;
    return 0xff;
}
byte *from_b64_bytes(char b64[])
{
    if(strlen(b64)%4!=0)return 0;
    byte *ret;
    asprintf(&ret, "");
    int i;
    for( i=0; i<strlen(b64); i+=4)
    {
        byte b_=get_number_b64_from_symbol_0_64(b64[i])<<2;
        b_+=get_number_b64_from_symbol_0_64(b64[i+1])>>4;
        asprintf(&ret, "%s%c", ret, b_);
        if(get_number_b64_from_symbol_0_64(b64[i+2])==0xff)
            break;
        b_=get_number_b64_from_symbol_0_64(b64[i+1])<<4;
        b_+=get_number_b64_from_symbol_0_64(b64[i+2])>>2;
        asprintf(&ret, "%s%c", ret, b_);
        if(get_number_b64_from_symbol_0_64(b64[i+3])==0xff)
            break;
        b_=get_number_b64_from_symbol_0_64(b64[i+2])<<6;
        b_+=get_number_b64_from_symbol_0_64(b64[i+3]);
        asprintf(&ret, "%s%c", ret, b_);
    }
    return ret;
}
byte *to_base64(byte data[], int size)
{
	byte *b64;
	asprintf (&b64, "");
	int i=0;
	for(;i<size;i++)
	{
		byte b=data[i];
		byte c1=b>>2;
		asprintf(&b64, "%s%c", b64, alphabet[c1]);
		byte c2=b<<6;
		c2=c2>>2;
		i++;
		if(i>=size){
			asprintf(&b64, "%s%c", b64, alphabet[c2]);
			break;
		}
		byte bb=data[i];
		byte c3=bb>>4;
		c2+=c3;
		asprintf(&b64, "%s%c", b64, alphabet[c2]);
		byte c4=bb<<4;
		c4=c4>>2;
		i++;
		if(i>=size){
			asprintf(&b64, "%s%c", b64, alphabet[c4]);
			break;
		}
		byte bbb=data[i];
		byte c5=bbb>>6;
		c4+=c5;
		asprintf(&b64, "%s%c", b64, alphabet[c4]);
		byte c6=bbb<<2;
		c6=c6>>2;
		asprintf(&b64, "%s%c", b64, alphabet[c6]);
	}
	if(strlen(b64)%4!=0)asprintf (&b64, "%s%c", b64, '=');
	if(strlen(b64)%4!=0)asprintf (&b64, "%s%c", b64, '=');	
	return b64;
}
long long int hexToDec(char hex[]){
	 long long int dec=0;
     long long int i = 0;
    while (hex[i])
    {
        switch (hex[i])  
        {
        case '0':
            dec+=0*pow(16,strlen(hex)-1-i); break;
        case '1':
            dec+=1*pow(16,strlen(hex)-1-i); break;
        case '2':
            dec+=2*pow(16,strlen(hex)-1-i); break;
        case '3':
            dec+=3*pow(16,strlen(hex)-1-i); break;
        case '4':
            dec+=4*pow(16,strlen(hex)-1-i); break;
        case '5':
            dec+=5*pow(16,strlen(hex)-1-i); break;
        case '6':
            dec+=6*pow(16,strlen(hex)-1-i); break;
        case '7':
            dec+=7*pow(16,strlen(hex)-1-i); break;
        case '8':
            dec+=8*pow(16,strlen(hex)-1-i); break;
        case '9':
            dec+=9*pow(16,strlen(hex)-1-i); break;
        case 'A':
            dec+=10*pow(16,strlen(hex)-1-i); break;
        case 'B':
            dec+=11*pow(16,strlen(hex)-1-i); break;
        case 'C':
            dec+=12*pow(16,strlen(hex)-1-i); break;
        case 'D':
            dec+=13*pow(16,strlen(hex)-1-i); break;
        case 'E':
            dec+=14*pow(16,strlen(hex)-1-i); break;
        case 'F':
            dec+=15*pow(16,strlen(hex)-1-i); break;
        case 'a':  
            dec+=10*pow(16,strlen(hex)-1-i); break;
        case 'b':
            dec+=11*pow(16,strlen(hex)-1-i); break;
        case 'c':
            dec+=12*pow(16,strlen(hex)-1-i); break;
        case 'd':
            dec+=13*pow(16,strlen(hex)-1-i); break;
        case 'e':
            dec+=14*pow(16,strlen(hex)-1-i); break;
        case 'f':
            dec+=15*pow(16,strlen(hex)-1-i); break;
        default:
            printf("N0t h3x4 d3c1m4 f0m4rt");
        }
        i++;
    }
    return dec;
}
void hexToBinary(char hex[])
{
	int bin[100];
	int n=0;
	int i=0;
	long long int k=hexToDec(hex);
	while(k){
		n=k%2;
		bin[i]=n;
		i++;
		k=k/2;
	}
	int h;
		for(  h=i-1;h>=0;h--){
	 	printf("%d",bin[h]);		
	}
}
void hexToOct(char hex[]){
   	int Oct[100];
	int n=0;
	int i=0;
	long long int k=hexToDec(hex);
	while(k){
		n=k%8;
		Oct[i]=n;
		i++;
		k=k/8;
	}
	int h;
		for(  h=i-1;h>=0;h--){
	 	printf("%d",Oct[h]);
	}
}
int main(int argc, char** argv) {
	char  hex[MAX];
	printf("3nt3r th3 h3x4d3c1m4 f0m4rt: ");
	fflush(stdin);
	gets(hex);
	printf("\n decimal value:%lld",hexToDec(hex));		
	printf("\n binary value: ");
	hexToBinary(hex);
	printf("\n oct value:");
	hexToOct(hex);
	printf("\n");
    byte inpt[500];
    printf("Enter plaintext you want b64 encode:");
	scanf("%[^\n]%*c", inpt);
	printf("encodeb64: \"%s\"\n", to_base64(inpt, strlen(inpt)));
	printf("Decodedb64 : \"%s\"",
	from_b64_bytes(to_base64(inpt, strlen(inpt))));
	printf("\n");
	char k[100];
	char plaintext[1000];
	printf("\n Enter the plaintext you want encrypt:");
	fgets(plaintext, sizeof(plaintext), stdin);
	printf("Enter secret key: ");
	fgets(k, sizeof(k), stdin);	
	printf("The ciphered text with Key  = '%s' is: ", k);
	vigenereCipher(plaintext, k);
}
