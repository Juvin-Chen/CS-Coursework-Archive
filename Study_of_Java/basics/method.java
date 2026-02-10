public class method {
    public static void main(String[] args) {
        //使用递归算法完成阶乘：1!+2!+3!+4!+5!
        int a=5,sum=0;
        for(int i=1;i<=5;i++){
            sum+=add(i);
        }
        System.out.println(sum);
    }
    //写方法的时候好像就是需要public static
    public static int add(int num){
        if(num==1) return 1;
        else return num*add(num-1);
    }

}
