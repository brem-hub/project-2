#!/bin/bash

random_size=10000

for ((iteration=1; iteration < 10; iteration++))
do
    ./bin/project_cpp -r $random_size -o /dev/null
    echo '-----------------------------'
done
