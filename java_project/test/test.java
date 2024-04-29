package java_project.test;

public class test {
    public static void main(String[] args) {
        
        CharSequence test = "He";
        System.out.println("test " + test.codePoints().reduce((v1, v2) -> v2));        
        
        System.out.println((int) 'e');
    }
}
