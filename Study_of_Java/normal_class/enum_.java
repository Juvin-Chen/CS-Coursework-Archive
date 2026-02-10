import java.util.Arrays;
import java.util.Random;

/*
    枚举（Enumeration） 是一种特殊的数据类型，用于定义一组固定的常量集合。它可以让代码更清晰、更安全，尤其适合表示有明确取值范围的场景（如星期、季节、状态等）。
 */
public class enum_ {
    public static void main(String[] args) {
        System.out.println(s.SPRING); // 访问season类中的常量
        //Season.values()：values() 是枚举类型自动生成的方法，调用后会返回一个包含该枚举所有常量的数组，这里返回的数组就是 [SPRING, SUMMER, AUTUMN, WINTER]。
        Season season = Season.SUMMER;
        System.out.println(season); // 输出枚举常量 SUMMER
        for (Season s : Season.values()) {
            System.out.println(s); // 输出枚举常量
        }
        // 创建 Random 对象，调用 nextInt(4) 生成 0、1、2、3 中的随机整数
        int a = new Random().nextInt(4);
        // Season.values() 获取枚举所有常量组成的数组，根据随机索引 a 取出对应枚举常量
        switch (Season.values()[a]) {
            case SPRING:
                System.out.println("春天");
                break;
            case SUMMER:
                System.out.println("夏天");
                break;
            case AUTUMN:
                System.out.println("秋天");
                break;
            case WINTER:
                System.out.println("冬天");
                break;
        }
    }
}
enum Season{
    SPRING, SUMMER, AUTUMN, WINTER
}
class s{
    public static final int SPRING = 0; // 春天
    public static final int SUMMER = 1; // 夏天
    public static final int AUTUMN = 2; // 秋天
    public static final int WINTER = 3; // 冬天
}