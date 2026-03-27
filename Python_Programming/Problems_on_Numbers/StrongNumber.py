'''
    Description : program  to check the number is strong number or not 
                EX :- 145 (1! +4! + 5! == 145)

    Date :- 21/03/2026
    
    Author : Rekha Shankarlal Kumawat
'''


def StrongNumber(iNo):
    
    iDigit = 0 
    iSum = 0 
    iFact = 0
    iTemp = iNo 
    factArr =[1,1,2,6,24,120,720,5040,40320 ,362880 ]

    while(iNo != 0):
    
        iDigit = iNo % 10 

        iSum = iSum + factArr[iDigit] 

        iNo =  iNo // 10 

    
    
    return iTemp == iSum 

def main():

    iValue = 0
    iRet = False 

    print("Enter a Number :- ")
    iValue = int(input())

    iRet = StrongNumber(iValue)

    if(iRet == True):
        print(iValue," is a Strong Number ")
    else:
        print(iValue,"is not a Strong Number ")
    
if __name__ =="__main__":
    main()