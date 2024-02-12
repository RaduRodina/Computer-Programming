#include <stdio.h>
#include <stdint.h>
#include <string.h>

int identici(unsigned short x, unsigned short y)
{
    unsigned short m;
    unsigned short n1;
    unsigned short n2;

    printf("x = %x y = %x\n", x, y);
    m = 0xF000;
    for (int i = 0; i < sizeof(m)*8/4; i++)
    {
        n1 = x&m;
        n2 = y&m;
        printf("n1 = %x\n", n1);
        printf("n2 = %x\n", n2);
        m = m >> 4;

        if(n1 == n2)
        {
            return 1;
        }

    }

    return 0;
}


unsigned long countPairsN(unsigned k)
{
    unsigned short x1[100];
    unsigned short x2[100];

    x1[0] = 0xBA32;
    x2[0] = 0xCAD1;
    x1[1] = 0xAB54;
    x2[1] = 0xAD32;
    x1[2] = 0xBA32;
    x2[2] = 0xCAD1;
    x1[3] = 0xDB34;
    x2[3] = 0xAD42;
    x1[4] = 0xDA64;
    x2[4] = 0xAE52;
    unsigned long j = 0;
    for(int i = 0; i < k; i++)
    {
        if(identici(x1[i], x2[i]))
        {
            printf("%x %x\n", x1[i], x2[i]);
            j++;
        }
    }
    return j;
}

int main()
{
    unsigned  k = 5;
    unsigned long rezultat;
    rezultat = countPairsN(k);
    printf("rezultat = %lu\n", rezultat);

    return 0;
}
