

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Registrar{
    String firstName = null;

    public static void main(String [] args){
        Connection conn = null;
        try {
            // db parameters
            String url = "jdbc:sqlite:/home/medsys/Dev/educational-projects/WallsAndMirrors/CH1/SchoolDB.db";
            // create a connection to the database
            Class.forName("org.sqlite.JDBC");
            conn = DriverManager.getConnection(url);
            
            System.out.println("Connection to SQLite has been established.");
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
        } finally {
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }
}