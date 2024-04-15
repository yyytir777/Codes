package java_project.test;

import java.util.Arrays;
import java.util.HashSet;

public class test {
    public static void main(String[] args) {
        HashSet<Integer> set = new HashSet<Integer>(Arrays.asList(1,2,3,4,5));

        ////set내부에 값 1이 있다면 true 출력, 없다면 false 출력
        System.out.println(set.contains(0));     
    }
}
