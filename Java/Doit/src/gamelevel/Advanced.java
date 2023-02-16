package gamelevel;

public class Advanced extends PlayerLevel{

	@Override
	public void run() {
		System.out.println("Runs fast");
	}

	@Override
	public void jump() {
		System.out.println("Jump high");
	}

	@Override
	public void turn() {
		System.out.println("Can't Turn");
	}

	@Override
	public void showLevelMessage() {
		System.out.println("Advanced Level");
	}
}
