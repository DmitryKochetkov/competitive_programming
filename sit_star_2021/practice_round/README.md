# SIT STAR 2021: Practice Round

Test round was held on 1-7 February 2021. 

My progress:

- [x] Problem A
- [x] Problem B
- [x] Problem C
- [x] Problem D
- [x] Problem E
- [x] Problem F
- [x] Problem G
- [ ] Problem H - TL / WA
- [ ] Problem I
- [ ] Problem J
- [ ] Problem K
- [ ] Problem L

## Problem F: Divisibility Problem

I still don't understand, how to mathematically prove the method I guessed. At the beginning I just tried to use a greedy algorithm (`problemF_greedy.cpp`) to see the answers. For some reason, each next number ends with the digits of the previous one:

- `n = 1: the answer is 2`
- `n = 2: the answer is 12`
- `n = 3: the answer is 112`
- `n = 4: the answer is 2112`
- `n = 5: the answer is 22112`
- `n = 6: the answer is 122112`
- and so on

So basically my solution is just to recursively find solution for each `n` by choosing a new digit to add at the beginning of the answer for `n-1`.

The thing is I don't know how to prove this fact. Maybe, using induction?

There is one more idea, which is bugging me: amount of numbers with n digits, which are 1 or 2, is `2^n`.
