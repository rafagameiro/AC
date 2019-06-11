/**
 * 
 */
import java.util.Scanner;

/**
 * @author Rafael Gameiro
 *
 */
public class Ficha1_7 {

	/**
	 * @param args
	 */
	
	public static final int DEFAULT = 10000;
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int num = in.nextInt();
		in.nextLine();	
		
        printBin(num);
		

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
		
	}	
	
}
