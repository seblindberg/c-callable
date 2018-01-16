#include <compiler.h>
#include <callable/callable.h>
#include <callable/context.h>
#include "minunit.h"

int tests_run = 0;

int callback_a_did_run;
void
callable_callback_a()
{
  callback_a_did_run = 1;
}

int callback_b_did_run;
void
callable_callback_b()
{
  callback_b_did_run = 1;
}

static char *
test_context()
{
  callable_t callable_a;
  callable_t callable_b;
  context_t  ctx;
  
  callable__ctor(&callable_a, callable_callback_a);
  callable__ctor(&callable_b, callable_callback_b);
    
  context__ctor(&ctx);
  
  context__run(&ctx, &callable_a);
  context__run(&ctx, &callable_b);
  
  callback_a_did_run = 0;
  callback_b_did_run = 0;
  
  context__spin_once(&ctx);
  
  mu_assert("Only callback a should have run",
            callback_a_did_run && !callback_b_did_run);
            
  context__spin_once(&ctx);
  
  mu_assert("Callback b should have run",
            callback_b_did_run);

  return NULL;
}

static char *
test_priority()
{
  callable_t callable_a;
  callable_t callable_b;
  context_t  ctx;
  
  callable__ctor(&callable_a, callable_callback_a);
  callable__ctor(&callable_b, callable_callback_b);
  
  callable__set_priority(&callable_a, 1);
  callable__set_priority(&callable_b, 2);
  
  context__ctor(&ctx);
  
  context__run(&ctx, &callable_a);
  context__run(&ctx, &callable_b);
  
  callback_a_did_run = 0;
  callback_b_did_run = 0;
  
  context__spin_once(&ctx);
  
  mu_assert("Only callback b should have run",
            callback_b_did_run && !callback_a_did_run);
            
  context__spin_once(&ctx);
  
  mu_assert("Callback a should have run",
            callback_a_did_run);
            
  return NULL;
}

static char *
all_tests()
{
  mu_run_test(test_context);
  mu_run_test(test_priority);
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