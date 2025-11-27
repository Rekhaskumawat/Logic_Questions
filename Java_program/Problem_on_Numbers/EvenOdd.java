import java.util.Scanner;

class Logic
{
    int iNo = 0;

    public Logic(int iNo)
    {
        this.iNo = iNo ;
    }

    boolean Check()
    {
        return ((iNo % 2) == 0);
    }
    
}
class EvenOdd
{
    public static void main(String Arr[])
        {
            int iValue = 0 ;
            boolean bRet = false;

            Scanner sobj = new Scanner(System.in);
            

            System.out.println("Enter the number:");
            iValue = sobj.nextInt();

            Logic lobj = new Logic(iValue);
            bRet = lobj.Check();

            if(bRet == true)
            {
                System.out.println(iValue + " is an Even Number");
            }
            else
            {
                System.out.println(iValue + " is an Odd Number ");
            }

        }

}