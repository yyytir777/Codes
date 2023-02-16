package arraylist;

public class StudentTest {

	public static void main(String[] args) {
		Student studentLee = new Student(1001, "Lee");
		studentLee.addSubject("Language", 100);
		studentLee.addSubject("Math", 50);
		
		Student studentKim = new Student(1002, "Kim");
		studentKim.addSubject("Language", 70);
		studentKim.addSubject("Math", 85);
		studentKim.addSubject("English", 100);
		
		studentLee.showStudentInfo();
		System.out.println("=================================");
		studentKim.showStudentInfo();
	}

}
