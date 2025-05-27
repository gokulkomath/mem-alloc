
## Memory allocation without using malloc()
# 🧠 Memory Allocation Without Using `malloc()`

This program demonstrates how to manually manage memory allocation by reserving **1 GB of memory** and allocating **4-byte words** based on user input — **without using `malloc()`**.

## 📦 Features

- Reserves **1 GB** of memory at program startup.
- Allocates memory in **4-byte words** (suitable for `int` values).
- Completely avoids dynamic allocation via `malloc()`.
- Uses custom functions provided in `Birchutils.zip`.

## 🛠 Requirements

- gcc compiler
- Extract and include the utilities from `Birchutils.zip`

## 📁 Files

- `alloc.c` – Contains the core logic for manual memory allocation.
- `Birchutils.zip` – Archive containing utility libraries required for compilation.

## How to run

`make clean`

`make`

`./alloc`



