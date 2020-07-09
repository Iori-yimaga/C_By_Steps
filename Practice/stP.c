//
// Created by jokermss on 2020/7/7.
//

#include<stdio.h>
struct Student{
    char name[10];
    char sex;
    int age;
};

//void print(struct Student stu[]){
//    for(int i = 0;i < 3;i++){
//        printf("%s %c %d\n", stu[i].name,stu[i].sex,stu[i].age);
//    }
//}

void print(struct Student *stu){
    int i = 0;
    while(i<3){
        printf("%d\n", (stu++)->age);
        i++;
    }
}

int main(){
    struct Student stu[5]={
            {"张三",'m',20},
            {"李四",'m',19},
            {"王五",'f',21}
    };
    print(stu);
    return 0;
}