package witharraylist;
import java.util.ArrayList;

public class CustomerTest {

	public static void main(String[] args) {
		ArrayList<Customer> customerList = new ArrayList<Customer>();
		
		Customer customerLee = new Customer(10010, "Lee");
		Customer customerKim = new Customer(10020, "Kim");
		Customer customerShin = new GoldCustomer(10030, "Shin");
		Customer customerHong = new GoldCustomer(10040, "Hong");
		Customer customerYoul = new VIPCustomer(10050, "Youl", 12345);
		
		customerList.add(customerYoul);
		customerList.add(customerHong);
		customerList.add(customerShin);
		customerList.add(customerKim);
		customerList.add(customerLee);
		
		System.out.println("print customer information");
		for(Customer customer : customerList) {
			System.out.println(customer.showCustomerInfo());
		}
		
		System.out.println("calculate saleratio & bonuspoint");
		int price = 10000;
		for(Customer customer : customerList) {
			int cost = customer.calcPrice(price);
			System.out.println(customer.getCustomerName() + " : " + cost);
			System.out.println(customer.getCustomerName() + " : " + customer.bonusPoint);
		}
	}

}
