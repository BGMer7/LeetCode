#include <stdio.h>
int main()
{
    int a[11];
    for (int i = 0; i < 11; i++)
    {
        a[i] = 0; // 初始化为0
    }

    for (int i = 0; i < 5; i++)    // 循环读入5个数
    {
        int t;
        scanf("%d", &t); // 把每个数读到变量t中
        a[t]++;          // 进行计数
    }

    for (int i = 0; i < 11; i++) // 依次判断a[0]~a[10]
        for (int j = 1; j <= a[i]; j++)
                // 出现了几次就打印几次
                printf("%d", i);

    getchar();
    getchar();
    // 暂停程序，查看程序输出内容，也可以用system("pause");等来代替
    return 0;
}