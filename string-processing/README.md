# String Processing

This project implements various string processing algorithms. The algorithms included are:

- **KMP**
- **KMP Reversed**

They are implemented using a custom String class.


## Table of Contents

- [Installation](#installation)
- [String Processing Algorithms](#string-processing-algorithms)


## Installation

To compile and run the code, ensure you have a C++ compiler (like g++) installed on your system. Clone this repository and navigate to the project directory:

```bash
git clone https://github.com/despacitokiller5369/mig_prog_zadaci.git
cd mig_prog_zadaci/string-processing
mkdir build
cd build
cmake ..
cmake --build .
```

## String Processing Algorithms

This project contains a custom implementation of a String class in C++, featuring fundamental operations and specialized substring searching methods using the Knuth-Morris-Pratt (KMP) algorithm.

### String Class
The String class provides functionality for:

- Basic string construction, assignment, and memory management.
- Overloaded operators for ease of use, including indexing and output.
- Advanced substring searching methods using the KMP algorithm, allowing for efficient pattern matching.

### KMP-based Substring Searching:

- **findAllSubStr:** Finds all occurrences of a substring in the String.
- **findFirstSubStr:** Finds the first occurrence of a substring.
- **findLastSubStr:** Finds the last occurrence of a substring.
- **findAllSubStrReverse:** Finds all occurrences of a substring in reverse order.
