#include <stdlib.h>

#include "minunit.h"
#include "matrix.h"

int tests_run = 0;

char* test_alloc(){
  Matrix result = make_matrix();
  mu_assert("Matrix not allocated.", result != NULL);
  return 0;
}
 
char* test_add(){
  Matrix first = make_matrix();
  Matrix second = make_matrix();

  first[0][0] = 10;
  second[0][0] = 15;
  
  Matrix result = add_mat(first, second);

  mu_assert("Adding matrices incorrect", result[0][0] == 25);
  return 0;
}

//char* test_mult(){

char* all_tests(){
  mu_run_test(test_alloc);
  mu_run_test(test_add);
  return 0;
}

int main(){
  char* result = all_tests();
  if(result != 0){
    printf("%s\n", result);
  }else{
    printf("All tests passed\n");
  }
  printf("%d tests run.\n", tests_run);
  return result != 0;
}
