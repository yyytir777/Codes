package gamelevel;

public class Beginner extends PlayerLevel{

	@Override
	public void run() {
		System.out.println("Runs slow");		
	}

	@Override
	public void jump() {
		System.out.println("Can't Jump");
	}

	@Override
	public void turn() {
		System.out.println("Can't Turn");
	}

	@Override
	public void showLevelMessage() {
		System.out.println("Beginner Level");
	}	
}
