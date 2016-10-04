/*
// NUTEX //
////////////////
// NATIVE
// ULTRA
// TINY
// EFFICIENT
// X
*/

/*
*    Name: NUTEX
*    Version: 1.0
*    Desc: A cross-platform mutex handler
*    Author: Navid R. Nazari
*
*    Copyright (C) 2015,	Navid R. Nazari
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _H_NUTEX_
#define _H_NUTEX_

#if defined(__linux__) || defined(__unix__)
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
typedef pid_t thread_iden;
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
typedef long thread_iden;
#endif

#define NUTEX_MAX_MUTEX 1000

void nutex_check(int index_);
void nutex_uncheck(int index_);
thread_iden _nutex_getThreadID();

#endif