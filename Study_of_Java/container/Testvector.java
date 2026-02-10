import java.util.*;

public class Testvector {
    public static void main(String[] args) {
        Vector<Integer> vector = new Vector<>();
        vector.add(1);
        vector.add(2);
        //这个是向量的独有方法firstElement和lastElement
        System.out.println("第一个元素: " + vector.firstElement());
        System.out.println("最后一个元素: " + vector.lastElement());


    }

}
