package gamelevel;

public class MainBoard {

	public static void main(String[] args) {
		Player player = new Player();
		player.play(1);
		
		Advanced aLevel = new Advanced();
		player.upgradeLevel(aLevel);
		player.play(2);
		
		Super sLevel = new Super();
		player.upgradeLevel(sLevel);
		player.play(3);
	}

}
