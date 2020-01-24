#!/bin/bash

sumcalc () { 
  local sum=0 sred=0 i
  for i in $@
  do
    sum=$(($sum+$i))
  done
  sred=$(($sum/$#))
  echo $sred 
}


stroki () {
  echo ${1//$2/$3}
}


lscpp () {
  ls {*.h,*.cpp,*.hpp,*.cxx,*.hxx} 2>/dev/null
}



