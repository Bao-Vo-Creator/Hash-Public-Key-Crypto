#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

string random_message(int n){
    char alphabet[52] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z',
                      	  'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z'};
 
    string message = "";
    for (int i = 0; i < n; i++){
        message = message + alphabet[rand() % 52];
	}
     
    return message;
}

void print_digest(unsigned char md_value[], unsigned int digest_length){
	for (int i = 0; i < digest_length; i++){
		printf("%02x", md_value[i]);
	}
	printf("\n");
}


int main(int argc, char *argv[]){
	srand(time(NULL));
	int z = 5;
	int y = 1;
	bool looping = true;
	while(looping){
		EVP_MD_CTX *mdctx;
		const EVP_MD *md = EVP_md5();
		string mess1 = random_message(10);
		string mess2 = "Helloworld";
		//char mess1[message1.length() + 1] = message1.c_str();
		//char mess2[] = "Hello Wo rld\n";
		unsigned char md_value_1[EVP_MAX_MD_SIZE];
		unsigned char md_value_2[EVP_MAX_MD_SIZE];
		unsigned int md_len;
		
		//Digest for message 1
		mdctx = EVP_MD_CTX_create();
		EVP_DigestInit_ex(mdctx, md, NULL);
		EVP_DigestUpdate(mdctx, mess1.c_str(), strlen(mess1.c_str()));
		EVP_DigestFinal_ex(mdctx, md_value_1, &md_len);
		EVP_MD_CTX_destroy(mdctx);
		
		//Digest for message 2
		mdctx = EVP_MD_CTX_create();
		EVP_DigestInit_ex(mdctx, md, NULL);
		EVP_DigestUpdate(mdctx, mess2.c_str(), strlen(mess2.c_str()));
		EVP_DigestFinal_ex(mdctx, md_value_2, &md_len);
		EVP_MD_CTX_destroy(mdctx);
		
		
		//compare the first 24 bits of h1 and h2	
	    if(memcmp ( md_value_1, md_value_2, 3 ) == 0){
	        cout << "Found the two messages!" << endl;
	        printf("M1: %s \n", mess1.c_str());
	        printf("M2: %s \n", mess2.c_str());
	        printf("Digest 1: ");
	        print_digest(md_value_1, md_len);
	        printf("Digest 2: ");
	        print_digest(md_value_2, md_len);
	    	cout << "Trials: " << y << endl;
	        looping = false;
	    }
	    y++;
	}
 }
