package inheritance;

public class OverridingTest2 {

	public static void main(String[] args) {
		//묵시적 형변환 -> VIPCustomer기 Customer로 변환 : 어떤 클래스의 메서드를 호출? ==> VIPCustomer의 메서드 호출
		Customer vc = new VIPCustomer(10030, "a", 2000);
		vc.bonusPoint = 1000;
		
		System.out.println(vc.getCustomerName() + " : " + vc.calcPrice(10000));
	}

}
