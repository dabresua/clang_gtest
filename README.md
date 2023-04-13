# Introduction

Example of clang coverage with gtest suite

# Steps

Build the project

```bash
mkdir build
cd build
cmake ..
make
```

Run the tests

```bash
./coverage_test
```

Raw profiles have to be indexed before they can be used to generate coverage reports. This is done using the “merge” tool in llvm-profdata (which can combine multiple raw profiles and index them at the same time):

```bash
llvm-profdata merge -sparse default.profraw -o default.profdata
```

Show the coverage report

```bash
llvm-cov report ./coverage_test -instr-profile=default.profdata --ignore-filename-regex=_deps/*
```

[Optional] Show the line report

```bash
llvm-cov show ./coverage_test -instr-profile=default.profdata --ignore-filename-regex=_deps/*
```
