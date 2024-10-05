## Exceptions

If no appropriate `catch` is found, execution is transferred to a library function named `terminate`.

The `exception` header defines the most general kind of exception class named `exception`. Communicates only that an
exception occurred with no additional info.

The `stdexcept` header defines

- `runtime_error`
- `range_error` runtime error: result generated outside of meaningful range
- `overflow_error`
- `underflow_error`
- `logic_error`
- `domain_error`

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