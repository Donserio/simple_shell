#!/bin/bash

for file in test_scripts_$1/*
do
echo -e "####### Check: $file #######\n"
 checker/checker.bash ./hsh  "$file"
 echo -e "\n" 
done
