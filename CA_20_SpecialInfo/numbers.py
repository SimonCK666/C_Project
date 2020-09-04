#
# numbers.py
# @author bulbasaur
# @description 
# @created 2020-07-29T19:00:12.252Z+08:00
# @last-modified 2020-07-29T19:07:09.242Z+08:00
#
sum=0
for i in range(1,5,1):
    for j in range(1,5,1):
        for k in range(1,5,1):
            if(i!=j&j!=k):
                sum=sum+1;
                print (i,j,k)  # 这里去重
print (sum)