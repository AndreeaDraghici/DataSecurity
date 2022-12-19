#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>


#define TEXT_SIZE 30

using namespace std;

/**
* Author: Draghici Andreea
* Date: 19.12.2022
* Caesar Cipher
**/

string lower(string s)
{

    string lower = "";

    for (int i = 0; i < s.length(); i++) {
        lower += tolower(s[i]);
    }
    return lower;

}


string make_even(string s)
{

    int length = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            length++;
        }
    }

    if (length % 2 != 0) {
        s.append("z");
    }

    return s;
}


void genereaza_patratul_polybius(string key, char matrix[5][5])
{

    int visit[26];
    int i, j, cntr;
    string result;

    for (cntr = 0; cntr < 26; cntr++) {
        if ((char)(cntr + 97) != 'j')
            visit[cntr] = 1;
    }

    for (cntr = 0; cntr < key.length(); cntr++) {
        visit[key[cntr] - 97] = 0;
    }

    i = 0;
    j = 0;
    for (int l = 0; l < key.length(); l++) {
        if (visit[key[l] - 97] == 0) {
            visit[key[l] - 97] = -1;
            matrix[i][j] = key[l];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

    for (cntr = 0; cntr < 26; cntr++) {
        if (visit[cntr] == 1) {
            matrix[i][j] = (char)(cntr + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    cout << "Patratul lui Ploybius este: "<<endl;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void criptare(string text, char matrix[5][5])
{

    int i, j, k;
    int x1, y1, x2, y2;
    string result = "";

    for (i = 0; i < text.length(); i += 2) {

        if (text[i] != ' ') {

            int count = i;

            for (j = 0; j < 5; j++) {
                for (k = 0; k < 5; k++) {
                    if (matrix[j][k] == text[count]) {
                        x1 = j;
                        y1 = k;
                    }
                    else if (matrix[j][k] == text[count + 1]) {
                        x2 = j;
                        y2 = k;
                    }
                }
            }

            if (x1 == x2) {
                //same row
                result += (matrix[x1][(y1 + 1) % 5]);
                result += (matrix[x1][(y2 + 1) % 5]);
            }
            else if (y1 == y2) {
                //same column
                result += (matrix[(x1 + 1) % 5][y1]);
                result += (matrix[(x2 + 1) % 5][y1]);
            }
            else {
                result += (matrix[x1][y2 % 5]);
                result += (matrix[x2 % 5][y1]);
            }

        }

    }

    cout  <<"Text-ul criptat este: "<< result << endl;

}

void decriptare(string text, char matrix[5][5])
{

    int i, j, k;
    int x1, y1, x2, y2;
    string result = "";

    for (i = 0; i < text.length(); i += 2) {

        if (text[i] != ' ') {

            int count = i;

            for (j = 0; j < 5; j++) {
                for (k = 0; k < 5; k++) {
                    if (matrix[j][k] == text[count]) {
                        x1 = j;
                        y1 = k;
                    }
                    else if (matrix[j][k] == text[count + 1]) {
                        x2 = j;
                        y2 = k;
                    }
                }
            }

            if (x1 == x2) {
                //same row
                result += (matrix[x1][(y1 + 4) % 5]);
                result += (matrix[x1][(y2 + 4) % 5]);
            }
            else if (y1 == y2) {
                //same column
                result += (matrix[(x1 + 4) % 5][y1]);
                result += (matrix[(x2 + 4) % 5][y1]);
            }
            else {
                result += (matrix[x1][y2 % 5]);
                result += (matrix[x2 % 5][y1]);
            }

        }

    }

    cout << "Text-ul decriptat este: "<< result << endl;

}

int main()
{
    string key;
    string text;
    char matrix[5][5];
    int option = 0;

    cout << "Introduce cheia: ";
    cin >> key;
    cout << "Introduce criptograma: ";
    cin >> ws;

    getline(cin, text);

    string low_key = lower(key);

    genereaza_patratul_polybius(low_key, matrix);

    string even = make_even(text);
    string low_case = lower(even);

    printf("\n1 Criptare\n2 Decriptare\n3 Exit\nOptiunea aleasa este: ");
    scanf_s("%d", &option);

    switch (option) {
       case 1:
          criptare(low_case, matrix);
          break;
       case 2:
          decriptare(low_case, matrix);
          break;
       default:
          break;
    } 
    return 0;
}