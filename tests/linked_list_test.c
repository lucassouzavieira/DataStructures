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
    list *ptr = create_linked_list();

    TEST_CHECK(ptr != NULL);
    TEST_CHECK(ptr->list == NULL);
    TEST_CHECK(ptr->last == NULL);
    TEST_CHECK(ptr->nodes == 0);
}

void test_is_empty_linked_list(void) {
    list *ptr = create_linked_list();

    TEST_CHECK(is_empty_linked_list(ptr));

    node *elem = init(elem);

    insert_linked_list(ptr, elem);

    TEST_CHECK(!is_empty_linked_list(ptr));
}

void test_insert_linked_list(void) {
    list *ptr = create_linked_list();
    node *elem = init(elem);

    TEST_CHECK(ptr->nodes == 0);
    TEST_CHECK(ptr->list == NULL);
    TEST_CHECK(ptr->last == NULL);

    insert_linked_list(ptr, elem);

    TEST_CHECK(ptr->nodes == 1);
    TEST_CHECK(ptr->list != NULL);
    TEST_CHECK(ptr->last != NULL);

    // With one element list his head is equals his tail
    TEST_CHECK(ptr->list == ptr->last);

    node *snd_node = init(snd_node);
    insert_linked_list(ptr, snd_node);

    TEST_CHECK(ptr->nodes == 2);
    TEST_CHECK(ptr->list != NULL);
    TEST_CHECK(ptr->last != NULL);

    // With more than one element list his head is not equals his tail
    TEST_CHECK(ptr->list != ptr->last);
}

/*
 * Tests list
 */
TEST_LIST = {
        {"test_create_linked_list",   test_create_linked_list},
        {"test_insert_linked_list",   test_insert_linked_list},
        {"test_is_empty_linked_list", test_is_empty_linked_list},
        {0}
};