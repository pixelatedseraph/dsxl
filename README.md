# dsxl — Data Structure eXtension Library for C

`dsxl` is a lightweight, extensible, STL-style data structure library for C.  
It provides clean APIs, modular headers, and function-table based abstractions that allow you to use linked lists (singly and doubly linked), and other data structures without rewriting boilerplate pointer code.

If you've ever wanted an STL-like interface in pure C, `dsxl` provides exactly that.

---

## Features

- **Object-like APIs** using function tables stored within structs
- **Singly Linked Lists (SLL)**
- **Doubly Linked Lists (DLL)**
- **Full CRUD operations**: create, insert, update, fetch, delete
- **Utility operations**: print, clear, is-empty, contains, locate
- **Variadic linked-list constructor** using a sentinel terminator
- **Clean syntax** using helper macros (e.g., `ListHead(list)`)
- **Modular public header structure** under `include/dsxl/`
- **CMake-based build system**
- **Example programs and unit tests** included

---

## Quick Example

```c
#include <dsxl/LinkedList.h>

int main() {
    LinkedList list = new_List(10, 20, 30, sentinel);
    
    list.PrintList(ListHead(list));
    list.DeleteAtBack(&ListHead(list));
    list.PrintList(ListHead(list));
    list.ClearList(&ListHead(list));
    list.PrintList(ListHead(list));
    
    return 0;
}
```

**Example output:**
```
10 -> 20 -> 30
10 -> 20
(empty)
```

---

## Internal Design

Each data structure (for example, `LinkedList`) contains:
- A pointer to its data (`header`)
- A function table with all available operations

During construction via `new_List`, every method is assigned:

```c
List.CreateNode    = CreateNode;
List.InsertFront   = InsertFront;
List.InsertBack    = InsertBack;
List.Insert        = Insert;
List.DeleteAtIndex = DeleteAtIndex;
List.DeleteAtFront = DeleteAtFront;
List.DeleteAtBack  = DeleteAtBack;
List.GetLength     = GetLength;
List.Locate        = Locate;
List.Contains      = Contains;
List.PrintList     = PrintList;
List.GetValue      = GetValue;
List.SetValue      = SetValue;
List.ClearList     = ClearList;
List.IsEmpty       = IsEmpty;
```

The macro:
```c
#define ListHead(list) (list.header)
```

allows expressive, readable calls such as:
```c
list.PrintList(ListHead(list));
list.DeleteAtBack(&ListHead(list));
```

---

## Building

### Clone

```bash
git clone https://github.com/pixelatedseraph/dsxl.git
cd dsxl
```

### Build with CMake

```bash
mkdir build
cd build
cmake ..
make
```

### Run test

```bash
./dsxl_test
```


---

## Roadmap

-  ArrayList / dynamic array
-  Stack implementation
-  Queue implementation
-  HashMap / hash table
-  Priority queue
-  AVL and Red-Black Trees
-  Generic type containers using `void*`
-  Allocator hooks for custom memory strategies
-  Benchmarking and profiling suite

---

## License

This project is licensed under the **GNU General Public License v3.0 (GPLv3)**.  
See the [LICENSE](LICENSE) file for full terms.

---

## Contributing

Contributions are welcome!

- All submitted code must be compatible with the GPLv3 license.
- Issues, feature requests, and pull requests are encouraged.


## Contact

For questions, suggestions, or feedback, please open an issue on GitHub.

---

**Made with for C developers who miss STL**
