# cplusplus
few reference programs implemented using C++ language
## Steps to compile
### C11 codes
g++  -std=c++11 <infile>.cpp -o <outfile>
### C14 codes
g++  -std=c++14 <infile>.cpp -o <outfile>

## Debugging
### gdb
```
gdb <outfile>
gdb> start
gdb> b myfun #put break points
gdb> run
```
For details please visit https://github.com/tapankumarmishra/tips-and-tricks/blob/master/gdb
### c++ demangle symbol
c++filt <mangled symbol>





