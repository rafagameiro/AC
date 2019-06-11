/**
 * 
 */

/**
 * @author Rafael Gameiro
 *
 */
public class Ficha1_5 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		byte b = 127;
		
		String bb = Integer.toBinaryString(b);
		
		System.out.println("Resultado inicial Inteiro: " + b);
		System.out.println("Resultado inicial Binário: " + bb);
		
		for(int i = 0; i < bb.length();i++){
			if(i == 1){
				String bb1 = bb.substring(0, 1);
 				String bb2 = bb.substring(2, bb.length());
 				bb = bb1 + 0 + bb2;
			}
		}
		
		System.out.println("\nResultado final Binário: " + bb);
		b = (byte) Integer.parseInt(bb, 2);
		System.out.println("Resultado final Inteiro: " + b + "\n");
		
		System.out.println("Alinea b): \n");
		
		byte b_2 = 127;
		
		String bb_2 = Integer.toBinaryString(b_2);
		
		System.out.println("Resultado inicial Inteiro: " + b_2);
		System.out.println("Resultado inicial Binário: " + bb_2);
		
		for(int i = 0; i < bb_2.length();i++){
			
				String bb_21 = bb_2.substring(4, bb_2.length());
				bb_2 = "0000" + bb_21;
		}
		
		System.out.println("\nResultado final Binário: " + bb_2);
		b_2 = (byte) Integer.parseInt(bb_2, 2);
		System.out.println("Resultado final Inteiro: " + b_2);
		
		System.out.println("Alinea c): \n");
		
		byte b_3 = 0b00110011;
		
		String bb_3 = Integer.toBinaryString(b_3);
		
		System.out.println("Resultado inicial Inteiro: " + b_3);
		System.out.println("Resultado inicial Binário: " + bb_3);
		
		for(int i = 0; i < bb_3.length();i++){	
			if(i == 2){
				String bb_31 = bb_3.substring(0, 2);
 				String bb_32 = bb_3.substring(3, bb_3.length());
 				bb_3 = bb_31 + 0 + bb_32;
			}
		}
		
		System.out.println("\nResultado final Binário: " + bb_3);
		b_3 = (byte) Integer.parseInt(bb_3, 2);
		System.out.println("Resultado final Inteiro: " + b_3);
		
		System.out.println("Alinea d): \n");
		
		byte b_4 = (byte) 0x86;
		
		String bb_4 = Integer.toBinaryString(b_4);
		
		System.out.println("Resultado inicial Inteiro: " + b_4);
		System.out.println("Resultado inicial Binário: " + bb_4);
		
			String bb_41 = bb_4.substring(0, 1); 
			if(bb_41.equals(0)){
				System.out.println("\nO bit é zero");	
			}else{
				System.out.println("\nO bit é um");
			}
		
		System.out.println("Alinea e): \n");
		
		byte b_5 = (byte) 0x86;
			
		String bb_5 = Integer.toBinaryString(b_5);
			
		System.out.println("Resultado inicial Inteiro: " + b_5);
		System.out.println("Resultado inicial Binário: " + bb_5);
		
		int Int = b_5;
			
			for(int i = 0; i < 15; i++){
				Int = Int + b_5;
				
			}
		
		bb_5 = Integer.toBinaryString(Int);
		
		System.out.println("\nResultado final Inteiro: " + Int);
		System.out.println("Resultado final Binário: " + bb_5);	
		
//		System.out.println("Alinea f): \n");
//		
//		byte b_6 = 127;
//			
//		String bb_6 = Integer.toBinaryString(b_6);
//			
//		System.out.println("Resultado inicial Inteiro: " + b_6);
//		System.out.println("Resultado inicial Binário: " + bb_6);
//		
//		int Int_2 = b_6;
//		for(int i = 0; i < 50; i++){
//				int num = i;
//				Int_2 = (num * 4);
//				if(Int_2 > 100){
//					String possibility = Integer.toString(Int_2);
//					System.out.println(Int_2);
//					String ola = possibility.substring(0, 2);
//					System.out.println(ola);
//					if((possibility.substring(0, 1)).equals("12")){
//						Int_2 = i;
//						System.out.println(Int_2);
//						i = 50;
//					}
//				}
//				
//			}
//		
//		bb_6 = Integer.toBinaryString(Int_2);
//		
//		System.out.println("\nResultado final Inteiro: " + Int_2);
//		System.out.println("Resultado final Binário: " + bb_6);	
		
		System.out.println("Alinea g): \n");
		
		byte b_7 = 0b00110011;
			
		String bb_7 = Integer.toBinaryString(b_7);
			
		System.out.println("Resultado inicial Inteiro: " + b_7);
		System.out.println("Resultado inicial Binário: " + bb_7);
		
		int Int_3 = b_7;
			
			for(int i = 0; i < 11; i++){
				Int_3 = Int_3 + b_7;
				
			}
		
		bb_7 = Integer.toBinaryString(Int_3);
		
		System.out.println("\nResultado final Inteiro: " + Int_3);
		System.out.println("Resultado final Binário: " + bb_7);	
	}
	
	

}
