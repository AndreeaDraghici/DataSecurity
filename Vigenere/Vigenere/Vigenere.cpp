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

int main()
{
    char mesaj[MAX_SIZE];
    char key[MAX_SIZE];
    unsigned char decriptare[MAX_SIZE];
    unsigned char criptare[MAX_SIZE];

    cout << "Introduceti  mesajul: " << endl;
    cin >> mesaj;
    cout << "Introduceti  cheia: " << endl;
    cin >> key;

    int lungime_mesaj = strlen(mesaj);
    int lungime_cheie = strlen(key);
    int idx = 0, cntr = 0;

    for (idx = 0; idx < lungime_mesaj; idx++, cntr++) {

        char lower = ((((mesaj[idx]) - 97) + ((key[cntr]) - 97)) % 26) + 97;
        if (cntr >= lungime_cheie) cntr = 0;
        decriptare[idx] = lower;
    }
    cout << "Mesaj Decriptat: ";
    for (idx = 0; idx < lungime_mesaj; idx++, cntr++) {
        cout << decriptare[idx] << " ";
    }
    cout << endl;

    for (idx = 0, cntr = 0; idx < lungime_mesaj; idx++, cntr++) {
        char lower = ((((decriptare[idx]) - 97) - ((key[cntr]) - 97)) % 26) + 97;
        if (cntr >= lungime_cheie) cntr = 0;

        criptare[idx] = lower;
    }
    cout << "Mesaj Criptat: ";

    for (idx = 0; idx < lungime_mesaj; idx++) {
        cout << criptare[idx];
    }


    return 0;
}