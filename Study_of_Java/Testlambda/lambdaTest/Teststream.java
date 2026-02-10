package lambdaTest;

import java.util.ArrayList;
import java.util.List;

public class Teststream {
    public static void main(String[] args) {
        //1.创建一个集合
        //2.通过集合获取流
        //3.对流进行操作
        //4.将流转换为其他形式
        List<String> list=new ArrayList<>();
        list.add("f");
        list.add("s");
        list.add("j");
        list.add("a");
        list.add("c");
        //collection接口下.stream()可以获取流，filter（）里面的参数是一个函数式接口Predicate
        list.stream().filter(s->s.startsWith("a")).forEach(System.out::println); 
    }
}
