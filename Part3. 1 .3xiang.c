#include <stdio.h>

//考虑到求平均数，总成绩时难免会出现小数
//于是，将部分数据改成了双精浮点数。
double power(int i,int amount);
double zh_function(double p,double f);
int compare(double zh1,double zh2,double zh3);
//观察到在计算综合成绩时依然存在大面积复用情况
//于是，除题目要求外，我额外添加了zh_n函数，以期减少主函数中的复用现象。
double zh_n(int x,int y,int z);

int main(){
    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;

    printf("请输入小明的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &x1, &x2, &x3);
    printf("请输入小强的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &y1, &y2, &y3);
    printf("请输入小林的三项成绩（顺序为A B C,以一个空格为间隔）：");
    scanf("%d %d %d", &z1, &z2, &z3);

    double zh1 = zh_n(x1,x2,x3);
    double zh2 = zh_n(y1,y2,y3);
    double zh3 = zh_n(z1,z2,z3);
//将各自的综合成绩计算出来，更直观的同时，还可以判断compare函数有没有出错
//但是，这个数值太丑了。。
    printf("小明的综合成绩是%2f\n",zh1);
    printf("小强的综合成绩是%2f\n",zh2); 
   	printf("小林的综合成绩是%2f\n",zh3);

    compare(zh1,zh2,zh3);
    return 0;
}
//虽然计算方差只需要用到平方，但写出真正意义上的乘方函数而不是平方函数，是一劳永逸的事情，何乐而不为呢？
double power(int i,int amount){
    double sum = 1;
    for(int index =0;index<amount;index++){
        sum = sum*i;
    }
    return sum;
}
//封装综合成绩的函数，乏善可陈。
double zh_function(double p,double f){
    double sum = 3*p-f/3;
    return sum;
}
/*一方面我并不是很想要直接复制题目代码粘贴
另一方面，个人认为这样更加符合我的思考过程（看起来稍显复杂，其实也还好吧...嗯..应该吧）
另外，我取了等号，这样也许会严谨一些*/
int compare(double zh1,double zh2,double zh3){
    if(zh1 >= zh2){
        if(zh3 >=zh1){
            printf("小林 >=小明 >=小强");
        }else if(zh3 >= zh2){
            printf("小明 >=小林 >=小强");
        }else{
            printf("小明 >=小强 >=小林");
        }
    }else{
        if(zh3 >= zh2){
              printf("小林 >=小强 >= 小明");
        }else if(zh3 >= zh1){
            printf("小强 >=小林 >=小明");
        }else{
            printf("小强 >=小明 >= 小林");
        }
    }
     
    return 0;
}
double zh_n(int x,int y,int z){
    double p = (x + y + z) / 3.0;
    double f = power((p-x),2)+power((p-y),2)+power((p-z),2);
    double zh = zh_function(p,f);
    return zh;
}