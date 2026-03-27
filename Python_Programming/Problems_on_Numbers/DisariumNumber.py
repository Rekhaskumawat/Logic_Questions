'''
    Description : program  to check the number is Disarium number or not 
                EX :- 135 (1^1 + 3^2 + 5^3 == 135) 
                
    Date : 21/03/2026
    
    Author : Rekha Shankarlal Kumawat
                
'''
import math

def DisariumNumber(iNo):

        iNo = 0 
        iTemp = 0 
        iDigit = 0 
        iCount = 0  
        iSum = 0 

        iTemp = iNo

        while (iNo != 0):
            iCount = iCount +1 
            iNo = iNo // 10

        iNo = iTemp 

        while(iNo != 0):
            iDigit = iNo % 10 
            iSum = iSum + (math.pow(iDigit, iCount))
            iCount = iCount -1
            iNo = iNo //10 

        
        return iSum == iTemp


def main():
    iValue = 0
    bRet = False 

    print("Enter the Number :- ")
    iValue = int(input())
    
    bRet =  NeonNumber(iValue)

    if(bRet == True):
        print(iValue ,"is a Neon Number")
    else:
        print(iValue ,"is not a Neon Number")

if __name__ == "__main__":
    main()