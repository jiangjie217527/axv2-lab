#!/bin/bash

echo $1"运行10次" >> res.txt
for i in {1..10};
do
	./bin/$1 >> res.txt
done
