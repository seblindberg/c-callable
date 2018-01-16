#ifndef CONTEXT_H
#define CONTEXT_H 1

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <list/s_list.h>
#include <callable/callable.h>


/* Constants -------------------------------------+-------------------------- */




/* Data Types --------------------------------------------------------------- */

typedef struct {
  s_list_t _super;
} context_t;


/* Global Variables --------------------------------------------------------- */




/* Public Functions --------------------------------------------------------- */

void
  context__ctor(context_t *ctx)
  NONNULL;
  
void
  context__schedule(context_t *ctx, callable_t *callable)
  NONNULL;

void
  context__spin_once(context_t *ctx)
  NONNULL;

/* Macros ----------------------------------------+--------+----------------- */




/* Inline Function Definitions ---------------------------------------------- */



#endif /* CONTEXT_H */