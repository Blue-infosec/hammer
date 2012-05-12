#ifndef HAMMER_ALLOCATOR__H__
#define HAMMER_ALLOCATOR__H__
#include <sys/types.h>

typedef struct arena* arena_t; // hidden implementation

arena_t new_arena(size_t block_size); // pass 0 for default...
void* arena_malloc(arena_t arena, size_t count) __attribute__(( malloc, alloc_size(2) ));
void delete_arena(arena_t arena);

typedef struct {
  size_t used;
  size_t wasted;
} arena_stats_t;

void allocator_stats(arena_t arena, arena_stats_t *stats);


#endif // #ifndef LIB_ALLOCATOR__H__
