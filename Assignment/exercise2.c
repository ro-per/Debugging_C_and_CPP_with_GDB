#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program first encrypts a message with a key, then decrypts the ciphertext 
and checks equality of the original message and the decrypted one.
The program takes 3 arguments: <key> <key_size> <message>
This is an awful "encryption" algorithm, don't use this in real world applications!

Working input
./exercise2 $'\x61\x65\x67\x68\x6c\x66\x67\x61\x73\x68\x6a\x62\x66\x76\x68\x6a\x76\x73\x62\x6a\x6c\x66\x67\x7a\x64\x68\x6b\x6c\x46\x44\x53\x34\x35\x68\x64\x33\x34\x35\x67\x6a\x34\x35\x33\x66\x68\x37\x34\x6c\x6d\x6e\x61\x6b\x62\x76\x6e\x64\x67\x73\x35\x37\x76\x6e\x63\x62\x64\x67\x65\x74\x35\x37\x32\x6b\x76\x6e\x73\x68\x66\x74\x65\x34' 80 Carle_Jan_looked_at_the_cursed_record_in_her_hands_and_felt_Happy._She_walked_over_to_the_window_and_reflected_on_her_Loud_surroundings.

Broken input
./exercise2 $'\x66\x67\x6c\x6b\x6a\x61\x73\x64\x66\x67\x67\x66\x6e\x73\x35\x34\x73\x66\x67\x61\x64\x35\x34\x68\x6d\x00\x64\x66\x67\x73\x35\x36\x61\x6a\x35\x33\x34\x66\x73\x62\x68\x67\x6b\x34\x66\x62\x68\x35\x34\x6a\x35\x6b\x66\x79\x79\x72\x77\x45\x55\x54\x41\x38\x36\x4a\x44\x47\x52\x41\x54\x44\x33\x48\x35\x33\x34\x4a\x4b\x48\x37\x38' 80 Carle_Jan_looked_at_the_cursed_record_in_her_hands_and_felt_Happy._She_walked_over_to_the_window_and_reflected_on_her_Loud_surroundings.

*/


void xor(char* key, int key_length, char* in_text,
         int in_text_length, char* out_text){
    for(int i = 0; i < in_text_length; i++){
        int key_index = i % key_length;
        out_text[i] = (char) (in_text[i] ^ key[key_index]);
    }
}

//xor every message char with the key char with the same index modulo the key length
int encrypt(char** argv, char* ciphertext){
    char* key = argv[1];
    int key_length = atoi(argv[2]);
    char* plaintext = argv[3];
    int plaintext_length = strlen(plaintext);
    
    xor(key, key_length, plaintext, plaintext_length, ciphertext);
    return plaintext_length;
}

void decrypt(char* key, int key_length, char* ciphertext, 
             int ciphertext_length, char* new_plaintext){
    xor(key, key_length, ciphertext, ciphertext_length, new_plaintext);
}


int main(int argc, char** argv){
    if(argc != 4){
        printf("The program should have 3 additional arguments: "
               "the encryption key, the key length and the plaintext.\n");
        return 1;
    }

    //encrypt message
    int plaintext_length = strlen(argv[3]); 
    //because of the algorith used, the cipher text will have the same 
    //length as the original text
    char ciphertext[plaintext_length];
    int ciphertext_length = encrypt(argv, ciphertext);

    //decrypt message
    char* key = argv[1];
    int key_length = strlen(key);
    char new_plaintext[plaintext_length];
    decrypt(key, key_length, ciphertext, plaintext_length, new_plaintext);
    
    
    //check equality
    char* plaintext = argv[3];
    for(int i = 0; i < plaintext_length; i++){
        if(plaintext[i] != new_plaintext[i]){
            printf("New plaintext is different from original plaintext! "
                   "Program contains errors!\n");
            return -1;
        }
    }
    
    printf("New plaintext is the same as the original plaintext.\n");

    return 0;
}
