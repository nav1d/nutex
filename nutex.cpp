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

#include <nutex.h>

static thread_iden _nutex[NUTEX_MAX_MUTEX] = { 0 };

void nutex_check(int index_)
{
	thread_iden tid = _nutex_getThreadID();
	thread_iden *mutex = &_nutex[index_];

	if (!*mutex)
	{
		*mutex = tid;
		return;
	}

	if (*mutex == tid)
	{
		*mutex = tid;
		return;
	}
	else
	{
		while (1)
		{
			if ((!*mutex) || (*mutex == tid))
			{
				*mutex = tid;
				return;
			}
#if defined(__linux__) || defined(__unix__)
			usleep(1);
#endif
#if defined(_WIN32) || defined(_WIN64)
			Sleep(1);
#endif
		}
	}
}

void nutex_uncheck(int index_)
{
	thread_iden tid = _nutex_getThreadID();
	thread_iden *mutex = &_nutex[index_];

	if (*mutex == tid)
		*mutex = 0;

	return;
}

thread_iden _nutex_getThreadID()
{
#ifdef _WIN32
	return (thread_iden)GetCurrentThreadId();
#endif

#if defined(__linux__) || defined(__unix__)
	return (thread_iden)syscall(SYS_gettid);
#endif
}

