package array;

public class BookArray2 {

	public static void main(String[] args) {
		Book[] library = new Book[5];
		library[0] = new Book("a", "1");
		library[1] = new Book("b", "2");
		library[2] = new Book("c", "3");
		library[3] = new Book("d", "4");
		library[4] = new Book("e", "5");
		
		//Book 인스턴스 멤버
		for(int i = 0; i < library.length; i++) {
			library[i].showBookInfo();
		}
		
		//Book 인스턴스를 저장한 메모리 공간 주소
		for(int i = 0; i < library.length; i++) {
			System.out.println(library[i]);
		}
	}
}
