import java.util.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.lang.String;

class NameScores{
    public static void main(String [] args){
        
        Scanner scanner = null;
        String fileName = "ProjEul/p022_names.txt";
        PriorityQueue pq = new PriorityQueue(5000);
        long result = 0;
        Path file = FileSystems.getDefault().getPath(".", fileName);
        try (InputStream in = Files.newInputStream(file);
            BufferedReader reader =
              new BufferedReader(new InputStreamReader(in))) {
            String line = null;
            StringTokenizer st = null;
            while ((line = reader.readLine()) != null) {
                st = new StringTokenizer(line, ",");
            }
            String[] nameList = new String[st.countTokens()];
            for(int i = 0; i < nameList.length; i++){
                if(st.hasMoreTokens()){
                    nameList[i] = new String(st.nextToken().replace('\"', ' ').trim());
                }
            }
            Arrays.sort(nameList);
            int nameVal = 0;
            for(int i = 0; i < nameList.length; i++){
                for(int j = 0; j < nameList[i].length(); j++){
                    nameVal += nameList[i].toLowerCase().charAt(j) - 'a' + 1;
                }
                result += (i+1) * nameVal;
                nameVal = 0;
            }
            System.out.println(result);
            } catch (IOException x) {
            System.err.println(x);
        }

    }
}

