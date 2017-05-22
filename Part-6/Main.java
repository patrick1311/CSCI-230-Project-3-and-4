/*
 * Ziv Lempel like text compression system
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	public static void main(String args[]) {	
		File file = new File("src/text.txt");

		LList<String> StringList = new LList<String>();
		ArrayList<String> input = new ArrayList<String>();
		String output;
		input = readToAL(file);	//Read file input into array list
		
		output = TextCompression(StringList, input);
		System.out.println(output);
	}

	public static String TextCompression(LList<String> list, ArrayList<String> input) {
		String output = "";
		for(int i = 0; i < input.size(); i++) {
			String word = input.get(i);
			if(list.isInList(word)){
				output += Integer.toString(list.getPos(word));
			}
			else {
				list.append(word);
				output += word;
			}
			output += " ";
			list.accessMTF(word);
			list.printList();
		}
		return output;
	}
	
	public static <E> void printArrayList(ArrayList<E> input) {
		for(int i = 0; i < input.size(); i++) {
			System.out.print(input.get(i) + " ");
		}
	}
	
	public static ArrayList<String> readToAL(File file) {
		ArrayList<String> input = new ArrayList<String>();
		try {
			Scanner s = new Scanner(file);
			while(s.hasNext())
			{
				input.add(s.next());
			}
			s.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("File not found.");
		}
		return input;
	}
}