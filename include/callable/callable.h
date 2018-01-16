#ifndef CALLABLE_H
#define CALLABLE_H 1

/* Includes ----------------------------------------------------------------- */

#include <compiler.h>
#include <list/s_list_item.h>

/* Constants -------------------------------------+-------------------------- */




/* Data Types --------------------------------------------------------------- */

typedef void (*callable__callback_t)(void);

typedef struct {
  s_list_item_t        _super;
  callable__callback_t  callback;
  uint8_t               priority;
} callable_t;


/* Macros ----------------------------------------+--------+----------------- */




/* Global Variables --------------------------------------------------------- */




/* Public Functions ---------+----------------------------------------------- */

void
  callable__ctor(callable_t *callable, callable__callback_t callback)
  NONNULL;

static inline void
  callable__call(callable_t *callable)
  NONNULL;
  
static inline void
  callable__set_priority(callable_t *callable, uint8_t priority)
  NONNULL;


/* Inline Function Definitions ---------------------------------------------- */

void
callable__call(callable_t *callable)
{
  callable->callback();
}

void
callable__set_priority(callable_t *callable, uint8_t priority)
{
  callable->priority = priority;
}

#endif /* CALLABLE_H */