package gamelevel;

public class Super extends PlayerLevel{

	@Override
	public void run() {
		System.out.println("Runs very fast");
	}

	@Override
	public void jump() {
		System.out.println("Jump very high");
	}

	@Override
	public void turn() {
		System.out.println("Turn around");
	}

	@Override
	public void showLevelMessage() {
		System.out.println("Super Level");
	}
}
