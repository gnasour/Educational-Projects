import java.util.*;
import java.io.*;
import java.nio.file.*;

class Day11{

    public static void main(String [] args){
        Scanner scanner = null;
        final String TMP_DIR = "F:/tmp/";
        byte[][] seatArr  = new byte[4][];
        try{
            //scanner = new Scanner(new File("Day11.txt"));
            RandomAccessFile raf = new RandomAccessFile("Day11.txt", "rw");
            
            Path tmpFld = FileSystems.getDefault().getPath("F:/tmp/");
            
            if(!Files.exists(tmpFld)){
                Files.createDirectory(tmpFld);
            }
            
            Path charSim = Files.createTempFile(tmpFld, null,".txt");
            RandomAccessFile tmpF = new RandomAccessFile(charSim.toFile(), "rw");
            
            //Determine if there are any changes to the seats
            boolean changed = false;

            do{

                raf.write
            }while(changed);
            
            tmpF.close();
            raf.close();
            Files.deleteIfExists(charSim);
            Files.deleteIfExists(tmpFld);
        }catch(FileNotFoundException fnf){
            fnf.printStackTrace();
        }catch(IOException ioe){
            ioe.printStackTrace();
        }

        //while(scanner.hasNext())

        //scanner.close();
    }
}