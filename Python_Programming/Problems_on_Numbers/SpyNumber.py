'''
    Description : program  to check the number is Spy number or not 
                EX :- sum of digit = product of digit
                
    Date :- 21/03/2026
    
    Author : Rekha Shankarlal Kumawat
                
'''
def SpyNumber(iNo):


    iSum = 0 
    iprod = 0 
    iDigit = 0 
    iTemp = 0
    
    iTemp = iNo 

    iprod = 1 
    while(iNo != 0):
    
        iDigit = iNo % 10 
        iSum = iSum + iDigit
        iprod = iprod*iDigit

        iNo = iNo //10 
    
    return iSum == iprod
    
def main():
    
    iValue = 0
    bRet = False 

    print("Enter the Number :- ")
    iValue = int(input())
    
    bRet =  SpyNumber(iValue)

    if(bRet == True):
        print(iValue ,"is a Spy Number")
    else:
        print(iValue ,"is not a Spy Number")

if __name__ == "__main__":
    main()