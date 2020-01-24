#!/bin/bash

fact(){
 if (($1 < 0)); then
   echo Fail
   return
 elif (($1 == 0 || $1 == 1)); then
   echo 1
   return
 fi
 local result=1
 for ((i=0; i <= $1; i++)); do
  result=$((result*i))
 done
 echo $result
}

fact 5




