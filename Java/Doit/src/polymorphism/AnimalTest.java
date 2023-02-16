package polymorphism;
import java.util.ArrayList;

class Animal{
	public void move() {
		System.out.println("Animal moves");
	}
}

class Human extends Animal{
	public void move() {
		System.out.println("Human walks");
	}
	
	public void readBook() {
		System.out.println("Human read a book");
	}
}

class Tiger extends Animal{
	public void move() {
		System.out.println("Tiger runs");
	}
	
	public void hunting() {
		System.out.println("Tiger hunts");
	}
}

class Eagle extends Animal{
	public void move() {
		System.out.println("Eagle flies");
	}
	
	public void flying() {
		System.out.println("Eagle flies away");
	}
}

public class AnimalTest {
	ArrayList <Animal> aniList = new ArrayList<Animal>();
	
	public static void main(String[] args) {
		AnimalTest aTest = new AnimalTest();
		aTest.addAnimal();
		System.out.println("DownCasting");
		aTest.testCasting();
	}
	
	public void addAnimal() {
		//Animal형으로 형변환
		aniList.add(new Human());
		aniList.add(new Tiger());
		aniList.add(new Eagle());
		
		for(Animal ani : aniList) {
			ani.move();
		}
	}
	
	public void testCasting() {
		for(int i = 0; i < aniList.size(); i++) {
			Animal ani = aniList.get(i);
			
			//Human이면 Animal -> Human으로 다운캐스팅
			if(ani instanceof Human) {
				Human h = (Human)ani;
				h.readBook();
			}
			
			//Tiger이면 Animal -> Tiger로 다운캐스팅
			else if(ani instanceof Tiger) {
				Tiger t = (Tiger)ani;
				t.hunting();
			}
			
			//Eagle이면 Animal -> Eagle로 다운캐스팅
			else if(ani instanceof Eagle) {
				Eagle e = (Eagle)ani;
				e.flying();
			}
			
			else {
				System.out.println("form not supported");
			}
		}
	}
}
