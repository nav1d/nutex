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
#include <stdlib.h>
#include <stdio.h>

static int sample_value;
int my_nutex_id = 16;

int callx(void *ptr)
{
	nutex_check(my_nutex_id);

#if defined(_WIN32)
	printf("tid : %d, print value: %d\n", GetCurrentThreadId(), sample_value);
#endif
	sample_value++;
	nutex_uncheck(my_nutex_id);
	return 0;
}

int main()
{
#if defined(_WIN32)
	HANDLE o;
	for (int i = 0; i < 1000; i++)
	{
		o = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)callx, NULL, 0, NULL);
		if (o)
			CloseHandle(o);
	}
#endif

	system("pause");
	return 0;
}
