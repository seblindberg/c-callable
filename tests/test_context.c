#include <compiler.h>
#include <callable/callable.h>
#include <callable/context.h>
#include "minunit.h"

int tests_run = 0;

typedef struct {
  callable_t _super;
  bool_t     did_run;
} test_callable_t;

void
callable_callback(callable_t *callable)
{
  ((test_callable_t *) callable)->did_run = 1;
}

static char *
test_context()
{
  test_callable_t callable_a;
  test_callable_t callable_b;
  context_t  ctx;
  
  callable__ctor(&callable_a._super, callable_callback);
  callable__ctor(&callable_b._super, callable_callback);
    
  context__ctor(&ctx);
  
  context__run(&ctx, &callable_a._super);
  context__run(&ctx, &callable_b._super);
  
  callable_a.did_run = 0;
  callable_b.did_run = 0;
  
  context__spin_once(&ctx);
  
  mu_assert("Only callback a should have run",
            callable_a.did_run && !callable_b.did_run);
            
  context__spin_once(&ctx);
  
  mu_assert("Callback b should have run",
            callable_b.did_run);

  return NULL;
}

static char *
test_priority()
{
  test_callable_t callable_a;
  test_callable_t callable_b;
  context_t  ctx;
  
  callable__ctor(&callable_a._super, callable_callback);
  callable__ctor(&callable_b._super, callable_callback);
  
  callable__set_priority(&callable_a._super, 1);
  callable__set_priority(&callable_b._super, 2);
  
  context__ctor(&ctx);
  
  context__run(&ctx, &callable_a._super);
  context__run(&ctx, &callable_b._super);
  
  callable_a.did_run = 0;
  callable_b.did_run = 0;
  
  context__spin_once(&ctx);
  
  mu_assert("Only callback b should have run",
            callable_b.did_run && !callable_a.did_run);
            
  context__spin_once(&ctx);
  
  mu_assert("Callback a should have run",
            callable_a.did_run);
            
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