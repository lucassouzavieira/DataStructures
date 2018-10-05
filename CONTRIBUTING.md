## How to contribute

* Fork this repository
* Clone your fork
* Add this repository as second remote to your own with this command:  
 `git remote add upstream https://github.com/lucassouzavieira/DataStructures.git`
* Check our open issues or open a new if you find a trouble
* Open a Pull Request to integrate your contribution

and also, we recommend reading the following article: [Contributing to open source](https://opensource.guide/how-to-contribute/)

### Coding requirements and conventions

* Variables and function names:
    *  Always use lowercase and with an underscore as a word separator
* For a given data structure (eg. linked lists), append the name of structure at end of name function. If the data structure has an very common abbreviation, you can use the abbreviation:
    * `create_linked_list` to linked list
    * `create_bst` to binary search trees
* Use always C code. Check if your code attends the [C11 standard](http://www.iso-9899.info/wiki/The_Standard#C11).
* If possible, adds the copyright information at the top of the new files.
* Unitary tests are welcome. Please, add the unit tests for your implementations. This repository uses [acutest](http://github.com/mity/acutest) for unitary tests.
