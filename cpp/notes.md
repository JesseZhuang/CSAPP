## compile cpp on mac

```shell
 g++ --version
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: x86_64-apple-darwin21.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

```shell
g++ ./hello.o ./hello.cpp
# or make hello
$ ./hello.o jt1
hello world!
arg count: 2
args: ./hello.o, jt1
```