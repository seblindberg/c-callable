#include <compiler.h>
#include <callable/callable.h>
#include "minunit.h"

int tests_run = 0;

static char *
test_callable()
{
  return NULL;
}

static char *
all_tests()
{
  mu_run_test(test_callable);
  return NULL;
}

int
main(int argc, char *argv[])
{
  char *result = all_tests();
  
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}