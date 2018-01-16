#include <callable/callable.h>

/* Macros ------------------------------------------------------------------- */



/* Private Functions -------------------------------------------------------- */




/* Global Variables --------------------------------------------------------- */




/* Function Definitions ----------------------------------------------------- */

void
callable__ctor(callable_t *callable, callable__callback_t callback)
{
  s_list_item__ctor(&callable->_super);
  
  callable->callback = callback;
  callable->priority = 0;
}

