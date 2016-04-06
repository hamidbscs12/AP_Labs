import java.util.Random;

public class Player {

	public int sc,curPos;
	public boolean st;
	
	//default
	public Player(){
		sc = 0;
		curPos = 0;
		st = false;
	}

	public int move(){
		Random rand = new Random();
		return (int)rand.nextInt(6)+1;
	}
	
}
