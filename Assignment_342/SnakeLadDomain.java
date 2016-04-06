import java.util.ArrayList;

public class SnakeLadDomain {
	
	public Double avg;
	public Integer min;
	public Integer max;
	
	//list for moves
	public ArrayList<Integer> moves = null;

	//constructor
	public SnakeLadDomain() {
		moves = new ArrayList<Integer>();
		avg = 0.0;
		min = 0;
		max = 0;
	}
	
	public void showStats(){
		
		//calculate average moves of SnakeLad
		int sum = 0;
		for(int i=0; i<moves.size() ; i++)
			sum += moves.get(i);
		if(moves.size()<=0)
			this.avg = 0.0;
		else
			avg = (double) (sum/moves.size());
		System.out.println("Average moves: "+this.avg);
		
		//Calculate max moves of SnakeLad
		for(int i=0; i<moves.size() ; i++){
			if(max < moves.get(i)){
				max = moves.get(i);
			}
		}
		System.out.println("Maxim.. moves: "+this.max);
		
		//calculate min moves of SnakeLad
		min = max;
		for(int i=0; i<moves.size() ; i++){
			if(min > moves.get(i)){
				min = moves.get(i);
			}
		}
		System.out.println("Mini.. moves: "+this.min);
		
	}
	
	
}
