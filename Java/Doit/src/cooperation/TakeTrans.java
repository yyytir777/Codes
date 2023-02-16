package cooperation;

public class TakeTrans {
	public static void main(String[] args) {
		Student student1 = new Student("1", 5000);
		Student student2 = new Student("2", 10000);
		
		Bus bus100 = new Bus(100);
		student1.takeBus(bus100);
		student1.showInfo();
		bus100.showInfo();
		
		Subway subwaygreen = new Subway("2");
		student2.takeSubway(subwaygreen);
		student2.showInfo();
		subwaygreen.showInfo();
	}
}
