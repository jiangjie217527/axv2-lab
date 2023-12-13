#!/bin/bash

echo $1"运行10次"
for i in {1..10};
do
	./$1
done
