import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        //动态初始化
        int[]  a=null; //数组的声明，这里只有栈
        a=new int[10]; //数字的定义，到这里才会在堆中分配空间
        Man m1=new Man(19,"chen");
        Man[] man=new Man[2];
        man[0]=m1;

        //静态初始化
        int[] b={1,2,3,4,5,6,7,9,8};
        System.out.println(b[1]);

        //几种遍历方式
        //简单的读取，不能改变
        for(int i:b){
            System.out.println(i);
        }
        for(int i=0;i<b.length;i++){
            b[i]++;
        }

        //数组的拷贝
        int[] c=new int[10];
        //原数组，从原数组的哪个位置开始拷贝，目标数组，从目标数组的哪个位置开始粘贴，拷贝的元素数量
        System.arraycopy(b,0,c,0,b.length);

        //测试数组的java.util.Arrays类
        System.out.println(Arrays.toString(b)); //将数组元素打印出来
        Arrays.sort(b); //将数组排序
        System.out.println(Arrays.toString(b));
        //二分法查找，返回排序后新的索引位置，未找到返回-1
        System.out.println("该元素索引："+Arrays.binarySearch(b,9));
        //数组的填充，从索引1到2位置填充为100
        Arrays.fill(b,1,2,100);
        System.out.println(Arrays.toString(b));

        //多维数组，以数组为元素的数组，3种定义方式
        int[][] s=new int[3][];  //只能先定义前面的，从低维到高维
        s[0]=new int[5];
        s[2]=new int[2];
        s[0][1]=15;

        int[][] s1={
                {7,4},
                {1,2,3}
        };

        int[][] s2=new int[5][];
        s2[0]=new int[]{1,3,7,2,4}; //记住new int[]要先写，要先声明数组类型
        System.out.println(Arrays.toString(s2[0]));

        //数组存储表格的两种方式
        //用Object[]，对应于那句话Object数组的每一个元素都是对象
        Object[] a1={1001,"a",12};
        Object[] a2={1002,"b",13};
        Object[] a3={1003,"c",18};
        Object[][] emps=new Object[3][];
        emps[0]=a1;
        emps[1]=a2;
        emps[2]=a3;
        System.out.println(Arrays.toString(emps[0]));
        for (int i=0;i< emps.length;i++){
            for(int j=0;j<emps[i].length;j++){
                System.out.println(emps[i][j]+"\t");
            }
            System.out.println();
        }

        //使用javabean和数组保存数据
        Emp[] emp={
                new Emp(12,"a",15,"doctor","7.1"),
                new Emp(17,"vi",16,"pilot","8.9"),
                new Emp(16,"hra",18,"police","6.19"),
        };
        for(Emp e:emp){
            System.out.println(e);
        }

        //使用Compareable接口进行比较,这个接口只有一个方法public int compareTo(Object o),java排序算法的底层也依赖这个接口
        Man mans[]={new Man(12,"ki"),new Man(13,"tom"),new Man(10,"li")};
        Arrays.sort(mans);
        System.out.println(Arrays.toString(mans));

        //冒泡排序极其优化
        int[] values = {5, 3, 8, 6, 2};
        boolean flag = true;
        int temp;
        // 外层循环控制排序的趟数
        for (int i = 0; i < values.length - 1; i++) {
            for (int j = 0; j < values.length - 1 - i; j++) {
                if (values[j] > values[j + 1]) { // 如果前一个元素大于后一个元素，则交换两元素的值；
                    temp = values[j];
                    values[j] = values[j + 1];
                    values[j + 1] = temp;
                    // 本趟发生了交换，表明该数组在本趟处于无序状态，需要继续比较；
                    flag = false;
                }
            }
            if (flag) break; // 如果某一趟没有发生交换，说明数组已经有序，提前退出排序
        }

    }
    //二分查找方法，前提是这个数组要是有序的
    public static int binarySearch(int[ ] array, int value){
        int low = 0;
        int high = array.length - 1;
        while(low <= high){
            int middle = (low + high) / 2;
            if(value == array[middle]){
                return middle;        //返回查询到的索引位置
            }
            if(value > array[middle]){
                low = middle + 1;
            }
            if(value < array[middle]){
                high = middle - 1;
            }
        }
        return -1;        //上面循环完毕，说明未找到，返回-1
    }
}
class Man implements Comparable{
    int age;
    String name;
    Man(int age,String name){
        this.age=age;
        this.name=name;
    }

    @Override
    public int compareTo(Object o) {
        Man man=(Man)o;
        if(this.age< man.age) return -1;
        else if(this.age>age) return 1;
        return 0;
    }

    @Override
    public String toString() {
        return "Man{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }
}
class Emp{
    public int id;
    public String name;
    public int age;
    public String job;
    public String hiredate;
    public Emp(int id, String name, int age, String job, String hiredate) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.job = job;
        this.hiredate = hiredate;
    }
    //重写toString方法
    @Override
    public String toString() {
        return "Emp{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", job='" + job + '\'' +
                ", hiredate='" + hiredate + '\'' +
                '}';
    }
}