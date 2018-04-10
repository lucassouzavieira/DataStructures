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
#include <types.h>
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

void test_new_node(void) {
    test_struct_ *ptr = init(ptr);
    ptr->key = 5.2;
    ptr->value = 10;

    node* nodeptr = new_node(ptr, NULL);

    TEST_CHECK(nodeptr != NULL);

    // Check values
    test_struct_ *fromNode = (test_struct_*) nodeptr->data;

    double nodeKey = fromNode->key;
    long int nodeValue = fromNode->value;

    TEST_CHECK(ptr->key == nodeKey);
    TEST_CHECK(ptr->value == nodeValue);

    // Pointer
    TEST_CHECK(nodeptr->pointer == NULL);
}

/*
 * Tests list
 */
TEST_LIST = {
        {"test_init", test_init},
        {"test_new_node", test_new_node},
        {0}
};