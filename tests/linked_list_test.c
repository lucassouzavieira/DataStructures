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
 * linked_list.h UNIT TESTS
 */

#include <stdlib.h>

#include <util.h>
#include <types.h>
#include <acutest.h>
#include <linked_list.h>

void test_create_linked_list(void) {
    list* ptr = create_linked_list();

    TEST_CHECK(ptr != NULL);
    TEST_CHECK(ptr->list == NULL);
    TEST_CHECK(ptr->last == NULL);
    TEST_CHECK(ptr->nodes == 0);
}

/*
 * Tests list
 */
TEST_LIST = {
        {"test_create_linked_list", test_create_linked_list},
        {0}
};