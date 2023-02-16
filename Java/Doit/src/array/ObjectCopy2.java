package array;

public class ObjectCopy2 {

	public static void main(String[] args) {
		Book[] bookArray1 = new Book[3];
		Book[] bookArray2 = new Book[3];
		
		bookArray1[0] = new Book("a", "1");
		bookArray1[1] = new Book("b", "2");
		bookArray1[2] = new Book("c", "3");
		System.arraycopy(bookArray1, 0, bookArray2, 0, 3);
		
		for(int i = 0; i < bookArray2.length; i++) {
			bookArray2[i].showBookInfo();
		}
		
		bookArray1[0].setBookName("a_1");
		bookArray1[0].setAuthor("1_1");
		
		System.out.println("bookArray1 : ");
		for(int i = 0; i < bookArray1.length; i++) {
			bookArray1[i].showBookInfo();
		}
		
		//bookArray1의 변경사항이 bookArray2에도 적용 : 얕은 복사
		System.out.println("bookArray2 : ");
		for(int i = 0; i < bookArray2.length; i++) {
			bookArray2[i].showBookInfo();
		}
	}

}
