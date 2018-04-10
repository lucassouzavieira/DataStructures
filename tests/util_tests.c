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

/*
 * util.h UNIT TESTS
 */

#include <stdlib.h>

#include <util.h>
#include <acutest.h>

typedef struct test_struct_ {
    double key;
    long int value;
} test_struct_;

void test_init(void) {
    test_struct_ *ptr = init(ptr);
    TEST_CHECK(ptr != NULL);

    ptr->key = 4.5;
    ptr->value = 10;

    TEST_CHECK((bool) ptr->key);
    TEST_CHECK((bool) ptr->value);
}

/*
 * Tests list
 */
TEST_LIST = {
        {"init", test_init},
        {0}
};