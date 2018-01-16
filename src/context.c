#include <callable/context.h>

/* Macros ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */



/* Private Functions –––––––––––––––––––––––––––––––––––––––––––––––––––––––– */

static bool_t
  priority_insert_handler(s_list_item_t const *item,
                          s_list_item_t const *compare_to);


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
  s_list__insert_ordered(&ctx->_super, &callable->_super,
                         priority_insert_handler);
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

bool_t
priority_insert_handler(s_list_item_t const *item,
                        s_list_item_t const *compare_to)
{
  return ((callable_t *) item)->priority > ((callable_t *) compare_to)->priority;
}