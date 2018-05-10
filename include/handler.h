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
#include <signal.h>

/**
 * Default handler for all SIG errors
 *
 * @param signal
 */
void default_handler(int signal);

/**
 * Called before main
 *
 * Defines errors to be handled
 */
void __attribute__((constructor)) initialize();

#ifdef __cplusplus
};
#endif

#endif //DS_HANDLER.H