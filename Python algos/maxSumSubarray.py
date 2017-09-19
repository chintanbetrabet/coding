def maxSubarray(nums):
    n=len(nums)
    curr=0
    pos=0
    ms=0
    me=0
    st=0
    end=0
    maxv=nums[0]
    for i in range(n):
        x=nums[i]
        if curr>0 and x >=0:
            curr=curr+x
            end+=1
            pos+=x
            if curr> maxv:
                maxv=curr
                ms=st
                me=end
        else:
            if curr <=0 and x >=0:
				curr=x
				pos+=x
				if curr> maxv:
					maxv=curr
					ms=st
					me=end
				st=i
				end=i
            else:
                if curr <=0 and x <=0:
					curr=0
					st=i
					end=i
					if curr> maxv:
						maxv=curr
						ms=st
						me=end
                else:
                    if curr >=0 and x <=0:
                        if curr> maxv:
                            maxv=curr
                            ms=st
                            me=end
                        curr=curr+x
                        end+=1
    if pos==0:
        pos=max(nums)
        maxv=pos
    #print "maxv from",ms,"to",me
    for i in range(ms,me+1):
        nums[i]=(nums[i]*-1)
    #print nums
    cnt=0
    for x in nums:
        if x==-1:
            cnt+=1
    return cnt
t=input()
while t>0:
    t-=1
    n=input()
    nums=map(int,raw_input().split())
    for i in range(n):
        nums[i]=pow(-1,nums[i])
    #print nums 
    print maxSubarray(nums)
            
