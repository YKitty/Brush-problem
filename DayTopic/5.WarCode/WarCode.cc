#include <iostream>
#include <stdio.h>

void DigitInit(int a[])
{
    int i = 0;
    for (i = 3; i < 10005; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] >= 10000)
        {
            a[i] %= 10000;
        }
    }
}

int main()
{
    int array[10005] = { 0, 1, 2, 3, 5 };
    int num, tmp;
    DigitInit(array);
    while (scanf("%d", &num) != EOF)
    {
        while (num--)
        {
            scanf("%d", &tmp);
            //这是为了那些不足4位的，进行输出
            printf("%04d", array[tmp]);
        }
        printf("\n");
    }
    return 0;
}
