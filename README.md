# nopassdb
nopassdb is a program that hashes passwords for you without a database.<br />
Because it doesn't use a database, in case you remember the `SALT` nothing can be lost, if your computer ever fails you can just setup this program again.

## Requirements before executing
### Linux:
- Dependencies (1)<br />
xsel (optional) – to copy passwords to clipboard

## How to get it
- Get the script: `git clone git://github.com/Riyyi/nopassdb`
- Change the text `[ENTER YOUR SALT HERE]` in main.cpp to your desired salt.
- (Optional) change the default output password length in the `int length` variable.
- `$ cd` in the `nopassdb` directory.
- Compile the program:
<pre>$ mkdir build
$ cd build
$ cmake .. && make</pre>

## How to use
- (Optional) add an alias to your `.bashrc` (in your home directory) to run it quicker: <br />`alias nopassdb='[FULL PATH]'` and then reloading your .bashrc once `. ~/.bashrc`
- To run: `$ cd [PATH] && ./nopassdb` or simply: `nopassdb` if you setup an alias
- The default returned password length is 20 characters if you want less/more characters, run the program with the flag `-l` followed by a number.<br />
For example: `$ nopassdb -l 12` or `$ nopassdb -l 40`

The maximum password length this program can output is 172 characters.

## Configuration
The configuration file can either be in the same directory as the application, or in the default system config location.
The default output `length` should be on line 1, and the `SALT` should be on line 2.

- Windows<br />
C:\Users\\[USER]\AppData\Roaming\nopassdb\config.txt
- OS X<br />
/Documents/nopassdb/nopassdb.conf
- Linux<br />
/home/[USER]/.config/nopassdb/nopassdb.conf
