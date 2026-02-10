import java.util.*;


public class Testiterator {
    public static void main(String[] args) {
        List<String> list=new ArrayList<>();
        list.add("apple");
        list.add("banana");
        list.add("cherry");
        //使用迭代器遍历集合
        System.out.println("Using Iterator:");
        Iterator<String> iterator = list.iterator(); // 获取迭代器
        while (iterator.hasNext()) { // 检查是否有下一个元素
            String element = iterator.next(); // 获取下一个元素
            System.out.println(element); // 输出元素
        }
        //使用for循环
        for (Iterator<String> it2= list.iterator();it2.hasNext();) { // 增强for循环遍历集合
            System.out.println(it2.next());
        }

        //set的迭代器使用方式和list是一样的
        Set<String> set1=new HashSet<>();
        set1.add("dog");
        set1.add("cat");
        Iterator<String> it = set1.iterator(); // 获取迭代器
        while(it.hasNext()){
            System.out.println(it.next());
        }

        //用迭代器删除元素，注意：不要一边迭代一边添加元素
        List<String> list2 = new ArrayList<>(Arrays.asList("one", "two", "three", "four"));
        Iterator<String> it2 = list2.iterator();
        while (it2.hasNext()) {
            String element = it2.next();
            if (element.equals("two")) {
                it2.remove(); // 使用迭代器的remove方法删除元素
            }
        }
        System.out.println("After removal: " + list2); // 输出删除后的集

    }
}
