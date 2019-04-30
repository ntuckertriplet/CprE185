# This is an RSA encryption program for my 185 final

This is some neat code that even some parts go over my head, but this a brief explanation of how it works

# The steps

## 1) Choose two random primes, p and q
this is done by grabbing two random prime numbers from primes.txt
## 2) Calculate n
n is p * q
## 3) Calculate totient n
totient n = (p - 1) * (q - 1)
## 4) Choose e
e > 1 and e is coprime to totient n
## 5) Calculate d
d is a difficult one. It is stored as the private key exponent.
Additionally, de satisfies the congruence relation to 1 mod totient n
## 6) Now that you have all of your elements to the keys, store them in appropriate values.
The public key contains n and e, n as the modulus, e as the exponent
The private key needs to contain the same exact modulus, but stores d as the exponent
## 7) Finally, you can encrypt and decrypt
your message, m, is encrypted to enc, calculated as enc = pow(m, e) mod n
I looped through each element of the string and encrypted it individually
To decrypt, it's a very simple process
Your decrypted, dec, is your encrypted, pow(enc, d) mod n
