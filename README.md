# cpp-dynamic-memory-structs

A C++ project demonstrating dynamic memory management using structs and raw pointers.

## Overview

This project implements a `Person` struct and showcases memory allocation patterns at multiple levels:

- **Single pointer** — creating and managing a single `Person`
- **Pointer array** — dynamically allocated array of `Person*`
- **2D pointer array** — array of arrays ("book of people"), using `Person***`

Each level includes proper `new`/`delete` cleanup to avoid memory leaks.

## Build

Open `cpp-dynamic-memory-structs.slnx` in Visual Studio 2022+ and build with **x64 Debug**.

## License

[MIT](LICENSE)
