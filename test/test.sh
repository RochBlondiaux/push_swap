ARGS="$(cat test.txt)"
./../push_swap $ARGS | ./../checker_Mac $ARGS
./../push_swap $ARGS | wc -l
