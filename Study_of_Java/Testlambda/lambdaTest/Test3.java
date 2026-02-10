package lambdaTest;

import javax.print.DocFlavor;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Compare implements Comparator<String> {
    @Override
    public int compare(String o1, String o2) {
        return o1.compareTo(o2);
    }
}
public class Test3 {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        list.add("f");
        list.add("s");
        list.add("j");
        list.add("a");
        list.add("c");
        //遍历集合
        Comparator c=new Compare();
        list.sort(c);
        list.forEach(s-> System.out.println(s));

        //lambda表达式简化
        list.sort((o1,o2)->o1.compareTo(o2));
        list.forEach( System.out::println);
    }
}
