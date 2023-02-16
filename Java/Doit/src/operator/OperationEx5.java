package operator;

public class OperationEx5 {

	public static void main(String[] args) {
		int num = 0B00000101;
		
		System.out.println(num << 2); // 00010100
		System.out.println(num >> 2); // 00000001
		System.out.println(num >>> 2);// 00000001
		
		System.out.println(num); //num에 값을 대입하지 않았으므로 비트이동과 관계없이 값 유지
		
		num = num << 2; // 왼쪽으로 2비트 이동한 값을 num에 대입
		System.out.println(num);
	}

}
