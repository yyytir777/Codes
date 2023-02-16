package inheritance;

public class CustomerTest2 {

	public static void main(String[] args) {
		VIPCustomer customerKim = new VIPCustomer(10020, "Kim", 12);
		customerKim.setCustomerID(10020);
		customerKim.setCustomerName("Kim");
		
		customerKim.bonusPoint = 1000;
		System.out.println(customerKim.showCustomerInfo());
	}

}
