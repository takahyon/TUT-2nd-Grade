package lec04;

/**
 * Created by takamasa on 2017/10/20.
 */
public class ADS_Ex04_1 {
    public static void main(String[] args) {
        int i =0;
        for (i=0; i<=9;i++) {
            System.out.print(i + ")Hello");
            if (i==2||i==7) {
                System.out.println("(" + i + "回目だよ)");
            }else{
                System.out.println();

            }
        }

    }
}
