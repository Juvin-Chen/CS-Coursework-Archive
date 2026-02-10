import java.util.Scanner;

public class calculator {
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        System.out.println("**********  ***********");
        do{
            int salary=s.nextInt();
            if(salary==88) break;
            int month=s.nextInt();
            System.out.println("年薪是："+salary*month);
            System.out.println("如果年薪超过10万，恭喜你超过90%的国人。如果年薪超过20万，恭喜你超过98%的国人");
        }while(true);



    }
}
