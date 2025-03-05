## Todo-list

A simple terminal-based todo-list written in modern C++23

## Features 📃:

- Add new tasks
- Mark tasks as completed
- Remove tasks
- View all tasks
- Persistent storage in a text file

## Requirements 📌:

- C++23 compatible compiler
- CMake 3.15 or higher

## Installing/Building 📁:

1. Clone the repo:
```bash
git clone https://github.com/Hkmori15/todo-list.git
```
2. Create and move to build directory:
```bash
mkdir build && cd/z build
```
3. Generate build files:
```bash
cmake ..
```
4. Build the project:
```bash
cmake --build .
```

## Usage ☕:

Run the todo-list:
```bash
./todo_list
```

**Available commands** ❗:
- **1** Add task
- **2** Mark task as completed
- **3** Remove task
- **4** Show tasks
- **5** Exit

## File Storage 🔒:

Tasks aru automatically saved to **tasks.txt&** in the following format:
```<completed>;<desc>```

Where completed is 0 (not done) or 1 (done)
