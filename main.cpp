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

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) /* записываем знак */
        n = -n;         /* делаем n положительным числом */
    i = 0;
    do
    {                          /* генерируем цифры в обратном порядке */
        s[i++] = n % 5 + '0'; /* берем следующую цифру */
    } while ((n /= 5) > 0);   /* удаляем */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}



int main (int argc, char *argv[])
{
    const int size = argc - 2;
    printf(" HAHA %d\n", size);
    char *operation_arr = (char *)calloc(size - 1, sizeof(char));
    char *new_ar = (char *)calloc(2*size -1, sizeof(char));

    int sum = 0;

    while (sum < pow(5, size-1))
    {
        itoa(sum, operation_arr);
        for (int i = 0; i < size-1; i++)
        {
            if (operation_arr[i] == '\0')
                operation_arr[i] = '0';
        }

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
                switch (operation_arr[l])
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
        printf("%s", new_ar);

        int res_sum = getG(new_ar);
        printf(" = %d\n", res_sum);
        if(atoi(argv[1]) == res_sum)
        {
            printf("FOUND :\n");
            for (int i = 0; i < 2 * size - 1; i++)
            {
                if (new_ar[i] != '~')
                    printf("%c", new_ar[i]);
            }
            printf( " = %d", res_sum);
            return 0;
        }
        sum++;
    }
    printf("not found!");
}