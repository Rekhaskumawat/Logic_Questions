'''
    Description : program  to check the number is Neon number or not 
                EX :- 9 (9^2 = 81  , (8+1 == 9)) then  its neon number
                
     Date :- 21/03/2026
    
    Author : Rekha Shankarlal Kumawat

                
'''

def NeonNumber(iNo):
    iCount = 0 
    iDigit = 0 
    iTemp = 0  
    iSum = 0 

    iTemp = iNo 

    iNo = iNo * iNo

    while (iNo != 0) :
        iDigit = iNo % 10
        iSum = iSum+iDigit 
        iNo = iNo // 10

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