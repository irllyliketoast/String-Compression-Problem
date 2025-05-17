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

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=flat-square\&logo=c%2B%2B\&logoColor=white)
![Java](https://img.shields.io/badge/java-%23ED8B00.svg?style=flat-square\&logo=openjdk\&logoColor=white)
![](https://img.shields.io/badge/Prolog-%230f548c?style=flat-square\&logo=prolog\&logoColor=white)
![](https://img.shields.io/badge/SML-%23a10224?style=flat-square\&logo=sml\&logoColor=white)
![Python](https://img.shields.io/badge/python-3670A0?style=flat-square\&logo=python\&logoColor=ffdd54)


---

---
