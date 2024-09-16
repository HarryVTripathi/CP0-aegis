
### How C++ Works

 - Header files do not get compiled at all. Just CPP files. Header files get included via a preprocessor statement called `include` into a CPP file and that's when they get compiled.

 - CPP files get compiled individually. Every CPP file will get compiled into an object file. The extension is `.obj` for VSCode's(Microsoft C++) compiler.

 - Once we have all of those individual `obj` files, we need some way to stitch them together. That's where *Linker* comes in. Linker takes all of those obj files and glues them together in to an `exe` file.


### How the C++ Compiler Works

 - In going from text file to executable binary, we have two main operations - Compiling and Linking.

 - Compiler does several things when it produces *object* files.

 - Firstly it pre-processes . Any pre-process statements get evaluated then and there.

 - Then it tokenises and parses to create an Abstract Syntax Tree representation of the code.

 - `#include`: We specify which file we want to include. The preprocessor reads all the content of that file and pastes it into the file where `include` statement is written.

