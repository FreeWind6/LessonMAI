#1/bin/bash

output=result.txt
echo '' > $output

#cat list.txt
for file in $(cat list.txt); do
  echo Compiling file $file
  if g++ $file -std=c++11 -lpthread; then
  
   echo Running file $file
   ./a.out
   if (($? == 0)); then
     echo Running $file failed
     echo $(date) - $fale - OK >> $output
   else
     echo Running $file failed
     echo $(date) - $fale - FAIL >> $output
   fi
     else
     echo $(date) - $fale - COMPILE FAILED >> $output
  fi
done
rm -f a.out
