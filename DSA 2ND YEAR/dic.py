# Enter your code here. Read input from STDIN. Print output to STDOUT
n=input()
dic={};
for t in range(n):
    k,v=raw_input().split(' ')
    dic[k]=v
O_name=raw_input()
N_name=" "
while O_name!=N_name:
    if(dic.has_key(O_name)):
        print O_name+'='+dic[O_name]
    else:
        print "Not found"
    N_name=O_name
    O_name=raw_input()

    
