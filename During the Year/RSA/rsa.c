#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdint.h>



//stored as int now, as they will be modified to a long long type
//for encryption and decryption
int i,j = 0;

//public key component containing the exp and mod
//The exponent will be the same as the private key
struct public_key_struct{
  long long exponent;
  long long modulus;
};

//private key component
struct private_key_struct{
  long long exponent;
  long long modulus;
};



// Recursive function to return gcd of a and b 
int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0){ 
       return b;
    } 
    if (b == 0){ 
       return a;
    } 
    // base case 
    if (a == b){ 
        return a;
    }	
    // a is greater 
    if (a > b){ 
        return gcd(a-b, b);
    }	
    return gcd(a, b-a); 
}

// this function is using the extended euclidian algorithm to calculate d
// essentially, to find d, it needs to satisfy de ≡ 1 mod phi
// it's a little hard to follow, and even some of the logic goes a little over my head
// all i know it that it works, and if it works, it doesn't need fixed
long long calculate_d(long long a, long long b){
 long long x = 0, d = 1, u = 1, v = 0; 
 long long gcd = b, var_a, n, q, var_b;
 do{
   q = gcd/a; 
   var_b = gcd % a;
   var_a = x-u*q; 
   n = d-v*q;
   gcd = a; 
   a = var_b; 
   x = u; 
   d = v; 
   u = var_a; 
   v = n;
   } while (a != 0); 
   return d;
}

// recursively go through and go from encrypted to decrypted or vice versa
// the math works the same when given the public key to encrypt and the private key to decrypt
long long calculate_mod_exp(long long mess, long long exp, long long mod){
// if any are negative or the message is less than or equal to zero, it won't work, break
  if (mess < 0 || exp < 0 || mod <= 0){
    exit(-1);
  }
  mess %= mod;
  
  //case if even
  if(exp % 2 == 0){
    return (calculate_mod_exp(mess * mess % mod), (exp / 2), mod) % mod);
  }
  //case if odd
  if(e % 2 == 1){
    return (mess * calculate_mod_exp(mess, (exp - 1), mod) % mod);
  }

}



//a buffer of a large size with more than enough spaces for the prime numbers
//a null character will be appended in the correct position at the end of the primes list
char buffer[1000];

//unchanged value, ergo const
const int largest_nums = 64;


// generate a public and private key, given the primes list and the key structs
void rsa_gen_keys(struct public_key_struct *pub, struct private_key_struct *priv, char *primelistfile)
{
  FILE *prime_list = fopen(primelistfile, "r");

  // count number of primes in the list
  int num_primes = 0;
 
  //do - while because it will need to be done at least once
  do{
    //read in the file, putting each element in the buffer
    int position = fread(buffer, 1, sizeof(buffer) - 1, prime_list);
   
    //need a null character to stop an array
    buffer[position] = '\0';
    for (i=0 ; buffer[i]; i++){

      //file is in a list format, with one number on each line.
      //therefore, every number would require a new line space except the last one
      if (buffer[i] == '\n'){
		num_primes++;
      }
    }
  }

  //stop at end of file
  while(feof(primes_list) == 0);
  
  
  // choose random primes from the list, store them as p,q

  long long p = 0;
  long long q = 0;
  
  //powl is pow using longs
  long long e = powl(2, 8) + 1; // e = 257
  long long d = 0;
  char prime_buffer[largest_nums];
  long long max = 0;
  long long totient_n = 0;
  
  //seed random
  srand(time(NULL));
  
  do{
    // a and b are the positions of p and q in the list
    int a =  (double)rand() * (prime_count+1) / (RAND_MAX+1.0);
    int b =  (double)rand() * (prime_count+1) / (RAND_MAX+1.0);
    
    // rewind to the start of the file in order to go through and select values
    rewind(primes_list);
    for(i=0; i < a + 1; i++){
      fgets(prime_buffer,sizeof(prime_buffer)-1, primes_list);
    }
    p = atol(prime_buffer); 
    
    // here we find the prime at position b, store it as q
    rewind(primes_list);
    for(i=0; i < b + 1; i++){
      for(j=0; j < largest_nums; j++){
	prime_buffer[j] = 0;
      }
      fgets(prime_buffer,sizeof(prime_buffer)-1, primes_list);
    }
    q = atol(prime_buffer); 

    max = p*q;
    totient_n = (p-1)*(q-1);
  }
  while(!(p && q) || (p == q) || (gcd(totient_n, e) != 1));
 
  // Next, we need to choose a,b, so that a*max+b*e = gcd(max,e). We actually only need b
  // here, and in keeping with the usual notation of RSA we'll call it d. We'd also like 
  // to make sure we get a representation of d as positive, hence the while loop.
  d = calculate_d(totient_n,e);
  while(d < 0){
    d += totient_n;
  }

  printf("primes are %lld and %lld\n",(long long)p, (long long )q);
  // Store public and private key values n, d, and e
  pub->modulus = max;
  pub->exponent = e;

  priv->modulus = max;
  priv->exponent = d;
}


long long *rsa_encrypt(char *message, unsigned long message_size, struct public_key_struct *pub){
  long long *encrypted = malloc(sizeof(long long)*message_size);
  
  long long i = 0;
  for(i=0; i < message_size; i++){
    encrypted[i] = calculate_mod_exp(message[i], pub->exponent, pub->modulus);
  }
  return encrypted;
}


char *rsa_decrypt(long long *message, unsigned long message_size, struct private_key_struct *priv){
  // We allocate space to do the decryption (temp) and space for the output as a char array
  char *decrypted = malloc(message_size/sizeof(long long));
  char *temp = malloc(message_size);
 
  // Store each value of the decrypted message in temp, as a mediary for temp to decrypted
  long long i = 0;
  for(i=0; i < message_size/8; i++){
    temp[i] = calculate_mod_exp(message[i], priv->exponent, priv->modulus);
  }
  // We move each character over now that it is in the range of char
  for(i=0; i < message_size/8; i++){
    decrypted[i] = temp[i];
  }
  free(temp);
  return decrypted;
}
