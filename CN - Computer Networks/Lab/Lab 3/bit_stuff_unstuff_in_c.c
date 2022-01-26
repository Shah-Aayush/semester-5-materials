#include <stdio.h>
#include <string.h>

//void byteStuff(char[] message, char[]){
//	
//}


int main() {
	char message[] = "0111111111111010101111110";
	char flag[] = "011111";
	char flagSeq[] = "0111110";
	int count = 0;
	char stuffedMessage[1000] = "";
	int ind = 0;
	for(int i=0;i<strlen(message);i++){
//		printf("before : %s",stuffedMessage);
		strncat(stuffedMessage, &message[i], 1);
//		strcat(stuffedMessage, message[i]);
//		printf("after : %s",stuffedMessage);
		if (message[i]==flag[count]){
			count++;
			printf("count increased: %d | ",count);
		}
		else{
			count = 0;
			printf("count reset | ");
		}
		if(count==6){
			count = 0;
			strcat(stuffedMessage, "0");
			printf("0 appended | ");
		}
		printf("%d : %s\n",i,stuffedMessage);
	}
	
	printf("original  : %s\n",message);
	printf("stuffed   : %s\n",stuffedMessage);
	
	count = 0;
	char unstuffedMessage[1000] = "";
	for(int i=0;i<strlen(stuffedMessage);i++){
		if (stuffedMessage[i]==flagSeq[count]){
			count++;
			printf("count increased: %d | ",count);
		}
		else{
			count = 0;
			printf("count reset | ");
		}
		if(count==7){
			count = 0;
			continue;
			printf("0 skipped | ");
		}
		strncat(unstuffedMessage, &stuffedMessage[i], 1);
		printf("%d : %s\n",i,unstuffedMessage);
	}
	printf("original  : %s\n",message);
	printf("stuffed   : %s\n",stuffedMessage);
	printf("unstuffed : %s\n",unstuffedMessage);
	printf("original  : %s\n",message);
	return 0;
}