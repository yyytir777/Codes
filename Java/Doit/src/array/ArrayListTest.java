package array;
import java.util.ArrayList;

public class ArrayListTest {

	public static void main(String[] args) {
		ArrayList<Book> library = new ArrayList<Book>();
		
		library.add(new Book("a", "1"));
		library.add(new Book("b", "2"));
		library.add(new Book("c", "3"));
		library.add(new Book("d", "4"));
		library.add(new Book("e", "5"));
		
		for(int i = 0; i < library.size(); i++) {
			Book book = library.get(i);
			book.showBookInfo();
		}
		System.out.println();
		
		System.out.println("Enhanced ForLoop");
		for(Book book : library) {
			book.showBookInfo();
		}
	}
}
