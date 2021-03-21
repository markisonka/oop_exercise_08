#!/bin/bash
prog="$1"
echo $prog

"$prog" 3 < test_01.test > tmp_test_file
    
if diff tmp_test_file test_01.result && diff Buffer_1 test_01.buffer1.result ; then
    echo "test $a OK"
else
    echo "test $a NOT OK"
fi
let "a += 1"
rm tmp_test_file
rm Buffer_1
    
