/**
 * 
 */

/**
 * @author Rafael Gameiro
 *
 */
public class ficha2_2 {
	
	public static final int DEFAULT = 32;
	public static final int EXPONENTE = 8;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		float f = 0.1f;
		
		int fint = Float.floatToIntBits(f);
		
		printBin(fint);

	}
	
	public static void printBin(int val){
		int binary[] = new int[DEFAULT];
		int counter = 0;
		int value = val;
		for(int i = 0;value != 0; i++){
			int result = value % 2;
			binary[i] = result;
			counter++;
			value = value / 2;
		}
		binary[counter++] = 0;
		for(int i = counter;i >= 0; i--){
			System.out.print(binary[i]);
		}
		for(int i = counter;i >counter-10;i--){
			int exp[] = new int[EXPONENTE];
		}
		
	}

}
