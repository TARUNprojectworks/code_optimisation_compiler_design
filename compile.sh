#!/bin/bash
SRCDIR='/c/Users/TARUN/Desktop/Code Optimization/src'
EXEDIR='/c/Users/TARUN/Desktop/Code Optimization/exe'
COUNT=0
FAIL=0
for f in cf dce cse cp licm ivsr inline loop simd alias; do
  for o in O0 O1 O2 O3 Os; do
    gcc -$o -o "$EXEDIR/${f}_${o}.exe" "$SRCDIR/${f}.c" 2>&1
    if [ $? -eq 0 ]; then
      COUNT=$((COUNT+1))
    else
      echo "FAIL: $f $o"
      FAIL=$((FAIL+1))
    fi
  done
done
echo "Compiled $COUNT executables, $FAIL failures"
