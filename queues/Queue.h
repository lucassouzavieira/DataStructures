/*
 * Copyright (C) 2016  Lucas S. Vieira
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


#ifndef QUEUE_H
#define QUEUE_H

#include "../Types.h"

queue queue_create();

int queue_check(queue *myQueue);

void queue_enqueue(queue *myQueue, long int element);

void queue_dequeue(queue *myQueue);

void queue_print(queue *myQueue);

int queue_destroy(queue *myQueue);

#endif /* !QUEUE_H */