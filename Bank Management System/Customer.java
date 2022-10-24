package Bank;
public class Customer {
    private String name,AccNo;
    float bal;
    public Customer(){

    }
    public void setName(String name){
        this.name=name;
    }
    public String getName(){
        return name;
    }
    public void setAccNo(String AccNo){
        this.AccNo=AccNo;
    }
    public String getAccNo(){
        return AccNo;
    }
    public void setbal(float bal){
        this.bal=bal;
    }
    public float getBal(){
        return bal;
    }
}
