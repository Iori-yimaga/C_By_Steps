#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int TenNum(char a[], int B){
  int len, i, num;
  int sum = 0;
  len = strlen(a);
  for(i = 0; i < len; i++){
    if(a[i] >= '0' && a[i] <= '9'){
      num = a[i] - '0';
    }
    else if (a[i] >= 'A' && a[i] <='F'){
      num = a[i] - 'A' + 10;10
    }
    sum = sum * B + num;
  }
  return sum;
}

void NumChange(int m, int b){
  int n;
  if(m){
    NumChange(m / b, b);
    n = m % b;
    if(n < 10){
      printf("%d", n);
    }else{
      printf("%c", n + 55);
    }
  }
}

int main(){
  int B, b;
  char a[20];
  printf("请输入待转换的数制(2-16): >");
  do{
    scanf("%d", &B);
  }while(B < 2 || B > 16);
  printf("请输入待转换的数字: >");
  getchar();
  gets(a);
  int m = TenNum(a, B);
  printf("请输入需要转换的进制(2-16): >");
  do{
    scanf("%d", &b);
  }while(b < 2 || b > 16);
  printf("%d进制数%s转换为%d进制数的结果为:", B, a, b);
  NumChange(m, b);
  printf("\n");
  //system("PAUSE");
  return 0;
}
