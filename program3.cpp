/*
@author Aniket Gauba and Ethan Tecson
@caesar_cipher Program
@The key you used to hack ciphertext is 7
@The author of the famous quote is Lady Gaga(Lyrics from Born this way) 
@created 2023-02-10
@updated 2023-02-13
*/

// Header files
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Declares the functions
string lowercase(string text);
string translate(string ciphertext, int key);

// lowercase function
string lowercase(string code){
    // The function makes the string lowercase
    int i; // Declare int variable
    int ascii_int; // Declare int variable
    string lower; // Declare string
    for (i = 0; i < code.length(); i++) 
    { 
        ascii_int = int(code[i]); // Store ascii value
        if ((ascii_int > 64) and (ascii_int < 91)) // If char uppercase
            lower = lower + char(ascii_int+32); // Add lowercase to text
        else 
            lower = lower + code[i]; // Add lowercase to text
    }
    return lower; 
}

// translate function
string translate(string ciphertext, int key){
    // Function returns the plaintext of the provided ciphertext and key
    int i;  // Declare int variable
    int cipher_ascii_int;  // Declare int variable
    int ascii_int_plain; // Declare int variable
    string plaintext; // Declare string variable
    for (i = 0; i < ciphertext.length(); i++) 
    { 
        cipher_ascii_int = int(ciphertext[i])-71; // (ascii value - 97 + 26)

        if (isspace(ciphertext[i])) // If char is whitespace
            plaintext = plaintext + ciphertext[i];  // Add whitespace to plaintext

        else if ((cipher_ascii_int > 25) and (cipher_ascii_int < 52)){  // If char between a-z
            ascii_int_plain = (cipher_ascii_int-key)%26;    
            plaintext = plaintext + char(ascii_int_plain+97);
        }
    }
    return plaintext;
}

// main function
int main (int argc, char *argv[]){
    // Parameter argc is the number of arguments the fnction takes
    // Parameter argv determines what input you want
    string line, ciphertext, plaintext; // Declare string variables
    int key; // Declare int variable

    if (argc > 1){  // If argument provided
        key = atoi(argv[1]);    // Key is 2nd argument
    }
    else{
        key = 3;    // else, key is 3
    }

    while (getline(cin, line)){ // Get input till end of line
        ciphertext = ciphertext + "\n" + line; // Adds a newline character
    }

    ciphertext = lowercase(ciphertext); // lowercase text
    plaintext = translate(ciphertext, key);  // decipher text

    cout << "Plain text is: " << plaintext << endl; // Print plaintext

    return 0;
}