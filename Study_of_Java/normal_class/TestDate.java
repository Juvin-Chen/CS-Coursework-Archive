//这个包一定要导入，因为Date类在java.util包中
/*
介绍Date类的基本用法
DateFormat类和SimpleDateFormat类的用法
 */
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;
import java.util.zip.DataFormatException;


public class TestDate {

    public static void main(String[] args) throws ParseException {
        long now = System.currentTimeMillis();
        System.out.println("当前时间的毫秒数: " + now); //1754300203618
        Date data = new Date(); //这个调用的如果没有参数返回的就是当前的时间
        System.out.println(data); // 输出当前时间 Mon Aug 04 17:36:43 CST 2025
        // 创建指定毫秒数的Date对象，参照的标准时间是1970年1月1日00:00:00 UTC
        Date date1 = new Date(10000020323L);
        System.out.println(date1); // 输出指定时间
        System.out.println(date1.getTime()); // 调用Date类的getTime()，获取当前时间距离标准时间的毫秒数
        // 创建负数毫秒数的Date对象（1970年之前的时间）
        Date date2 = new Date(-21L * 365 * 24 * 60 * 60 * 1000);
        System.out.println(date2); // 输出1970年之前的时间
        // 调用Date类的比较方法
        System.out.println(date2.equals(date1)); // 比较是否相等
        System.out.println(date2.before(date1)); // 判断是否在之前
        System.out.println(date2.after(date1));  // 判断是否在之后
        System.out.println(date2.compareTo(date1)); // 比较先后（返回整数）

        /*
        日期时间格式化
        测试DateFormat类和SimpleDateFormat类的用法，后面的是前面的子类，做法就是先格式化SimpleDateFormat("pattern"),然后再试着进行相互转化
        */
        DateFormat format=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String str="2049-01-01 00:00:00"; //时间格式一定要匹配
        Date test=format.parse(str); // 将字符串解析为Date对象
        System.out.println(test); // 输出解析后的时间，这是标准的输出 Fri Jan 01 00:00:00 CST 2049
        System.out.println(test.getTime()); // 这个是毫秒数的输出 2493043200000

        DateFormat format2=new SimpleDateFormat("yyyy年MM月dd日 hh时mm分ss秒");
        Date date3 = new Date(3812712749128L);
        String str2 = format2.format(date3); // 将Date对象格式化为字符串
        System.out.println(str2); // 输出格式化后的字符串 2090年10月26日 10时52分29秒

        //比较不一样的表示
        Date now2 = new Date();
        DateFormat format3 = new SimpleDateFormat("今年的第D天，第W周，第F个星期");
        String str3 = format3.format(now2); // 将Date对象格式化为字符串
        System.out.println(str3); // 输出格式化后的字符串 今年的第216天，第2周，第1个星期

        //随机数，范围都是左闭右开区间
        // 生成随机数的类是java.util.Random，Math.random()也是生成随机
        System.out.println(Math.random()); // 生成0.0到1.0之间的随机数
        // Math.random()返回的是一个double类型的随机数，范围是[0.0, 1.0)，即包括0.0但不包括1.0
        // 如果需要生成其他范围的随机数，可以通过乘以范围的大小来实现
        Random random= new Random();
        System.out.println(random.nextDouble()); // 生成0.0到1.0之间的随机数
        System.out.println(random.nextInt()); // // 生成一个int类型范围内随机整数
        System.out.println(random.nextFloat());
        System.out.println(random.nextBoolean());  // 生成一个布尔值，true或false
        System.out.println(random.nextInt(10)); // 生成0到9之间的随机整数
        System.out.println(20+random.nextInt(10)); // 生成20到29之间的随机整数
        System.out.println(20+(int)(random.nextDouble()*10)); // 生成20到29之间的随机整数
    }
}
