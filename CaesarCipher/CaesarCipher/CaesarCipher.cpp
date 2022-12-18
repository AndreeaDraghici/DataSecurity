#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define TEXT_SIZE 150

/**
* Author: Draghici Andreea
* Date: 10.12.022
* Caesar Cipher
**/
int main()
{
    char mesaj[100], caracter;
    int idx, key, optiune = 1;
    char parola;

    while (optiune != 3)
    {
        printf("\n1 Criptare\n2 Decriptare\n3 Exist\nOptiunea aleasa este: ");
        scanf_s("%d", &optiune);

        switch (optiune)
        {
        case 1:

            FILE * fp;
            fp = fopen("fisier.txt", "w");
            printf("Alegeti deplasarea= ");
            scanf_s("%d", &key);

            printf("Introduceti parola= ");
            scanf_s("%d", &parola);

            gets_s(mesaj);

            for (idx = 0; mesaj[idx] != '\0'; ++idx)
            {
                caracter = mesaj[idx];
                if (caracter >= 'a' && caracter <= 'z')
                {
                    caracter = caracter + key;

                    if (caracter > 'z')
                    {
                        caracter = caracter - 'z' + 'a' - 1;

                    }
                    mesaj[idx] = caracter;
                }
                else if (caracter >= 'A' && caracter <= 'Z')
                {
                    caracter = caracter + key;

                    if (caracter >= 'Z')
                    {
                        caracter = caracter - 'Z' + 'A' - 1;
                    }

                    mesaj[idx] = caracter;
                }

            }

            printf("Parola criptata este: %s", mesaj);
            fprintf(fp, "%s", mesaj);
            break;

        case 2:
            FILE * fp1;
            fp1 = fopen("fisier.txt", "r");
            if (fp1 == NULL)
            {
                printf("Nu exista fisierul");
                return 1;
            }
            printf("Alegeti deplasarea= ");
            scanf_s("%d", &key);
            fgets(mesaj, TEXT_SIZE, fp1);
            fclose(fp1);


            for (idx = 0; mesaj[idx] != '\0'; ++idx)
            {
                caracter = mesaj[idx];
                if (caracter >= 'a' && caracter <= 'z')
                {
                    caracter = caracter + key;

                    if (caracter > 'z')
                    {
                        caracter = caracter - 'z' + 'a' - 1;

                    }
                    mesaj[idx] = caracter;
                }
                else if (caracter >= 'A' && caracter <= 'Z')
                {
                    caracter = caracter + key;

                    if (caracter >= 'Z')
                    {
                        caracter = caracter - 'Z' + 'A' - 1;
                    }

                    mesaj[idx] = caracter;
                }

            }

            printf("Parola decriptata este: %s", mesaj);
            fprintf(fp1, "%s", mesaj);
            break;

        }

        return 0;
    }
}
