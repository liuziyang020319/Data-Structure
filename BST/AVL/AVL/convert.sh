#! /bin/bash

for file in ./tree*.dot
do
    dot -Tpng $file -o $file.png
done