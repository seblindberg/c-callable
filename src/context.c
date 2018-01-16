#include <callable/context.h>

/* Macros ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */



/* Private Functions –––––––––––––––––––––––––––––––––––––––––––––––––––––––– */




/* Global Variables ––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */




/* Function Definitions ––––––––––––––––––––––––––––––––––––––––––––––––––––– */

void
context__ctor(context_t *ctx)
{
  s_list__ctor(&ctx->_super);
}

void
context__run(context_t *ctx, callable_t *callable)
{
  s_list__push(&ctx->_super, &callable->_super);
}

void
context__spin_once(context_t *ctx)
{
  callable_t *callable;
  
  callable = (callable_t *) s_list__shift(&ctx->_super);
  
  if (callable == NULL) {
    return;
  }
  
  callable__call(callable);
}