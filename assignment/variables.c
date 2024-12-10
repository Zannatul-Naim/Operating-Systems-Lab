#include <stdio.h>

// Global initialized variable
int global_var = 10;
int x;

void func() {
  // Local initialized variable
  int local_var = 20;

  // Local uninitialized variable
  int uninitialized_var;

  printf("Function: global_var = %d, local_var = %d\n", global_var, local_var);
  printf("Function: uninitialized_var = %d\n", uninitialized_var);
}

int main() {
  // Global uninitialized variable
  int global_uninitialized;

  printf("Main: global_var = %d, global_uninitialized = %d\n", global_var, global_uninitialized);

  func();

  printf("Main: global_var = %d, global_uninitialized = %d\n", global_var, global_uninitialized);

  printf("%d\n", x);
  
  return 0;
}