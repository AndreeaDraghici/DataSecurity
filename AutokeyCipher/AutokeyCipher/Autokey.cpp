#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

/**
* Author: Draghici Andreea
* Date: 24.12.2022
* Autokey Cipher
**/


#define TEXT_SIZE 26
#define A 65


int initTable(char table[TEXT_SIZE][TEXT_SIZE]);
void copy(char* dest, char* src, int len);

int encrypt(char* cheie, char* sursa, char* destinatie)
{
	char table[TEXT_SIZE][TEXT_SIZE];
	char* source = sursa;
	char* key = cheie;
	char* destination = destinatie;

	initTable(table);

	do {
		if (!isalpha(*source))
		{
			continue;
		}
		*destination++ = table[toupper(*key) - A][toupper(*source) - A];

		if (!(*(++key)))
			key = cheie;
	} while (*source++);

	destinatie[strlen(sursa)] = 0;
	return 1;
}


int decrypt(char* cheie, char* sursa, char* destinatie)
{
	char* source = sursa;
	char* key = cheie;
	char* destination = destinatie;
	char offset;

	do {
		offset = (*source) - toupper(*key);
		offset = offset >= 0 ? offset : offset + TEXT_SIZE;
		*destination++ = A + offset;

		if (!(*(++key)))
			key = cheie;
	} while (*source++);

	destinatie[strlen(sursa)] = 0;
	return 1;
}

void getKey(char* cheie, char* text, char* cuvant)
{
	int total = strlen(text);
	int lungime = strlen(cuvant);

	if (lungime)
	{
		copy(cheie, cuvant, lungime);
	}

	copy(cheie + lungime, text, total - lungime);
}

void copy(char* destinatie, char* sursa, int lungime)
{
	while (lungime-- > 0)
	{
		if (isalpha(*sursa))
		{
			*destinatie++ = toupper(*sursa);
		}

		sursa++;
	}
}

int initTable(char table[TEXT_SIZE][TEXT_SIZE])
{
	int i, j;
	for (i = 0; i < TEXT_SIZE; i++) {
		for (j = 0; j < TEXT_SIZE; j++) {
			table[i][j] = A + (i + j) % TEXT_SIZE;
		}
	}
	return 1;
}

int main()
{
	
	//CRIPTOGRAMA: NTUEIXPLHNGJWGMYFXTSOZLCVYKSFLXFPNBXGGMCYVWYYUSUASXSHSWZLCVYLSLHCQVMZXAWFG 

	char plainText[256] = "WISEMENTALKBECAUSETHEYHAVESOMETHINGTOSAYFOOLSBECAUSETHEYHAVETOSAYSOMETHING";
	char key[256] = "";
	char password[256] = "RLCAWTCSHCWISEMENTALKBECAUSETHEYHAVESOMETHINGTOSAYFOOLSBECAUSETHEYHAVETOSA";

	char ciphertext[256];
	char output[256];


	getKey(key, plainText, password);
	cout << "Cheia: " << key<<endl;

	encrypt(key, plainText, ciphertext);
	cout << "\nText criptat: " << ciphertext<<endl;


	decrypt(key, ciphertext, output);
	cout << "\nText decriptat: " << output<<endl;

	return 0;
}