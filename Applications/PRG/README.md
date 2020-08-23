# Pseudo Random Generator using Cellular Automaton

## Introduction

This is the first application case study for the cellular Automaton.
We can use code for Cellular Automaton, to make a PRG, given random initial conditions. We will try to generate a PRG in C++ using [RULE 150](https://mathworld.wolfram.com/Rule150.html).

## Details of implementation


### Initiating
The PRG will generate 100000 PseudoRandom numbers, from each key. The key will be a 64 bit number that will be expanded into 100000 bits, using :

```python3
  while(bit<100000):
    key=(key*prime1 % prime2)
    map(key,bit,bit+63)
    bit+=64
```
Now, code will be using previous 100000 cells to generate next 100000 cells using rule 150.

### Generating Numbers 

Now, we need to generate random numbers. We will traverse from left to right and print each column (64 bits). We have 100000 columns and 64 rows. Thus we will be able to generate 100000 64 bit random numbers.

### Important things to Note

We should note that the key should not be in the initiation, but the first value should be *key x prime1 + prime 2*. This will prevent revealing the key after reading first 64 random numbers. This is crucial as the entire sequence can be duplicated if a person knows the key.

### Space and memory requirements

1. The space requirements are : *O((100000)x(64))*
2. The time complexity is : Precomputation : *O((100000)x(64))*, Access/Generation : *O(1)* 


### Guessing PRG 
The only way to guess a Number is to study its previous and next number along with the current number, and it is not possible to guess the current number if the next number and the current number are inaccesible. Given the previous number, we can predict each of the next bit with 50% probability, no better than a random guess.

Mathematical proof of security of this method is under analysis and will be updated soon.

1. Code : Code is available [here](https://github.com/vs666/CellAutomaton/blob/master/cpp/prg.cpp)
2. Executable : exe file is available [here](https://github.com/vs666/CellAutomaton/blob/master/exe_files/prg)

### Contact

In case of any tips on improving the code/idea, or in general any query or suggestion feel free to raise an issue.
