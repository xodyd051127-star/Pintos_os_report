#ifndef THREADS_PALLOC_H
#define THREADS_PALLOC_H

#include <stddef.h>

/* How to allocate pages. */
enum palloc_flags
{
    PAL_ASSERT = 001, /* Panic on failure. */
    PAL_ZERO = 002,   /* Zero page contents. */
    PAL_USER = 004    /* User page. */
};

/* [프로젝트 2: 메모리 할당] 추가 시작 */

/* Contiguous allocation mode selector */
enum palloc_mode
{
    PAL_FIRST_FIT, // 기본 제공 (bitmap_scan을 사용)
    PAL_NEXT_FIT,  // Next Fit 할당 기법 (bitmap_scan을 시작 인덱스부터 사용)
    PAL_BEST_FIT,  // Best Fit 할당 기법 (bitmap_scan_best_fit을 사용)
    PAL_BUDDY      // Buddy System 할당 기법 (별도의 리스트를 사용)
};

void palloc_set_mode (enum palloc_mode);

/* [프로젝트 2: 메모리 할당] 추가 끝 */


void palloc_init (size_t user_page_limit);
void *palloc_get_page (enum palloc_flags);
void *palloc_get_multiple (enum palloc_flags, size_t page_cnt);
void palloc_free_page (void *);
void palloc_free_multiple (void *, size_t page_cnt);

#endif /* threads/palloc.h */
