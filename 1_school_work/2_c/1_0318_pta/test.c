#include<stdio.h>
struct std{
    char name[10];
    char id[5];
    int score;
    int score2;
    int score3;
};

int main(void){
    int n, i, sum=0;
    int max = 0;
    int flag = 0;

    scanf("%d", &n); //输入n

    struct std a[n]; //结构体数组

    for(i=0;i<n;i++){
        scanf("%s %s %d %d %d", a[i].name, a[i].id, &a[i].score, &a[i].score2, &a[i].score3);
    }

    for(i=0;i<n;i++){
        sum = a[i].score+a[i].score2+a[i].score3;
        if (max < sum) {
            max = sum;
            flag = i;
        }
    }
    printf("%s %s %d",a[flag].name,a[flag].id,max);

    return 0;
}

//N个学生
//5个数字的字符串,学号
//长度小于10的不包含空白字符的字符串,名字
//3门课程的成绩,0,100区间的数组
//输入正整数<=10, 学号,姓名,成绩1,成绩2成绩三, 中间用空格间隔
//输出总分最高的学生的姓名,学号和总分

