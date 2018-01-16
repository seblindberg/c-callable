#include <compiler.h>
#include <callable/callable.h>
#include "minunit.h"

int tests_run = 0;

int callback_did_run;
void
callable_callback()
{
  callback_did_run = 1;
}

static char *
test_callable()
{
  callable_t callable;
  
  callable__ctor(&callable, callable_callback);
  
  callback_did_run = 0;
  callable__call(&callable);
  mu_assert("The callback should have run",
            callback_did_run);
  
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