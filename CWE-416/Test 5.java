import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(42);
        list.clear();
        int value = list.get(0);  // Use-After-Free vulnerability
        System.out.println(value);
    }
}
// This code demonstrates a Use-After-Free vulnerability in Java. 
// The code creates an ArrayList and adds an element to it. 
// The code then calls the clear method, which frees the memory used by the ArrayList. 
// However, the code then continues to access the memory by calling the get method to retrieve the first element of the ArrayList. 
// This results in a Use-After-Free vulnerability, as the program is accessing memory that has already been freed.