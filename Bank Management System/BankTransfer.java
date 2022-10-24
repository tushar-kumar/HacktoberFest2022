package Bank;

import java.util.Scanner;

import Bank.Customer;

public class BankTransfer{
    
    static Customer customer[] = new Customer[10];
    static void getDetails(){
        Customer c = new Customer();
         System.out.println("Enter name -: ");
         Scanner sc = new Scanner(System.in);
         c.setName(sc.nextLine());
         System.out.println("Enter Account No -:");
         c.setAccNo(sc.nextLine());
         System.out.println("Enter Current bal -:");
         c.setbal(sc.nextFloat());
         //calling setDetails
          setDetails(c);
    }

    static void setDetails(Customer c){
        int i=0;
        while(customer[i]!=null){
            i++;
        }
        //now setting the details
        customer[i] = c;
    }

      static void printCustomers(){
        int i=0;
        System.out.println("################################### Customers Details #######################################");
        while(customer[i]!=null){
            System.out.println("\nCustomer "+ (i+1));
            System.out.println("Name : "+customer[i].getName());
            System.out.println("Account No  : "+customer[i].getAccNo());
            System.out.println("Balance :"+customer[i].getBal());
            i++;
        }
      }

      //method for validation of AccountNo
      static boolean validation(String accNo){
        int i=0;
        while(customer[i]!=null){
            if(customer[i].getAccNo().equals(accNo)){
                return true;

            }
            i++;
        }
        return false;
      } 
    //method for deduction money
    static void deductMoneyAndAddMoney(float amount , String senderAccNo,String recAccNo){
        int i=0;
        while(customer[i]!=null){
            if(customer[i].getAccNo().equals(senderAccNo)){
                customer[i].bal=customer[i].bal-amount;
            }
            if(customer[i].getAccNo().equals(recAccNo)){
                customer[i].bal = customer[i].bal+amount;
            }
            i++;
        }
    }
    public static void bankTransfer(){

        System.out.println("First Enter your Account No -: ");
        Scanner sc = new Scanner(System.in);
        String senderAccNo = sc.nextLine();
        //now validate senderAccNo
       if(!validation(senderAccNo)){
            System.out.println("\nCustomer doesn't exists !!! Please enter valid account number");
            return;
       }
        System.out.println("Now Enter Receiever  Account No -: ");
        String recAccNo = sc.nextLine();
        //now validate senderAccNo
        if(!validation(recAccNo)){
            System.out.println("\nCustomer doen't exists !!! Please enter valid account number");
            return;
       }
        System.out.println("Enter how much amount you want to transfer-: ");
        float amount = sc.nextFloat();
        //now first deduct money from sender account
        deductMoneyAndAddMoney(amount,senderAccNo,recAccNo);

        System.out.println("\n!!! Transaction successfully done ");
        
    }
    //for balance inquiry
    static void balInquiry(){
        System.out.println("Enter your Account No -:");
        Scanner sc= new Scanner(System.in);
        String accNo = sc.nextLine();
        if(!validation(accNo)){
            System.err.println("\n Customer doesn't exists !!!!");
            return;
        }else{
            int i=0;
            
        System.out.println("\n################################### Customer Details #######################################");
            while(customer[i]!=null){
                if(customer[i].getAccNo().equals(accNo)){
                    System.out.println("Name : "+customer[i].getName());
                    System.out.println("Account No  : "+customer[i].getAccNo());
                    System.out.println("Balance :"+customer[i].getBal());
                }
                i++;
            }
        }
    }


    void main(){
        int choice;
        while(true){
        System.out.println("\n1.Create Account \n2.See All Exists Customer\n3.Bank tranfer\n4.Balance Inquiry\n5.Exit\n");
        Scanner sc = new Scanner(System.in);
        choice =  sc.nextInt();
        switch(choice){
            case 1:
            getDetails();
            break;
            case 2:
            printCustomers();
            break;
            case 3:
            bankTransfer();
            break;
            case 4:
             balInquiry();
             break;
            case 5:
            System.exit(0);
            default:
            System.out.println("\n choose correct option");
        }
        }
    }
    public static void main(String[] args) {
        BankTransfer b = new BankTransfer();
        b.main();
    }
}