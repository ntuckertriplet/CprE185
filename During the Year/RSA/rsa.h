#ifndef __RSA_H__
#define __RSA_H__

#include <stdint.h>

// the hardcoded primes file
char *primelistfile = "primes.txt";


struct public_key_struct{
	long long exponent;
	long long modulus;
};

struct private_key_struct{
	long long exponent;
	long long modulus;
};

// This function generates public and private keys, then stores them in the structs. 
// The 3rd argument should be the text primetext to have it use
// the location specified above in this header.
void rsa_gen_keys(struct public_key_class *pub, struct private_key_class *priv, char *primelistfile);

// This function will encrypt the data pointed to by message. 
// The encrypted data will be 8 times as large as the original data.
// The data will be stored as a long long, or 64 bit integer
long long *rsa_encrypt(char *message, unsigned long message_size, struct public_key_class *pub);

// This function will decrypt the data pointed to by message. 
// The variable message_size is the size in bytes of the encrypted message. 
// Decrypted data will be 1/8th the size of the encrypted data.
char *rsa_decrypt(long long *message, unsigned long message_size, struct private_key_class *pub);

#endif
