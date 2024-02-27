#include <stdio.h>
#include <string.h>
#include <ctype.h>

unsigned long convert(char w[])
{
    printf("w = %s\n", w);
    unsigned long zecimal = 0;
    int q = 0;
    for(int i = 0; i < strlen(w); i++)
    {
        if(isdigit(w[i]))
        {
            zecimal = zecimal*16 + (w[i] - '0');
        }
        else if((toupper(w[i]) >= 'A') && (toupper(w[i]) <= 'F'))
        {
            zecimal = zecimal*16 + 10 + (w[i] - 'A');
        }
        else
        {
            printf("ERROR\n");
            break;
        }
    }
    return zecimal;
}

unsigned long max_buf(unsigned long buff[])
{
    unsigned long max = buff[0];
    int i = 1;
    while(buff[i]!= 0)
    {
        if(max < buff[i])
        {
            max = buff[i];
        }
        i++;
    }
    return max;
}

double avg_buf(unsigned long buff[], int k)
{
    unsigned long s = 0;
    for(int i = 0; i < k; i++)
    {
        s = s + buff[i];
    }
    return (double)s/k;
}

void hexa_in_string(char s[])
{
    printf("%s\n", s);
    int i = 0;
    int st = 0;
    char w[100];
    int j = 0;
    unsigned long buff[100];
    int k = 0;

    int sum = 0;
    while(s[i] !='\0')
    {
        printf("st=%d, c=%c\n", st, s[i]);
        if(st == 0)
        {
            if(s[i] == '0')
            {
                st = 1;
                i++;
            }
            else if(s[i] == '\n')
            {
                st = 5;
            }
            else
            {
                st = 0;
                i++;
            }
        }
        else if(st == 1)
        {
            if(s[i] == 'x')
            {
                i++;
                st = 2;
            }
            else
            {
                st = 0;
                i++;
            }
        }
        else if(st == 2)
        {
            if (isdigit(s[i]) || (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F'))
            {
                w[j] = s[i];
                j++;
                st = 3;
                i++;
            }
            else
            {
                st = 0;
                i++;
            }
        }
        else if(st == 3)
        {
            if (isdigit(s[i]) || (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'F'))
            {
                w[j] = s[i];
                j++;
                st = 3;
                i++;
            }
            else
            {
                st = 4;
            }
        }
        else if(st == 4)
        {
            w[j] = 0;
            j = 0;
            unsigned long x = convert(w);
            printf("Am gasit un numar: %lu\n", x);
            buff[k] = x;
            k++;
            st = 0;
            i++;
        }
        else if(st == 5)
        {
            printf("Am gasit linie noua\n");
            for(int i = 0; i < k; i++)
            {
                printf("buff = %lu", buff[k]);
            }
            printf("\n");
            unsigned long m = max_buf(buff);
            printf("Maximul este: %lu\n", m);
            double avg = avg_buf(buff, k);
            printf("Media este: %lu\n", avg);
            for(int i = 0; i < k; i++)
            {
                buff[k] = 0;
            }
            k = 0;
            st = 0;
            i++;
        }
    }
}

void citire(char s[])
{
    char c;
    int i;
    c = getchar();
    i = 0;
    while (c != EOF)
    {
        s[i] = c;
        i++;
        c = getchar();
    }
    hexa_in_string(s);
}

int main()
{
    char s[100];
    citire(s);
    return 0;
}
