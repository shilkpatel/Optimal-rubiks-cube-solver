package solverv2;

import java.sql.*;

  

public class Database {

public static void setUpConnection()

{

Connection c = null;

try

{

Class.forName("org.sqlite.JDBC");

c = DriverManager.getConnection("jdbc:sqlite:heuristic.db");

} catch (Exception e) {

System.exit(0);

}

}

  

}