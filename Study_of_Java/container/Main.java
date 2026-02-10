import java.util.ArrayList;
import java.util.List;


public class Main {
    public static void main(String[] args) {
        //容器并非 “完全无法确定初始大小”。可以在创建时指定初始容量（如new ArrayList<>(100)），但这只是为了优化性能（减少扩容次数），并非强制要求。
        List<String> list=new ArrayList<>();
        //添加元素，返回值是boolean类型，表示添加是否成功
        //快捷键的使用方式，假如一开始只打了list.add("aa")，ctrl+alt+v直接生成返回值boolean的形式
        list.add("aa");
        list.add("bb");
        System.out.println(list); //输出整个集合
        System.out.println(list.size());
        if(list.contains("ee")) System.out.println("has ee");;
        //第一个是加入元素的索引位置，这个位置不能超过当前集合的大小
        list.add(0,"00"); //在开头添加元素
        String s=list.get(1);  //获取索引为1的元素
        //两种获取所有元素的方式
        for(int i=0; i < list.size(); i++)
            System.out.println(list.get(i)); //遍历输出集合中的每个元素
        for(String str : list)
            System.out.println(str); //使用增强for循环遍历输出集合中的每个元素
        list.remove("bb"); //删除指定元素
        list.remove(0); //删除指定索引位置的元素
        list.set(0,"tt"); //修改指定索引位置的元素
        //查找元素在容器中第一次出现的位置
        int index=list.indexOf("tt");
        int index2=list.lastIndexOf("tt"); //查找元素在容器中最后一次出现的位置
        System.out.println("Index of 'tt' (first occurrence): " + index);
        System.out.println("Index of 'tt': " + index);
        list.clear(); //清空集合
        System.out.println(list); //输出空集合
        //ArrayList的并集，交集，差集
        //并集：将一个集合的所有元素与另一个集合的所有元素合并，去除重复元素
        List<String> list2 = new ArrayList<>();
        list2.add("a");
        list2.add("b");
        List<String> list3 = new ArrayList<>(); //创建一个新的集合，包含list的所有元素
        list3.add("first"); //添加一个新元素到list3
        list3.add("a");
        list3.addAll(list2); //将list2的所有元素添加到list3
        System.out.println("Union: " + list3); //输出并集
        //交集：获取两个集合中都存在的元素，保留相同的。去除不相同的元素
        list2.retainAll(list3); //保留两个集合中都存在的元素
        System.out.println("Intersection: " + list2); //输出交集
        //差集：获取一个集合中存在而另一个集合中不存在的元素,保留不同的，去除相同的
        //List<String> list4 = new ArrayList<>(list3) 中的 list3 是一个已存在的列表对象，这句话的意思是 创建一个新的 ArrayList 容器，并将 list3 中的所有元素复制到这个新容器中。
        List<String> list4 = new ArrayList<>(list3); //创建一个新的集合，包含list3的所有元素
        list4.add("different"); //添加一个新元素到list
        list4.removeAll(list3); //从list4中删除所有在list中存在的
        System.out.println("Difference: " + list4); //输出差集

    }
}