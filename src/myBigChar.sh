#!/bin/bash

echo -e "\033c"

# echo -e "\033[10;5H\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2510"
# echo -e "\033[11;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
# echo -e "\033[12;5H\u2502     \u2588\u2502"
# echo -e "\033[13;5H\u2502     \u2588\u2502"
# echo -e "\033[14;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
# echo -e "\033[15;5H\u2502     \u2588\u2502"
# echo -e "\033[16;5H\u2502     \u2588\u2502"
# echo -e "\033[17;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
# echo -e "\033[18;5H\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2518"

var1=0;

for (( i=1; i <= 9; i++ ))
do
if [ $i -eq 1 ]
then
echo -e "\033[10;5H\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2510"
elif [ $i -eq 2 ]
then
echo -e "\033[11;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
elif [ $i -eq 5 ]
then
echo -e "\033[14;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
elif [ $i -eq 8 ]
then
echo -e "\033[17;5H\u2502\u2588\u2588\u2588\u2588\u2588 \u2502"
elif [ $i -eq 9 ]
then
echo -e "\033[18;5H\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2518"
else
var1=$(( 9 + $i ))
echo -e "\033[$var1;5H\u2502     \u2588\u2502"
fi
done
