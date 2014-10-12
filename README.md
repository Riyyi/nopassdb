# nopassdb
nopassdb is a program that hashes passwords for you without a database.

## Requirements before executing

- Library installed: gcc, glibc

## How to get it

- Get the script: `git clone git://github.com/Riyyi/nopassdb`
- Change the text `[ENTER YOUR SALT HERE]` in main.cpp to your desired salt.
- (Optional) change the default output password length in the `int length` variable
- Compile the program:<br /> `g++ [PATH]/nopassdb/src/main.cpp -std=c++0x -lcrypt` 

## How to use

- (Optional) add an alias to your `.bashrc` (in your home directory) to run it quicker: <br />`alias nopassdb='[FULL PATH]'` and then reloading your .bashrc once `. ~/.bashrc`
- To run: `cd [PATH] && ./nopassdb` or simply: `nopassdb` if you setup an alias
- The default returned password length is 20 characters if you want less/more characters run the program with a number behind it.
For example: `nopassdb 12` or `nopassdb 40`

## Extras

In case you want a less strong hashed password (for whatever reason) or less maximum password length,
you can change the hashing algoritm.<br />
You need to change this before compiling the program by changing the number in the salt variable `$6$[YOUR SALT]$`.

              ID  | Method
              ─────────────────────────────────────────────────────────
              1   | MD5
              2a  | Blowfish (not in mainline glibc; added in some
                  | Linux distributions)
              5   | SHA-256 (since glibc 2.7)
              6   | SHA-512 (since glibc 2.7)
              
              MD5     | maximum 22 characters
              SHA-256 | maximum 43 characters
              SHA-512 | maximum 86 characters
