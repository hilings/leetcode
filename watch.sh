#!/bin/bash
# usage: watch.sh $1 $2

INTERVAL=${3:-3}

while :; do 
  clear
  date
  $1 $2
  sleep $INTERVAL
done
