/**
* Author: Draghici Andreea
* Date: 18.12.022
* Vigenere Cipher
**/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>
using namespace std;

#define MAX_SIZE 1024

char encodeChar(char r) {
    return r - 65;
}

int main()
{
    char text[MAX_SIZE];
    char key[MAX_SIZE];
    unsigned char decode[MAX_SIZE];
    unsigned char encode[MAX_SIZE];

    cout << "Adauga text-ul: " << endl;
    cin >> text;
    cout << "Adauga cheia: " << endl;
    cin >> key;

    int len = strlen(text);
    int len_key = strlen(key);
    int i = 0, j = 0;

    for (i = 0; i < len; i++, j++) {

        char lower = ((((text[i]) - 97) + ((key[j]) - 97)) % 26) + 97;
        if (j >= len_key) j = 0;
        decode[i] = lower;
    }
    cout << "Criptare: ";
    for (i = 0; i < len; i++, j++) {
        cout << decode[i] << " ";
    }
    cout << endl;

    for (i = 0, j = 0; i < len; i++, j++) {
        char lower = ((((decode[i]) - 97) - ((key[j]) - 97)) % 26) + 97;
        if (j >= len_key) j = 0;

        encode[i] = lower;
    }
    cout << "Decriptare: ";

    for (i = 0; i < len; i++) {
        cout << encode[i];
    }


    return 0;
}