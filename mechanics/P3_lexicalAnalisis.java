import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class P3_lexicalAnalisis {
	public static void main(String[] args) throws IOException {

		File file = new File("lexicalAnalisis.txt");
		Scanner sc = new Scanner(file);
		
		String[] keyWords={"void","main","int"};
		ArrayList<String> keyWordsArray = new ArrayList<>();
		
		for (int i = 0; i < keyWords.length; i++) {
			keyWordsArray.add(keyWords[i]);
		}

		String programString = "";

		while (sc.hasNextLine()) 
			programString = programString + sc.next() + " ";

		String[] splitWords = programString.split(" ");
		System.out.println(programString);
		System.out.println();
		
		for (int i = 0; i < splitWords.length; i++) {
			
			if(keyWordsArray.contains(splitWords[i])){
				System.out.println("Keyword              : "+splitWords[i]);
			}
			else{
				char firstChar = splitWords[i].charAt(0);
				if(firstChar=='{' || firstChar=='}' || firstChar=='(' || firstChar==')' || firstChar=='[' || firstChar==']'){
					System.out.println("Brackets             : "+splitWords[i]);
				}
				else if(firstChar=='!' || firstChar=='%' || firstChar=='^' || firstChar=='&' || firstChar=='*' 
						|| firstChar=='-' || firstChar=='+' || firstChar=='='|| firstChar=='|'){
					
					System.out.println("Operators            : "+splitWords[i]);
				}
				else if(firstChar=='!'){
					System.out.println("End of Line Char     : "+splitWords[i]);
				}
				else{
					
					try{
						
						int x = new Integer(splitWords[i]);
						System.out.println("Constants            : "+splitWords[i]);
						
					}catch (Exception e) {
						
						System.out.println("Identifire           : "+splitWords[i]);
					}
					
				}
			}
			
		}		
		sc.close();
	}
}