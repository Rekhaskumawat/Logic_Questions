'''
    Description : program  to check the number is Automorphic number or not 
                EX :- 25 -> 25^2 = 625  (last digit of ans is 25 so its Automorphic)
                
    Date :- 21/03/2026
    
    Author : Rekha Shankarlal Kumawat
                
'''

def AutomorphicNumber(iNo):
    
    iCount = 0 
    iTemp = 0 
    iSqr = 0 
    iDeno = 0
    iCnt = 0 

    iTemp = iNo 

    while (iNo != 0):
    
        iCount = iCount +1 
        iNo = iNo // 10
        
    

    iNo = iTemp
    iSqr = iNo * iNo
    iDeno = 1 
    for i in range(1 ,iCount+1):
        iDeno = iDeno * 10

    return((iSqr % iDeno) == iTemp)
    

def main():
    
    iValue = 0
    bRet = False 

    print("Enter the Number :- ")
    iValue = int(input())
    
    bRet =  AutomorphicNumber(iValue)

    if(bRet == True):
        print(iValue ,"is a Automorphic Number")
    else:
        print(iValue ,"is not a Automorphic Number")

if __name__ == "__main__":
    main()