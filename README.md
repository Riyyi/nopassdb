nopassdb
========

This program hashes passwords for you without no database.

/*
g++ Documents/C++/Lesson2/main.cpp -std=c++0x -lcrypt

ID  | Method
              ─────────────────────────────────────────────────────────
              1   | MD5
              2a  | Blowfish (not in mainline glibc; added in some
                  | Linux distributions)
              5   | SHA-256 (since glibc 2.7)
              6   | SHA-512 (since glibc 2.7)

          MD5     | 22 characters
          SHA-256 | 43 characters
          SHA-512 | 86 characters

depends=(glibc)
*/
