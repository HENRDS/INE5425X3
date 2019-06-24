# X3

Implementation of a Pseudo random number generator that generates variates following:
- An uniform distribution
- An exponential distribution
- An erlang distribution
- A normal distribution
- A gamma distribution
- A beta distribution
- A weibull distribution
- A logNormal distribution
- A triangular distribution
- A discrete probability distribution

## Quickstart
To compile the program just run the [compile script](compile.sh). It will compile the executable `INE5425` to the `bin`
folder.



## Why use PRNG instead of TRNG?

A great advantage of PRNGs (Pseudo Random Number Generators) over TRNGs (True Random Number Generators) is that you can reproduce the same sequence of numbers in another time by simply knowing the starting point of the sequence (also known as the seed) - thus it is also periodic and the sequence will repeat itself in due time. 

You can be sure that the sequence of numbers produced by a Pseudo-RNG, though periodic, the time to reproduce the same sequence will eventually take a really long time that unless you acquire the actual algorithms, the correct sequence will be very difficult (almost impossible) to crack.

## Why use XOR-Shift instead of LCG?

In some cases it is useful to use fewer operations and still achieve an acceptable degree of randomness. To do this, we need to find a small combination of bitwise operations that meet certain randomness criteria and pass certain statistical tests. One solution proposed by George Marsaglia is in the form of Xorshift. 

In Xorshift the resulting numbers can be considered equally random, that is, their randomness is independent of their position. Marsaglia showed that a generator involving three shifts and three XOR operations satisfy various statistical tests of randomness (including ones that poorer generators such as LCGs fail).






This project is avaliable on [Github](https://github.com/HENRDS/INE5425X3).