#april 13 1900 was friday
def find_date_diff(d1,m1,y1,d2,m2,y2,thir,diff):
    #days=[31,28,31,30,31,30,31,31,30,31,30,31]
    days=[3,0,3,2,3,2,3,3,2,3,2,3]
    if y1==y2 and m1==m2:
        
        diff+=d2-d1
        if diff%7==0:
                thir+=1
                print "one"
                #diff=0
        return diff,thir
    else:
        if y1==y2 and m2!=m1:
            print diff
            raw_input()
            if diff%7==0:
                thir+=1
                print "yo"
                #diff=0
                print diff
                raw_input()
                
            diff+=days[m1-1]-d1
            for m in range(m1,m2-1):
                diff+=days[m]
                if m==1:
                    diff+=is_leap(y1)             
            diff+=d2
            
            return diff,thir
        else:
            y=y1
            m=m1
            diff=days[m1-1]-d1
            while(y<y2):
                if diff%7==0:
                    thir+=1
                    print "three"
                    #diff=0
                    
                diff+=days[m]
                if m==1 :
                    diff+=is_leap(y)       
                m+=1
                if m==12:
                    m=0
                    y+=1
            while(m<m2-1):
                if m==1 :
                    diff+=is_leap(y)  
                diff+=days[m]
                m+=1
            diff+=d2
            
            return diff,thir
def is_leap(year):
    if year%4!=0:
        return 0
    else:
        if year%100!=0:
            return 1
        else:
            if year%400==0:
                return 1
            return 0
def thirteen_offset(date,diff):
    print "d1=%d"%date
    if date>=13:
        return diff,0
    else :
        if (diff+(13-date))%7==0:
            return 0,1;
    
def calc(d1,m1,y1,d2,m2,y2):
    days,thir=find_date_diff(13,4,1900,d1,m1,y1,0,0)
    off=days%7
    print "\n%d"%off
    off,start=thirteen_offset(d1,off)
    print "\n%d"%off
    
    #print thir,off
    
    raw_input()
    days,off=find_date_diff(d1,m1,y1,d2,m2,y2,start,off)
    print off
#print is_leap(2000)
calc(12 ,1 ,2012 ,20 ,7 ,2012)
#calc(19 ,10, 1995, 11, 07, 2015)
#print find_date_diff(13,4,1900,10,4,2000,0)
def alt_year_cal(year):
    if(is_leap(year)):
        return 366
    else :
        return 355


    
    

            
    
