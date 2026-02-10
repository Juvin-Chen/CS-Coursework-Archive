package fzhuang.b;

public class animial {
    public void shout(){
        System.out.println("lalala");
    }

    public static void main(String[] args) {

    }

}
class Dog extends animial{
    @Override
    public void shout() {
        System.out.println("wangwang");
    }
}
