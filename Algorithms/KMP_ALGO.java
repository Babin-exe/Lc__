import java.util.*;

class KMPHelper {


    public static int[] buildLPS(String pat) {
        int m = pat.length();
        int[] lps = new int[m];
        lps[0] = 0;

        int len = 0; 
        int i = 1;

        while (i < m) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }


    public static List<Integer> KMP(String txt, String pat) {
        int n = txt.length();
        int m = pat.length();

        int[] lps = buildLPS(pat);
        List<Integer> occurrences = new ArrayList<>();

        int i = 0; 
        int j = 0; 

        while (i < n) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                occurrences.add(i - j); 
                j = lps[j - 1];         
            } else if (i < n && txt.charAt(i) != pat.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];    
                } else {
                    i++;               
                }
            }
        }

        return occurrences;
    }


    public static void main(String[] args) {
        String text = "ababcababc";
        String pattern = "ab";
        List<Integer> occ = KMP(text, pattern);
        System.out.println(occ); 
    }
}
