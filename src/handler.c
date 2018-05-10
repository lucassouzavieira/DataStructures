/*
 * Copyright (C) 2018  Lucas S. Vieira
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HANDLER_H
#define HANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>

void default_handler(int signal) {
    void *callstack[256];

    printf("OS Signal %d \n", signal);
    printf("Backtrace: \n");

    int frames = backtrace(callstack, 256);
    char **callstack_strs = backtrace_symbols(callstack, frames);

    for (int i = 0; i < frames; i++) {
        printf("\t %s \n", callstack_strs[i]);
    }

    exit(0);
}

void __attribute__((constructor)) initialize() {
    signal(SIGFPE, default_handler);
    signal(SIGSEGV, default_handler);
    signal(SIGABRT, default_handler);
}

#ifdef __cplusplus
};
#endif

#endif //DS_HANDLER.H