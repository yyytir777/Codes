package interfaceex;

public abstract class Calculator implements Calc{

	@Override
	public int add(int num1, int num2) {
		return num1 + num2;
	}

	@Override
	public int substract(int num1, int num2) {
		return num1 - num2;
	}
	
	//times 와 divide를 구현하지 않았으므로 Calculator는 추상클래스
}
