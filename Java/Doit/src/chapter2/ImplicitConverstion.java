package chapter2;

public class ImplicitConverstion {

	public static void main(String[] args) {
		byte bNum = 10;
		int iNum = 10;
		
		System.out.println(bNum);
		System.out.println(iNum);
		
		int iNum2 = 20;
		float fNum = iNum2;
		
		System.out.println(iNum);
		System.out.println(fNum);
		
		double dNum;
		dNum = fNum + iNum;
		System.out.println(dNum);
	}

}
