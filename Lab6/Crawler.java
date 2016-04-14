import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class Crawler implements Runnable
{
  public static Collection<File> chain = new ArrayList<File>();

  public void addTree(File file, Collection<File> chain) 
  {
    File[] children = file.listFiles();
    if (children != null) 
    {
      for (File child : children) 
      {
        addTree(child, chain);
      }
    }
    else
    {
      chain.add(file);
    }
  }

  public static Collection<File> getChain()
  {
    return chain;
  }
    
  public void run() 
  {
    System.out.println("[Crawler] initialized.");

    addTree(new File("/media/light/9290316490314FC9/Users/e-Light/Dropbox/Semester-6/CS213 Advanced Programming (BESE4-A)/codes/Labs"),
      chain);

    System.out.println("[Crawler] finished.");
  }
}
