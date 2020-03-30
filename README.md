# push_swap

For this project I needed sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed I had to manipulate various
types of algorithms and choose the one (of many) most appropriate solution for an
optimized data sorting

# Create push_swap executable
```
$ make push_swap
```

# Create checker executable
```
$ make checker
```

# Create both executables
```
$ make
```

# Run executables
for example:
```
$ ARGV=(-70 -51 55 -31 9); ./push_swap $ARGV | ./checker $ARGV
```

![](.push_swap.gif)
