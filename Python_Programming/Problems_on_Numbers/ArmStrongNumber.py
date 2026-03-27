'''
    Description : program  to check the number is Armstrong number or not 
                EX :- 153 (1^3 +5^3 + 3^3 == 153)

    Date :- 21/03/2026
    
    Author : Rekha Shankarlal Kumawat
'''

def ArmstrongNumber(iNo):

        iCount = 0 
        iDigit = 0 
        iPow = 0  
        iTemp = 0 
        iSum = 0  
        iCountTemp =0 
        
        iTemp = iNo

        while(iNo != 0):
        
            iDigit = iNo % 10               
            iCount = iCount +1
            iNo = iNo // 10
        
        iNo = iTemp 
        iCountTemp = iCount 

        while (iNo != 0):
            iDigit = iNo % 10
            iCount= iCountTemp
            iPow =1 

            while(iCount!= 0):
        
                iPow = iPow*iDigit
                iCount = iCount -1
            

            iSum =iSum +iPow 
            iNo = iNo // 10

        return iSum == iTemp

def main():

    iValue = 0
    iRet = False

    print("Enter the Numner : ")
    iValue = int(input())

    iRet = ArmstrongNumber(iValue)

    if(iRet == True):
        print(iValue," is a ArmStrong Number ")
    else:
        print(iValue ," is not a ArmStrong Number ")

if __name__ == "__main__":
    main()