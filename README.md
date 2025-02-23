# Simple Shell

## Description
**Simple Shell** is a basic UNIX command-line interpreter written in C. It mimics some of the core functionalities of a typical shell environment, providing users with an interface to execute commands and navigate their system. This project was built as part of the **ALX Software Engineering Program**, focusing on the fundamentals of system programming and process management.

---

## Features
The Simple Shell supports the following functionalities:

### Basic Features
- Display a prompt and wait for user input.
- Execute commands typed by the user.
- Handle simple command lines without advanced features (e.g., pipes, semicolons, redirection).
- Provide error messages for invalid commands.
- Handle the "end of file" condition (`Ctrl+D`) gracefully.

### Extended Features
- Support for commands with arguments (e.g., `ls -l`, `echo Hello`).
- Search and execute commands using the `PATH` environment variable.
- Implement built-in commands:
  - `exit`: Exits the shell.
  - `env`: Displays the current environment variables.

---

## Usage
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/your-username/simple_shell.git
   
2. Navigate to the project directory:
    cd simple_shell

3.Compile the source code:
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell

4. Run the shell:
    ./simple_shell

---

## Authors:
    Nadjib Mouhoun

