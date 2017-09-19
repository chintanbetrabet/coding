c=8
fnum=2
while [ $c -gt 0 ]
do
c=$((c-1))
python generator.py > input/input0$fnum.txt
./a.out < input/input0$fnum.txt > output/output0$fnum.txt
fnum=$((fnum+1))
done
