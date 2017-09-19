import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        String [] noSpace=s.split("\\W");
        scan.close();
        int c=0;
                for(String s1:noSpace)
        {
            if(!s1.trim().isEmpty())
            c+=1;
        }
        System.out.println(c);
                for(String s1:noSpace)
        {
            if(!s1.trim().isEmpty())
            System.out.println(s1);
        }

    }
}

