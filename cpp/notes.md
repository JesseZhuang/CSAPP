## cpp on mac

```shell
 g++ --version
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: x86_64-apple-darwin21.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```
https://code.visualstudio.com/docs/cpp/config-clang-mac

References

1. [about OS X libc++ vs libstdc++](https://stackoverflow.com/questions/19774778/when-is-it-necessary-to-use-the-flag-stdlib-libstdc)
1. https://code.visualstudio.com/docs/cpp/config-clang-mac

## use make with g++

```shell
g++ ./hello.o ./hello.cpp
# or make hello
$ ./hello.o jt1
hello world!
arg count: 2
args: ./hello.o, jt1
```