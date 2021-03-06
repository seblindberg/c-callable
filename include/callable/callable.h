#ifndef CALLABLE_H
#define CALLABLE_H 1

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <list/s_list_item.h>

/* Constants -------------------------------------+-------------------------- */




/* Data Types --------------------------------------------------------------- */

typedef struct callable callable_t;
typedef void (*callable__callback_t)(callable_t *callable);

struct callable {
  s_list_item_t        _super;
  callable__callback_t  callback;
};


/* Macros ----------------------------------------+--------+----------------- */




/* Global Variables --------------------------------------------------------- */




/* Public Functions ---------+----------------------------------------------- */

void
  callable__ctor(callable_t *callable, callable__callback_t callback)
  NONNULL;

static inline void
  callable__call(callable_t *callable)
  NONNULL;


/* Inline Function Definitions ---------------------------------------------- */

void
callable__call(callable_t *callable)
{
  callable->callback(callable);
}


#endif /* CALLABLE_H */