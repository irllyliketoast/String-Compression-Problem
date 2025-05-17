# String Compression – Multi-Language Implementation

This project implements a **string compression algorithm** in multiple languages (Python, Java, C++, Prolog, and SML) while connecting the solution to **theory in formal languages** such as context-free grammars (CFGs), regular expressions, and nondeterministic finite state machines (NDFSMs).

---

## Why Practice This?

* **String traversal & manipulation**
* **Memory and performance optimization**
* **Pattern recognition with automation (FSMs, CFGs)**
* **Cross-paradigm thinking** (imperative, functional, logical programming)
* **Recursive vs iterative logic construction**

---

## Context-Free Grammar (CFG)

This CFG describes the structure of a valid compressed string (e.g., `a3b2c1`):

```
S → C S | C
C → L D
L → a | b | c | ... | z | A | B | ... | Z
D → D D | N
N → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
```

* `S`: A full compressed string
* `C`: A single letter-count unit
* `L`: A valid letter
* `D`: One or more digits
* `N`: Single digits used to build counts

---

## Nondeterministic Finite State Machine (NDFSM)

I defined a simple NDFSM to recognize strings of the form `[a-zA-Z][0-9]+` repeated one or more times.

**States**:

* `q0`: Start
* `q1`: Read a letter `[a-zA-Z]`
* `q2`: Read one or more digits `[0-9]`

**Transitions**:

```
q0 --[a-zA-Z]--> q1  
q1 --[0-9]--> q2  
q2 --[0-9]--> q2  
q2 --[a-zA-Z]--> q1 (repeats for next char group)
```

**Accepting State**: `q2`

---

## Tech Stack:

### ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=flat-square\&logo=c%2B%2B\&logoColor=white)

**Paradigm**: Imperative, Object-Oriented, Low-Level Memory Access

**Why this implementation**: C++ is performance-focused and gives you full control over memory. The string compression function is implemented using a **manual loop and string building** with `+=`, which mimics how memory is appended. It uses `std::string`, but unlike higher-level languages, **no garbage collection or built-in dynamic typing** helps with string management—so care is taken with efficiency and data structures.

**Best for**: Performance-critical applications, embedded systems, systems programming.

---

### ![Java](https://img.shields.io/badge/java-%23ED8B00.svg?style=flat-square\&logo=openjdk\&logoColor=white)

**Paradigm**: Object-Oriented, Imperative, Platform-Independent

**Why this implementation**: Java emphasizes **object-oriented structure**, even for small utilities. We use a **class-based static method** and a **mutable StringBuilder**, which is idiomatic for string manipulation in Java to avoid performance issues with `+` concatenation. Java’s verbosity encourages wrapping utilities in reusable classes, and type safety ensures method robustness.

**Best for**: Enterprise apps, Android development, cross-platform systems with strong type safety.

---

### ![](https://img.shields.io/badge/Prolog-%230f548c?style=flat-square\&logo=prolog\&logoColor=white)

**Paradigm**: Declarative, Logic-Based

**Why this implementation**: Prolog doesn't loop in the traditional sense—it **recursively declares logical rules** that describe relationships. The implementation is centered around **pattern matching and unification**, building results by recursively traversing the input and appending `(Char, Count)` pairs. It’s a great showcase of **declarative programming**: instead of "how to compress", we describe **what compression is**.

**Best for**: Knowledge representation, symbolic AI, rule-based logic systems.

---

### ![](https://img.shields.io/badge/SML-%23a10224?style=flat-square\&logo=sml\&logoColor=white)

**Paradigm**: Functional, Strongly Typed

**Why this implementation**:SML (Standard ML) embraces **immutability** and **recursion**. The implementation is a textbook example of **tail-recursive accumulation**, passing along an updated count and result list. SML’s use of **pattern matching** allows concise decomposition of the list (`x::xs`) and conditional branching with no side effects. This aligns with how functional languages encourage expressing computation through **value transformation**, not mutation.

**Best for**: Theoretical computation, type theory, compilers, proof assistants.

---

### ![Python](https://img.shields.io/badge/python-3670A0?style=flat-square\&logo=python\&logoColor=ffdd54)

**Paradigm**: Multi-paradigm (Imperative, Object-Oriented, Functional)

**Why this implementation**:Python prioritizes **readability and brevity**, so the implementation is clean and linear. It uses a for-loop, a simple counter, and a `list` to collect intermediate results.
Python’s dynamic typing and flexible string manipulation make this approach intuitive and fast to write. It’s also easy to adapt to a recursive, functional, or even generator-based style, depending on needs.

**Best for**: Rapid prototyping, scripting, data science, educational examples.

---

### 🧠 Summary Table

| Language   | Paradigm(s)        | Highlights in This Problem                       |
| ---------- | ------------------ | ------------------------------------------------ |
| **C++**    | Imperative, OOP    | Manual string building, efficient memory control |
| **Java**   | OOP, Imperative    | Class-based utility, StringBuilder usage         |
| **Prolog** | Declarative, Logic | Pattern-based rule recursion                     |
| **SML**    | Functional         | Immutability, tail recursion, type safety        |
| **Python** | Multi-paradigm     | Concise, readable, flexible string ops           |

---
