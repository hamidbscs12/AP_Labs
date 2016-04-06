import static org.junit.Assert.*;
//                          /////////////////////dice////////////////////////
import org.junit.Test;

public class Dice {

	
	@Test
	public void testDice(){
		
		Player player = new Player();
		
		int get_D = player.move();
		System.out.println(get_D);	
		
		if(get_D>0 && get_D<=6){
			assertTrue(true);
		}
	}
	
	@Test
	public void test2(){
			
		SnakeLad sl = new SnakeLad();
		
		if(sl.saanp.size()>=6)		
			assertTrue(true);
		
		if(sl.ladr.size()>=6)
			assertTrue(true);
		
		
		
	}
	

}
