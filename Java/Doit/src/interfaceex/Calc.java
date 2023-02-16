package interfaceex;

public interface Calc {
	double PI = 3.14;
	int ERROR = -999999999;
	
	//인터페이스에서 선언한 메소드는 컴파일 과정에서 자동으로 추상 메소드로 변환
	int add(int num1, int num2);
	int substract(int num1, int num2);
	int times(int num1, int num2);
	int divide(int num1, int num2);
}
