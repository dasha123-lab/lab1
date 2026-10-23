#include<stdio.h>
void printBinary(int a) {
  if (a==0) {
    return;
  }
  printf("иттерация с числом %d\n", a);
  printBinary(a / 2);
  printf("%d", a % 2);
}
int main(){
  int a;
  printf("Введите число ");
  scanf("%i", &a);
   if (a<=0){
     printf("Число должно быть неотрицательным");
       return 1;
   }
  printf("Двоичное представление: ");
  printBinary(a);
  return 0;
} 
