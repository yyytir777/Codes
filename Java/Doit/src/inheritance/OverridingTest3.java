package inheritance;

public class OverridingTest3 {

	public static void main(String[] args) {
		int price = 10000;
		
		Customer customerLee = new Customer(10010, "Lee");
		System.out.println(customerLee.getCustomerName() + " : " + customerLee.calcPrice(price));
		
		VIPCustomer customerKim = new VIPCustomer(10020, "Kim", 12345);
		System.out.println(customerKim.getCustomerName() + " : " + customerKim.calcPrice(price));
		
		Customer vc = new VIPCustomer(10030, "Lim", 2000);
		System.out.println(vc.getCustomerName() + " : " + vc.calcPrice(price));
	}

}
