
executable=$1

mkdir -p test_results
rm -rf *.o
gcc -c test/test_list.c list.c
gcc -o test_results/$1 *.o
test_results/$1
rm -rf *.o