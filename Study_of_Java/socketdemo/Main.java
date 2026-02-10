import java.io.*;
import java.net.*;

public class Main {
    public static void main(String[] args) throws  Exception{
        URL url = new URL("https://www.itbaizhan.com/");
        try (BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()))) {
            StringBuilder sb = new StringBuilder();
            String temp;
            /*
             * 这样就可以将网络内容下载到本地机器。
             * 然后进行数据分析，建立索引。这也是搜索引擎的第一步。
             */
            while ((temp = br.readLine()) != null) {
                sb.append(temp);
            }
            System.out.println(sb);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}