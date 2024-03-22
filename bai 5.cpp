#include<stdio.h>
int main()
{
  int n;
  long S = 0;
  printf("\nNhap vao n: ");
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    S = S + i * i;
  }
  printf("\nTong 1^2 + 2^2 + ... + %d^2 là: %ld", n, S);
 
  printf("\n-------------------------------------\n");

}
 
 

