 - Make `.o` file:

 ```
 g++ -c hw.cpp
 ```

  This shall create a file named `hw.o` unless output file name is explicitly specified using `-o` flag.

 - From `.o` to executable.

 ```
 g++ -o somename hw.o
 ```

  This shall create an executable file named `somename.exe`.


 - Specify Makefile to make:

 ```
 make -f .\Makefile-v1
 ```

 - Show the preprocesor output
 ```
 g++ -E file.cpp
 ```

 Optionally, we can specify output file with `.i` format to write to.

 ```
  g++ -E -o pre.i ./file.cpp
 ```

 - Save compiler output in assembly language

 ```
 g++ -S ./file.cpp
 ```