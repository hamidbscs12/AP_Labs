import java.util.Random;
import java.util.HashMap;
import java.util.*;
public class SnakeLad {
	
	
	public int[][] luddo ;
	public int totplayr;
	public Map<Integer, Integer> saanp = new HashMap<Integer, Integer>();
	public Map<Integer, Integer> ladr = new HashMap<Integer, Integer>();
	public Player[] player;
	SnakeLadDomain dc;
	
	//constructor
	public SnakeLad(){
		
		initilizeBoard();
		run();
	}
	
	//initilze luddo
	public void initilizeBoard(){
		luddo = new int[10][10];
		int x = 1;
		for(int i=0 ; i<10 ; i++)
			for(int j=0 ; j<10 ; j++)
				luddo[i][j] = x++;	
		
		saanp.put(35, 10);
		saanp.put(43, 35);
		saanp.put(59, 38);
		saanp.put(70, 30);
		saanp.put(67, 44);
		saanp.put(98, 80);
		
		ladr.put(9, 35);
		ladr.put(23, 39);
		ladr.put(62, 100);
		ladr.put(66, 87);
		ladr.put(73, 96);
		ladr.put(78, 98);
	}
	

	public void run(){

		int curMove = 1,finMove = 1; 
		dc = new SnakeLadDomain();
		
		//loop of SnakeLad count
		while(curMove++ <= finMove){
			
			int countplayer;
			Random rand = new Random();
			countplayer = (int)rand.nextInt(4)+1;
			System.out.println("Total Player: "+ countplayer);
			player = new Player[countplayer];
			
			//initilize playrs
			for(int i=0 ; i< countplayer; i++)
				player[i] = new Player();
			//save cur move
			int move = 1;
			
			boolean runloop = true;
			
			while(runloop){
				move++;
				
				for(int i = 0; i < countplayer ; i++){
					
					//save player score
					int movee = 0;
					movee = player[i].move();
					
					//Temp store pos of move
					int temp = player[i].curPos + movee;
					
					//Check snake or not
					if(saanp.containsKey(temp)){
						player[i].curPos = saanp.get(temp);
						//transfer to other player 
						continue;
					}
					//check ladder or not
					else if(ladr.containsKey(temp)){
						temp = ladr.get(temp);
						
					} 
					while(true){
						if(movee == 6)
							movee += player[i].move();
						else
							break;
					}
					//if snake or ladder 
					temp = player[i].curPos + movee;
					if(saanp.containsKey(temp)){
						player[i].curPos = saanp.get(temp);
						continue;
					}
					else if(ladr.containsKey(temp)){
						temp = ladr.get(temp);
					}
					
					//if player current position is greter then 100
					//no move
					if(player[i].curPos + movee > 100)
						break;
					
					//if cur pos equal to  100,move to 100
					//wins
					else if(player[i].curPos + movee == 100){
						player[i].st = true;
						System.out.println("Player "+(i+1)+" Won.");
						runloop = false;
						break;
					}
					else
						player[i].curPos += movee;
				}//end player turn\
				
			}//end total move
			
			//SnakeLad ends
			dc.moves.add(move);
			//print total moves
			System.out.println("Total Moves: "+ move);
			System.out.println();
		}
		dc.showStats();
	}
	
	public static void main(String[] args)
	{
		new SnakeLad();
	}
}
