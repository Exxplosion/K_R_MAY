#include <cstring>
#include <cmath>
#include "calc.h"

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[], int size)
{
    int n_cpy = n;
    int i, sign;

    if ((sign = n) < 0) /* записываем знак */
        n = -n;         /* делаем n положительным числом */
    i = 0;
    do
    {                          /* генерируем цифры в обратном порядке */
        s[i++] = n % 4 + '0'; /* берем следующую цифру */
    } while ((n /= 4) > 0);   /* удаляем */
    if (sign < 0)
        s[i++] = '-';
    if (n_cpy < pow(4, size - 2))
    {
        //printf("lol!, %d\n", n);
        s[i] = '0';
    }
    reverse(s);
}

bool found = false;



int main (int argc, char *argv[])
{
    const int size = argc - 2;
    //printf(" HAHA %d\n", size);
    char *operation_arr = (char *)calloc(size - 1, sizeof(char));
    char *new_ar = (char *)calloc(2*size -1, sizeof(char));
    char *oper_arr = (char *)calloc(size - 1, sizeof(char));

 
        int sum = 0;

        while (sum < pow(4, size - 1))
        {
            for (int i = 0; i < size - 1; i++)
            {
                oper_arr[i] = '0';
            }
            itoa(sum, oper_arr, size);
            //printf("RESULT: %s\n", operation_arr);

        oper_arr[size] = '\0';
        //printf("RESULT2: %s\n", oper_arr);

        int j = 0;
        int l = 0;
        for (int i = 0; i < 2 * size - 1; i++)
        {
            if (!(i % 2))
            {
                new_ar[i] = argv[j+2][0];
                j++;
            }
            else
            {
                switch (oper_arr[l])
                {
                case '0':
                    new_ar[i] = '~';
                    break;
                case '1':
                    new_ar[i] = '+';
                    break;
                case '2':
                    new_ar[i] = '-';
                    break;
                case '3':
                    new_ar[i] = '*';
                    break;
                default:
                    new_ar[i] = '~';
                    break;
                }
                l++;
            }
        }
        //printf("%s", new_ar);

        int res_sum = getG(new_ar);
        //printf(" = %d\n", res_sum);
        if(atoi(argv[1]) == res_sum)
        {
            found = true;
            //printf("\nFOUND :\n");
            for (int i = 0; i < 2 * size - 1; i++)
            {
                if (new_ar[i] != '~')
                    printf("%c", new_ar[i]);
            }
            printf( " = %d\n", res_sum);
            //return 0;
        }
        sum++;
    }
    if (!(found))
        printf("not found!");
    }