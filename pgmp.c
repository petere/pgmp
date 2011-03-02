/* pgmp -- PostgreSQL GMP module
 *
 * Copyright (C) 2011 Daniele Varrazzo
 *
 * This file is part of the PostgreSQL GMP Module
 *
 * The PostgreSQL GMP Module is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the License,
 * or (at your option) any later version.
 *
 * The PostgreSQL GMP Module is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the PostgreSQL GMP Module.  If not, see
 * http://www.gnu.org/licenses/.
 */

#include "pgmp.h"

#include "fmgr.h"

PG_MODULE_MAGIC;

void    _PG_init(void);
void    _PG_fini(void);

void    *_pgmp_alloc(size_t alloc_size);
void    *_pgmp_realloc(void *ptr, size_t old_size, size_t new_size);
void    _pgmp_free(void *ptr, size_t size);


/*
 * Module initialization and cleanup
 */

void
_PG_init(void)
{
    /* A vow to the gods of the memory allocation */
    mp_set_memory_functions(
        _pgmp_alloc, _pgmp_realloc, _pgmp_free);
}

void
_PG_fini(void)
{
}


/*
 * GMP custom allocation functions using PostgreSQL memory management.
 */

void *
_pgmp_alloc(size_t alloc_size)
{
    return palloc(alloc_size);
}

void *
_pgmp_realloc(void *ptr, size_t old_size, size_t new_size)
{
    return repalloc(ptr, new_size);
}

void
_pgmp_free(void *ptr, size_t size)
{
    pfree(ptr);
}


