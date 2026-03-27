'''
    Description : program  to check the number is Sunny number or not 
                EX :- number + 1 is  perfect square number than its sunny number
                
    Date :- 21/03/2026
    
    Author : Rekha Shankarlal Kumawat
    
'''
import math 

def SunnyNumber(iNo):

    Ans = 0

    iNo = iNo +1

    Ans = int(math.sqrt(iNo))
    return(iNo == (Ans*Ans))

def main():
    
    iValue = 0
    bRet = False 

    print("Enter the Number :- ")
    iValue = int(input())
    
    bRet =  SunnyNumber(iValue)

    if(bRet == True):
        print(iValue ," is a Sunny Number\n")
    else:
        print(iValue ," is not a Sunny Number\n")

if __name__ == "__main__":
    main()