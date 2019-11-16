#!/usr/bin/env bash
for std in c89 c99 c11 c17 gnu89 gnu99 gnu11 gnu17; do
  echo $std
  gcc -std=$std -o CVersion.out CVersion.c
  ./CVersion.out
  echo
done
echo default
gcc -o CVersion.out CVersion.c
./CVersion.out