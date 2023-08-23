import math

def check_perfect_square(num):
    return (int(num**0.5) * int(num**0.5) == num)

for _ in range(int(input())):
    n = int(input())
    if n==1 or n%2!=0:
        print("NO")
    else:
        power_of_2 = 1
        flag = False
        while(power_of_2 < n):
            power_of_2 *= 2
            if(check_perfect_square(n/power_of_2)):
                flag = True
                break 
        if flag:
            print("YES")
        else:
            print("NO")