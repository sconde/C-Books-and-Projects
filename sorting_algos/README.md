# Sorting Algorithms


## Running `dtrace` 

- install `dtrace` from brew `brew install flamegraph`
  
```
sudo dtrace -x ustackframes=100 -n 'profile-97 /pid == $target/ { @[ustack()] = count(); } tick-60s { exit(0); }' -c "./your_executable" -o out.stacks -P
stackcollapse.pl out.stacks > out.folded
flamegraph.pl out.folded > flamegraph.svg 
```