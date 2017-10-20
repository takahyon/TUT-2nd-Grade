
package lec04;

import java.math.*;
/**
 * Created by takamasa on 2017/10/20.
 */
public class ADS_Ex04_2 {
    public static void main(String[] args) {
        System.out.println(fibonacci(31));
    }
        static int fibonacci(int n) {
            return (n==1||n==0)?n:fibonacci(n-2)+fibonacci(n-1);


    }

}

