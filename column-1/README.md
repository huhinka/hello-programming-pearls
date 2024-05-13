# Column 1

## My Machine

- MacBook Pro (14-inch, 2023)
- Apple M2 Pro
- 16 GB

## Run

Generate input set `phone-numbers.txt`.

```shell
gcc -o input-set-generator ./input-set/generator.c
./input-set-generator
```

Sort phone numbers by using bitmap sort.

```shell
gcc -o sort-by-bitmap main.c bitmap.c sort-by-bitmap.c
./sort-by-bitmap phone-numbers.txt sorted.txt
# Time taken: 0.138566 seconds
```

Sort by stdlib function `qsort`.

```shell
gcc -o sort-by-stdlib main.c sort-by-stdlib.c
./sort-by-stdlib phone-numbers.txt sorted.txt
# Time taken: 0.236909 seconds
```
