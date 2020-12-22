# Discrete knapsack problem
![](https://github.com/madamskip1/-AAL-Discrete-Knapsack-Problem/workflows/build/badge.svg)

## Build & run
```
mkdir build
cd build
cmake ..
make
```
```
./main [mode] [algorithm]
```
```
[mode]
    -m1   manual
    -m2   automated
    -m3   benchmark
[algorithm]
    -a1   naive
    -a2   optimal
```

### Manual input stream
```
numItems capacity maxDuplicates
volume1 value1
...
volumeN valueN
```

### Automated input stream
```
numItems capacity maxDuplicates binominalParameter
```

### Benchmark input stream
No input necessary.
