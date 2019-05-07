import java.util.HashMap;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class P8_SIMTAB_LITTAB {
	public static void main(String[] args) throws IOException {

		
		File file = new File("operations.txt");
		Scanner sc = new Scanner(file);
				
		HashMap<Integer, String> symbols = new HashMap<>();
		HashMap<Integer, String> literals = new HashMap<>();
		
		//symbolTableStatingAddress
		int stsa=1000;
		
		//literalTableStatingAddress
		int ltsa=5000;
		
		String programString = "";

		while (sc.hasNextLine()) 
			programString = programString + sc.next() + " ";

		String[] splitWords = programString.split(" ");
		System.out.println(programString);
		System.out.println();
		
		for (int i = 0; i < splitWords.length; i++) {
			try{				
				int x = new Integer(splitWords[i]);
				
				if(!(literals.containsValue(splitWords[i])))
					literals.put(ltsa++, splitWords[i]);
				
			}catch (Exception e) {
				
				if(!(symbols.containsValue(splitWords[i])))
					symbols.put(stsa++, splitWords[i]);
			}			
		}		
		
		System.out.println("\nSYMBOL TABLE: \n");
		System.out.println("LOCATION      :      SYMBOL");
		symbols.forEach((k,v) -> System.out.println("  "+k+"        :       "+v));
		

		System.out.println("\n\nLITERAL TABLE: \n");
		System.out.println("LOCATION      :      LITERAL");
		literals.forEach((k,v) -> System.out.println("  "+k+"        :       "+v));
		
		sc.close();
	}
}