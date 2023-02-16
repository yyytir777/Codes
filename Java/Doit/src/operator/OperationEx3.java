package operator;

public class OperationEx3 {

	public static void main(String[] args) {
		int num1 = 10;
		int i = 2;
		
		boolean value = ((num1 = num1 + 10) < 10) && ((i = i + 2) < 10);
		System.out.println(value);
		System.out.println(num1);
		System.out.println(i);
		
		value = ((num1 = num1 + 10) > 10) || ((i = i + 2) < 10);
		System.out.println(value);
		System.out.println(num1);
		System.out.println(i);
	}
	/*단락회로평가: 논리연산을 할 때 모든항을 실행하지 않더라도 결과 값을 알 수 있는 경우
	나머지 항은 실행되지 않는것 */
}
