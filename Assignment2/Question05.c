#include <stdio.h>

int length(char message[]){
	int i = 0;
	while(message[i] != '\0'){
		i++;
	}
	return i;
}

void reverse(char message[]){
	int i;
	int len = length(message);
	for(i = 0; i < len/2 ; i++){
		char temp = message[i];
		message[i] = message[len - i - 1];
		message[len - i - 1] = temp;
	}
}

void encodeMessage(char message[]){
	reverse(message);
	int len = length(message);
	int i;
	for(i = 0; i < len; i++){
		message[i] = message[i]^18;
	}	
}

void decodeMessage(char message[]){
	int len = length(message);
	int i;
	for(i = 0; i < len; i++){
		message[i] = message[i]^18;
	}
	reverse(message);
}

int main(){
	int i;
	int len;
	int choice;
	char message[100];
	
	printf("Key:\n1. Encode Message.\n2. Decode Message.\n3. Exit.\n");
	printf("Please enter your choice: ");
	scanf("%d", &choice);	
	while (getchar() != '\n'); // clear input buffer
	
	while(choice != 3){ // Exit
		switch(choice){
			case 1: // Encode Message
				printf("Please enter a message to encode: ");
				fgets(message, sizeof(message), stdin);
				len = length(message);
				if (len > 0 && message[len - 1] == '\n') {
    				message[len - 1] = '\0';
				}

				encodeMessage(message);

				printf("\nYour encoded message:\n");
				for(i = 0; i < len; i++){
					printf("%c", message[i]);
				}
				
				break;
			case 2: // Decode Message
				printf("Please enter a message to decode: ");
				fgets(message, sizeof(message), stdin);
				len = length(message);
				if (len > 0 && message[len - 1] == '\n') {
    				message[len - 1] = '\0';
				}

				decodeMessage(message);

				printf("\nYour decoded message:\n");
				for(i = 0; i < len; i++){
					printf("%c", message[i]);
				}
				
				break;
			default: // Wrong Input
				printf("Wrong Input! Please enter again.\n\n");
		}
		printf("\nKey:\n1. Encode Message.\n2. Decode Message.\n3. Exit.\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);
		while (getchar() != '\n'); // clear input buffer

	}
			
	return 0;
}
