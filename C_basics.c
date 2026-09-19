#include <stdio.h>

int main(){char name[100];
    int age;
    int amount = 0;
    int i =0;
    while(i != -1){
        printf("请输入您的姓名，年龄:\n");
        scanf(" %99[^\n] %d",name,&age);
        printf("\n您的姓名是：%s,您的年龄是：%d岁",name,age);
        amount++;
        printf("\n是否继续输入？\n输入-1退出,其他数字继续:\n");
        scanf("%d",&i);
    }
    printf("您一共操作了%d次",amount);
    return 0;

}