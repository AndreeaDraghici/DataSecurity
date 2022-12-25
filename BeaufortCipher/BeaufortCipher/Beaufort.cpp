#define _CRT_SECURE_NO_WARNINGS
/**
* Author: Draghici Andreea
* Date: 25.12.2022
* Beaufort Cipher
**/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<iostream>

using namespace std;

string cipher(string text, string cheie){

	string cipher;
	string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < text.size(); i++) {

		char c0 = text[i];
		char c1 = cheie[i % cheie.size()];

		int start = 0;
		for (int j = 0; j < 26; j++) {
			if (alfabet[j] == toupper(c0)) {
				start = j;
				break;
			}
		}

		int offSet = 0;
		for (int j = start; j < start + 26; j++) {
			int letter = j % 26;
			if (alfabet[letter] == toupper(c1)) {
				break;
			}
			offSet++;
		}
		cipher += alfabet[offSet];
	}
	return cipher;
}

int main()
{
	string text, cheie, result;
	int optiune = 0;

	cout << "Intoduceti cheia: ";
	cin >> cheie;

	printf("\n1 Criptare\n2 Decriptare\n3 Exit\nOptiunea aleasa este: ");
	scanf_s("%d", &optiune);

	switch (optiune) {
	case 1:
		cout << "Introduceti plain text-ul: ";
		cin >> text;
		result = cipher(text, cheie);
		cout << "Text-ul criptat este: " << result << endl;
		break;
	case 2:
		cout << "Introduceti text-ul criptat(criptograma): ";
		cin >> text;
		result = cipher(text, cheie);
		cout << "Text-ul decriptat este: " << result << endl;
		break;
	default:
		break;
	}
	return 0;
}